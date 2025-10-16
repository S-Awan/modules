/*
 * integrate.c --- Implementation of the integrate module.
 *
 * Author: Shahzaib Awan
 * Date: 29-09-2025
 *
 * Description: This file provides the functions for performing numerical
 * integration as declared in integrate.h.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "integrate.h"

// This is a static helper function, meaning it is private to this file.
// It performs the actual trapezoidal calculation.
static double calculate_area(double (*f)(double x), double a, double b, uint32_t n) {
	// dividing into small steps
	double interval = (b - a) / (double)n;
	double result = 0.0;
  
	for (uint32_t i = 0; i < n; i++) {
		// using the formula for the area of a trapezium to find the area
		result += 0.5 * (f(a + (i * interval)) + f(a + ((i + 1) * interval))) * interval;
	}
	return result;
}


int32_t integraten(double (*f)(double x), double a, double b, uint32_t n, double *rp) {
	// Checking for input values to see if they are valid
	if (b <= a || n == 0) {
		return -1;
	}
	
	// Calculating the integral using the helper function
	*rp = calculate_area(f, a, b, n);
	
	return 0;
}


int32_t integratep(double (*f)(double x), double a, double b, double p, double *rp, uint32_t *sp) {
	// Checking for input values to see if they are valid
	if (b <= a || p <= 0 || p >= 1) {
		return -1;
	}
	
	uint32_t n = 1;
		double lastResult;
	double currentResult;
	
	// Perform initial calculations for n=1 and n=2 before starting the loop.
	lastResult = calculate_area(f, a, b, n);
	n = n * 2;
	currentResult = calculate_area(f, a, b, n);
	
	// Loop until the difference between successive results is within the precision.
	while (fabs(currentResult - lastResult) >= p) {
		lastResult = currentResult;
		n = n * 2;
		currentResult = calculate_area(f, a, b, n);
	}
	// Use the pointers to return results
	*rp = currentResult;
	*sp = n;
  
	return 0;
}
