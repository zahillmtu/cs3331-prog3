// -----------------------------------------------------------
// NAME : Zachary Hill                   User ID: zahill
// DUE DATE : 10/28/2016
// PROGRAM ASSIGNMENT #3
// FILE NAME : thread-main.cpp
// PROGRAM PURPOSE :
//    Contains the main program, used to load in data and
//    compute the prefix sum computation concurrently. Creates
//    threads to compute each piece of the problem
//    concurrently.
// -----------------------------------------------------------

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "thread.h"

using namespace std;

// -----------------------------------------------------------
// FUNCTION printWrap :
//    A wrapper method for printing using write()
// PARAMETER USAGE :
//    buf - A character array of size 100 containing
//          the print statement
// FUNCTION CALLED :
//    write()
// -----------------------------------------------------------
void printWrap(char buf[100]) {
    write(1, buf, strlen(buf));
}

// -----------------------------------------------------------
// FUNCTION main :
//    A warm up multithreaded program solving The Prefix Sum
//    Problem. main() reads in the initial data and places it
//    into an array, then creates new threads to calculate
//    each piece of the problem concurrently
// PARAMETER USAGE :
//    buf - A character array of size 100 containing
//          the print statement
// FUNCTION CALLED :
//    write()
// -----------------------------------------------------------
int main(void)
{
    int numVals;
    int i;
    int h;
    int k;
    char buf[100];

    sprintf(buf, "Concurrent Prefix Sum Computation\n\n");
    printWrap(buf);

    // Get the first value
    cin >> numVals;
    sprintf(buf, "Number of input data = %d\n", numVals);
    printWrap(buf);

    k = (int) log2(numVals);

    // Load the array into the first row of bArr[][]
    sprintf(buf, "Input array:\n");
    printWrap(buf);
    int bArr[k + 1][numVals];
    for (i = 0; i < numVals; i++)
    {
        cin >> bArr[0][i];
        sprintf(buf, "%5d", bArr[0][i]);
        printWrap(buf);
    }
    sprintf(buf, "\n");
    printWrap(buf);

    // Array to hold the threads
    MyThread *newThread[numVals];
    for (h = 1; h < k + 1; h++)
    {
        for (i = 0; i < numVals; i++)
        {
            // cast to int array and use 2D array as a 1D array
            newThread[i] = new MyThread(h, i, numVals, (int *) bArr);
            sprintf(buf, "\tThread %d created\n", i);
            printWrap(buf);
            newThread[i]->Begin();
        }
        for (i = 0; i < numVals; i++)
        {
            newThread[i]->Join();
        }
        if (h != k)
        {
            // Print out the results of this run
            sprintf(buf, "Result after run %d:\n", h);
            printWrap(buf);
            for (i = 0; i < numVals; i++)
            {
                sprintf(buf, "%5d", bArr[h][i]);
                printWrap(buf);
            }
            sprintf(buf, "\n");
            printWrap(buf);
        }
    }

    // Print out the results of this run
    sprintf(buf, "Final result after run %d:\n", k);
    printWrap(buf);
    for (i = 0; i < numVals; i++)
    {
        sprintf(buf, "%5d", bArr[k][i]);
        printWrap(buf);
    }
    sprintf(buf, "\n");
    printWrap(buf);

    return 0;
}
