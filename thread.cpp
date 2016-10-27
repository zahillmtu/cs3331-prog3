// -----------------------------------------------------------
// NAME : Zachary Hill                   User ID: zahill
// DUE DATE : 10/28/2016
// PROGRAM ASSIGNMENT #3
// FILE NAME : thread.cpp
// PROGRAM PURPOSE :
//    Contains all the class implementations
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
void MyThread::printWrap(char buf[100]) {
    write(1, buf, strlen(buf));
}

// -----------------------------------------------------------
// FUNCTION MyThread::MyThread :
//    Constructor for the Thread Class MyThread.
// PARAMETER USAGE :
//    hVal    - The value of h for the calculation
//    iVal    - The calue of i for the calculation
//    num     - The number of elements in each row of the array
//    bArrPtr - Pointer to a 2D array being accessed as a 1D array
// FUNCTION CALLED :
//    N/A
// -----------------------------------------------------------
MyThread::MyThread(int hVal, int iVal, int num,  int * bArrPtr)
          :h(hVal), i(iVal), numVals(num), bArr(bArrPtr)
{
    // Make a threadname
}


// -----------------------------------------------------------
// FUNCTION MyThread::ThreadFunc :
//    Function called by Begin(), does the computation for
//    the Prefix Sum Problem
// PARAMETER USAGE :
//    N/A
// FUNCTION CALLED :
//    N/A
// -----------------------------------------------------------
void MyThread::ThreadFunc()
{
    Thread::ThreadFunc();
    char buf[100];

    if (i - pow(2, h - 1) < 0)
    {
        // Copy B[h-1][i] to B[h][i]
        *((bArr + (h * numVals)) + i) = *((bArr + ((h - 1) * numVals)) + i);
        sprintf(buf, "\tThread %d copies x[%d]\n", i, i);
        printWrap(buf);
    }
    else
    {
        // Calculate B[h][i] = B[h-1][i] + B[h-1][j-2^i]
        *((bArr + (h * numVals)) + i) = *((bArr + ((h - 1) * numVals)) + i) + *((bArr + ((h-1) * numVals)) + (i - ((int)pow(2, h - 1))));
        sprintf(buf, "\tThread %d computes x[%d] + x[%d-2^(%d-1)]\n", i, i, i, h);
        printWrap(buf);
    }
    sprintf(buf, "\tThread %d exits\n", i);
    printWrap(buf);
    Exit();
}
