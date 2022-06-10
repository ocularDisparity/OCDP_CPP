#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

Pixel** createImage(int width, int height) {
  cout << "Start createImage... " << endl;
  
  // Create a one dimensional array on the heap of pointers to Pixels 
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];
  
  bool fail = false;
  
  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];
    
    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }
  
  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // dlete array of pointers
    return nullptr;
  }
  
  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = { 0, 0, 0 };
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

int* createSeam(int length) {
  int* newArr = new int[length];
  for (int i = 0; i < length; i++) {
	newArr[i] = 0;
  }
  return newArr;
}

void deleteSeam(int* seam) {
  delete[] seam;
}

bool loadImage(string filename, Pixel** image, int width, int height) {
  string fileFormat;
  int w, h;
  int maxColor;
  int input;
  
  // open ifstream and error catch
  ifstream ifs(filename);
  if(!ifs.is_open()) {
	cout << "Error: failed to open input file - " << filename << endl;
	return false;
  }
  
  // input file format
  ifs >> fileFormat;
  if (tolower(fileFormat.at(0)) != 'p' || fileFormat.at(1) != '3') {
	cout << "Error: type is " << fileFormat << " instead of P3" << endl;
	ifs.close();
	return false;
  }
  
  // input width and height
  ifs >> w >> h;
  if(!ifs.good()) {
    cout << "Error: read non-integer value" << endl;
	ifs.close();
    return false;
  }
  
  if(w != width) {
	cout << "Error: input width (" << width << ") does not match value in file (" << w << ")" << endl;
	ifs.close();
	return false;
  }
  if (h != height) {
	cout << "Error: input height (" << height << ") does not match value in file (" << h << ")" << endl;
	ifs.close();
	return false;
  }
  
  // input maximum color
  ifs >> maxColor;
  if (maxColor != 255) {
	cout << "Error: invalid color value " << maxColor << endl;
	ifs.close();
	return false;
  }
  
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      // read in rgb values and check for validity
	  ifs >> image[j][i].r >> image[j][i].g >> image[j][i].b;
	  
	  if(!ifs.good() && !ifs.eof()) {
        cout << "Error: read non-integer value" << endl;
		ifs.close();
        return false;
      }
	  else if(ifs.fail()) {
        cout << "Error: not enough color values" << endl;
		ifs.close();
        return false;
      }
	  else if((image[j][i].r) < 0 || image[j][i].r > 255) {
        cout << "Error: invalid color value " << image[j][i].r << endl;
		ifs.close();
        return false;
      }
      else if((image[j][i].g) < 0 || image[j][i].g > 255) {
        cout << "Error: invalid color value " << image[j][i].g << endl;
		ifs.close();
        return false;
      }
      else if((image[j][i].b) < 0 || image[j][i].b > 255) {
        cout << "Error: invalid color value " << image[j][i].b << endl;
		ifs.close();
        return false;
      }
	}
  }
  
  // check for leftover data
  ifs >> input;
  if(ifs.good() && !ifs.eof()) {
    cout << "Error: too many color values" << endl;
	ifs.close();
    return false;
  }
  
  ifs.close();
  return true;
}

bool outputImage(string filename, Pixel** image, int width, int height) {
  // same thing as input, except let's output
  ofstream ofs(filename);
  
  // error handling
  if (!ofs.is_open()) {	
	cout << "Error: failed to open output file - " << filename << endl;
    return false;
  }
  
  // output to file
  ofs << "P3" << endl;
  ofs << width << " " << height << endl;
  ofs << 255 << endl;
  
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      ofs << image[j][i].r << " ";
      ofs << image[j][i].g << " ";
      ofs << image[j][i].b << endl;
    }
  }
  
  ofs.close();
  return true;
}

int energy(Pixel** image, int x, int y, int width, int height) {
  int xCalc;
  int yCalc;
  int totalNRG;
  
  // use the magic formula
  if(x == 0) {
    xCalc = pow(abs(image[x + 1][y].r - image[width - 1][y].r), 2) + pow(abs(image[x + 1][y].g - image[width - 1][y].g), 2) + pow(abs(image[x + 1][y].b - image[width - 1][y].b), 2);
  } else if(x == width - 1) {
    xCalc = pow(abs(image[x - 1][y].r - image[0][y].r), 2) + pow(abs(image[x - 1][y].g - image[0][y].g), 2) + pow(abs(image[x - 1][y].b - image[0][y].b), 2);
  } else {
    xCalc = pow(abs(image[x + 1][y].r - image[x - 1][y].r), 2) + pow(abs(image[x + 1][y].g - image[x - 1][y].g), 2) + pow(abs(image[x + 1][y].b - image[x - 1][y].b), 2);
  }
  
  if(y == 0) {
    yCalc = pow(abs(image[x][y + 1].r - image[x][height - 1].r), 2) + pow(abs(image[x][y + 1].g - image[x][height - 1].g), 2) + pow(abs(image[x][y + 1].b - image[x][height - 1].b), 2);
  } else if(y == height - 1) {
    yCalc = pow(abs(image[x][y - 1].r - image[x][0].r), 2) + pow(abs(image[x][y - 1].g - image[x][0].g), 2) + pow(abs(image[x][y - 1].b - image[x][0].b), 2);
  } else {
    yCalc = pow(abs(image[x][y + 1].r - image[x][y - 1].r), 2) + pow(abs(image[x][y + 1].g - image[x][y - 1].g), 2) + pow(abs(image[x][y + 1].b - image[x][y - 1].b), 2);
  }
  
  totalNRG = xCalc + yCalc;
  return totalNRG;
}


int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
  int verticalNRG;
  
  int currentX = start_col;
  int currentY = 0;
  
  int forward;
  int right;
  int left;
  
  seam[0] = start_col;
  verticalNRG = energy(image, currentX, currentY, width, height);
  
  for (currentY = 0; currentY < (height - 1); ++currentY) {
    // forward
	forward = energy(image, currentX, currentY + 1, width, height);
	
	// right
	if (currentX - 1 >= 0) {
	  right = energy(image, currentX - 1, currentY + 1, width, height);
	} else {
      right = 2147483647;
	}
    
    // left
	if (currentX + 1 < width) {
      left = energy(image, currentX + 1, currentY + 1, width, height);
	} else {
      left = 2147483647;
	}
	
	
	if ((forward < right && forward < left) || (forward < right && forward == left) || (forward == right && forward < left) || (forward == right && forward == left)) {
	  verticalNRG += forward;
	  
	  seam[currentY + 1] = currentX;
    }
    else if ((left < forward && left < right) || (left < forward && left == right)) {
      verticalNRG += left;
	  currentX += 1;
	  
	  seam[currentY + 1] = currentX;
    }
	else if (right < left && right < forward) {
      verticalNRG += right;
	  currentX -= 1;
	  
	  seam[currentY + 1] = currentX;
    }
  }
  
  return verticalNRG;
}

int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
  int horizontalNRG;
  
  int currentX = 0;
  int currentY = start_row;
  
  int forward;
  int right;
  int left;
  
  seam[0] = start_row;
  horizontalNRG = energy(image, currentX, currentY, width, height);
  
  for (currentX = 0; currentX < (width - 1); ++currentX) {
    // forward
	forward = energy(image, currentX + 1, currentY, width, height);
	
	// right
	if (currentY + 1 < height) {
	  right = energy(image, currentX + 1, currentY + 1, width, height);
	} else {
      right = 2147483647;
	}
    
    // left
	if (currentY - 1 >= 0) {
      left = energy(image, currentX + 1, currentY - 1, width, height);
	} else {
      left = 2147483647;
	}
	
	
	if ((forward < right && forward < left) || (forward < right && forward == left) || (forward == right && forward < left) || (forward == right && forward == left)) {
	  horizontalNRG += forward;
	  
	  seam[currentX + 1] = currentY;
    }
    else if ((left < forward && left < right) || (left < forward && left == right)) {
      horizontalNRG += left;
	  currentY -= 1;
	  
	  seam[currentX + 1] = currentY;
    }
	else if (right < left && right < forward) {
      horizontalNRG += right;
	  currentY += 1;
	  
	  seam[currentX + 1] = currentY;
    }
  }
  
  return horizontalNRG;
}

int* findMinVerticalSeam(Pixel** image, int width, int height) {
  int lowestNRG;
  int calculatedNRG;
  
  int* minSeam = createSeam(height);
  int* seam = createSeam(height);
  
  lowestNRG = loadVerticalSeam(image, 0, width, height, minSeam);
  
  for (int i = 1; i < width; ++i) {
    calculatedNRG = loadVerticalSeam(image, i, width, height, seam);
  
    if (calculatedNRG < lowestNRG) {
	  for (int j = 0; j < height; ++j) {
	    minSeam[j] = seam[j];
	  }
	  lowestNRG = calculatedNRG;
	}
  }
  deleteSeam(seam);
  
  return minSeam;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) {
  int lowestNRG;
  int calculatedNRG;
  
  int* minSeam = createSeam(width);
  int* seam = createSeam(width);
  
  lowestNRG = loadHorizontalSeam(image, 0, width, height, minSeam);
  
  for (int i = 1; i < height; ++i) {
    calculatedNRG = loadHorizontalSeam(image, i, width, height, seam);
  
    if (calculatedNRG < lowestNRG) {
	  for (int j = 0; j < width; ++j) {
	    minSeam[j] = seam[j];
	  }
	  lowestNRG = calculatedNRG;
	}
  }
  deleteSeam(seam);
  
  return minSeam;
}

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
  for (int i = 0; i < height; i++) {
    for (int j = verticalSeam[i]; j < (width - 1); ++j) {
	  image[j][i] = image[j + 1][i];
	}
  }
}

void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
  for (int i = 0; i < width; i++) {
    for (int j = horizontalSeam[i]; j < (height - 1); ++j) {
	  image[i][j] = image[i][j + 1];
	}
  }
}