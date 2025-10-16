#!/bin/bash
#
# integrate.sh - A test script for the integrate module.
#
# Author: Shahzaib Awan
# Date: 29-9-2025
#
# Description: This script calls the provided runtest.sh to execute
#              test cases against the test1 and test2 programs.


# Success Test Cases (test1) 
echo "Running SUCCESS test cases:"
./runtest.sh "test1 2.1 3.7 -n 5"
./runtest.sh "test1 2.1 3.7 -p 0.0001"
echo


# Failure Test case  (test2)
echo "Running FAILURE test program:"
./runtest.sh "test2"
echo
