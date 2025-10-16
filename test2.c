/*
 * test2.c --- A test driver for the integrate module that checks for
 * correct failure on invalid inputs.
 *
 * Author: Shahzaib Awan
 * Date: 29-09-2025
 *
 * Description: This program tests the error-handling of the integrate
 * module by intentionally passing an invalid interval where b < a.
 * The test succeeds if the module functions return a non-zero
 * error code, proving they correctly identified the bad input.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "integrate.h"

/**
 * Defines the mathematical function to be integrated.
 * @param x The input value.
 * @return The value of the function at x.
 */
double f(double x) {
    return (2 * x * x) + (9 * x) + 4;
}

int main(void) {
    printf("Running failure tests for the integrate module...\n");

    // integraten with b < a
    double a = 12.0;
    double b = 3.0;
    uint32_t n = 100;
    double result;

    // this function call should return non-zero
    if (integraten(f, a, b, n, &result) != 0) {
        printf("Test 1 PASSED: integraten correctly failed with b < a.\n");
    } else {
        printf("Test 1 FAILED: integraten did not return an error with b < a.\n");
        return EXIT_FAILURE;
    }

    // integratep with b < a
    double precision = 0.001;
    n = 0;

    // This function call should also return non-zero
    if (integratep(f, a, b, precision, &result, &n) != 0) {
        printf("Test 2 PASSED: integratep correctly failed with b < a.\n");
    } else {
        printf("Test 2 FAILED: integratep did not return an error with b < a.\n");
        return EXIT_FAILURE;
    }

    // If both tests passed
    printf("All failure tests passed.\n");
    return EXIT_SUCCESS;
}
