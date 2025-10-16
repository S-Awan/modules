/*
 * test1.c --- A test driver for the integrate module.
 *
 * Author: Shahzaib Awan
 * Date: 29-09-2025
 *
 * Description: This program serves as a client for the integrate module.
 * It parses command-line arguments and uses the integraten and
 * integratep functions to perform the integration, then prints the result.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "integrate.h"

/**
 * Defines the mathematical function to be integrated.
 * @param x The input value.
 * @return The value of the function at x.
 */
double f(double x) {
    // Using the equation given in step 6
    return (2 * x * x) + (9 * x) + 4;
}

int main(int argc, char *argv[]) {
    // Checking for arguments
    if (argc != 5) {
        fprintf(stderr, "usage: test1 a b (-n <steps> | -p <precision> )\n");
        return EXIT_FAILURE;
    }

    //declaring variables
    double a = strtod(argv[1], NULL);
    double b = strtod(argv[2], NULL);
    uint32_t n;
    double result;

    // Selecting which mode
    // -n (steps) mode
    if (strcmp(argv[3], "-n") == 0) {
        n = strtoul(argv[4], NULL, 10);
        
        // Calling the function from our module.
        if (integraten(f, a, b, n, &result) != 0) {
            // The module function returned an error.
            fprintf(stderr, "Error in integraten.\n");
            return EXIT_FAILURE;
        }

    // -p (precision) mode
    } else if (strcmp(argv[3], "-p") == 0) {
        double precision = strtod(argv[4], NULL);

        // Calling the function from our module.
        // This time we need to pass in the address of n as well
        if (integratep(f, a, b, precision, &result, &n) != 0) {
            fprintf(stderr, "Error in integratep.\n");
            return EXIT_FAILURE;
        }

    } else {
        // Invalid flag
        fprintf(stderr, "usage: test1 a b (-n <steps> | -p <precision> )\n");
        return EXIT_FAILURE;
    }

    // printing result to stdout
    printf("interval: [%lf-%lf], n: %u, result=%lf\n", a, b, n, result);

    return EXIT_SUCCESS;
}
