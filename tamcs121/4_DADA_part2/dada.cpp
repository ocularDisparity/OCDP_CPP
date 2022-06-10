/*
DADA function definitions
*/

#include "dada.h"
#include <cmath>

int amax(const double x[], const unsigned int len) {
	int position = -1;
	
    if (len != 0) {
		position = 0;
		double comparator = fabs(x[0]);
		
		for (unsigned int i = 1; i < len; i++) {
			if (fabs(x[i]) > comparator) {
				position = i;
				comparator = fabs(x[i]);
			}
		}
	}
	
	return position;
}

double asum(const double x[], const unsigned int len) {
	double total_sum = 0;
	
	for (unsigned int i = 0; i < len; i++) {
			total_sum += fabs(x[i]);
	}
	
	return total_sum;
}

void axpy(const double a, const double x[], double y[], const unsigned int len) {
    for (unsigned int i = 0; i < len; i++) {
		y[i] += x[i] * a;
	}
}

void copy(const double src[], double dest[], const unsigned int len) {
    for (unsigned int i = 0; i < len; i++) {
		dest[i] = src[i];
	}
}

double dot(const double x[], const double y[], const unsigned int len) {
	double product = 0;
	
	for (unsigned int i = 0; i < len; i++) {
			product += (x[i] * y[i]); 
	}
	
    return product;
}

double norm2(const double x[], const unsigned int len) {
    double norm = 0;
	
	for (unsigned int i = 0; i < len; i++) {
		norm += pow(fabs(x[i]),2);
	}
	
	norm = sqrt(norm);
    return norm;
}

void scale(const double a, double x[], const unsigned int len) {
    for (unsigned int i = 0; i < len; i++) {
		x[i] = x[i] * a;
	}
}

void swap(double x[], double y[], const unsigned int len) {
    double temp[len-1];
	
	for (unsigned int i = 0; i < len; i++) {
		temp[i] = x[i];
		x[i] = y[i];
		y[i] = temp[i];
	}
}
