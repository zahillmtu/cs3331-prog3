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
#include "thread.h"

using namespace std;

MyThread::MyThread(int hVal, int iVal, int num,  int * bArrPtr)
          :h(hVal), i(iVal), numVals(num), bArr(bArrPtr)
{
    // Make a threadname
}

void MyThread::ThreadFunc()
{
    Thread::ThreadFunc();

    if (i - pow(2, h - 1) < 0)
    {
        *((bArr + (h * numVals)) + i) = *((bArr + ((h - 1) * numVals)) + i);
    }
    else
    {
        *((bArr + (h * numVals)) + i) = *((bArr + ((h - 1) * numVals)) + i) + *((bArr + ((h-1) * numVals)) + (i - ((int)pow(2, h - 1))));
    }
    Exit();
}

void MyThread::ThreadPrint(int n)
{
    // print stuff here
}
