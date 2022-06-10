#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "functions.h"

using std::ifstream;

void readPrefs(std::string fileName, int ngames, int prefs[]){
	// open file
	ifstream ifs (fileName);
	
	// error handling
	if (!ifs.is_open()) {
		throw std::runtime_error("Invalid preferences file.");
	}
	
	// populate prefs with 0
	for (int i = 0; i < ngames; i++) {
		prefs[i] = 0;
	}
	
	for (int i = 0; i < ngames; i++) {
		int gameID = -1;
		int gameRating = -1;
		bool isValid = true;
		
		try { // attempt to get data from file
			ifs >> gameID;
			ifs >> gameRating;
		} catch ( int param ) {
			isValid = false;
		}
		
		// check if given game ID is valid (0 - ngames)
		if (gameID < 0 || gameID > ngames - 1) {
			isValid = false;
		}
		
		// check if given game rating if valid (1 - 5)
		if (gameRating < 0 || gameRating > 5) {
			isValid = false;
		}
		
		// check if the valid flag has been set to invalid
		if (isValid == true) {
			prefs[gameID] = gameRating;
		}
	}
	
	ifs.close();
}

void readPlan(std::string fileName, int plan[]){
	// open file
	ifstream ifs (fileName);
	
	// error handling
	if (!ifs.is_open()) {
		throw std::runtime_error("Invalid plan file.");
	}
	
	for (int i = 0; i < 366; i++) {
		int gameDate = -1;
		int gameID = -1;
		bool isValid = true;
		
		try { // attempt to get data from file
			ifs >> gameDate;
			ifs >> gameID;
		} catch ( int param ) {
			isValid = false;
		}
		
		// check if date is within parameters (1 - 365)
		if (gameDate <= 0 || gameDate > 365) {
			isValid = false;
		}
		
		// check if game ID is within paramters (any number above zero)
		if (gameID < 0) {
			isValid = false;
		}
		
		// check if the valid flag has been set to invalid
		if (isValid == true) {
			plan[gameDate] = gameID;
		}
	}
	
	ifs.close();
}

int computeFunLevel (int start, int duration, int prefs[], int plan[]){
	// if input exceeds number of days in a year
	if (start + duration > 366) {
		throw std::invalid_argument("Invalid input.");
	}
	
	int totalSUM = 0;
	
	for (int i = start; i < (start + duration); i++) {
		totalSUM += prefs[plan[i]];
	}
	
	return totalSUM;
}

int findBestVacation (int duration, int prefs[], int plan[]){
	int newHighScore = 0;
	int bestDay = 0;
	int sum = 0;
	
	for(int i = 1; i < 366; i++) {
		try {
			sum = computeFunLevel(i, duration, prefs, plan);
		} catch (std::invalid_argument& e) {
			sum = -1;
		}
		
		if(sum > newHighScore) {
			newHighScore = sum;
			bestDay = i;
		}
	}
	
	return bestDay;
}