// -----------------------------------------------------------
// NAME : Zachary Hill                   User ID: zahill
// DUE DATE : 10/28/2016
// PROGRAM ASSIGNMENT #3
// FILE NAME : thread-main.cpp
// PROGRAM PURPOSE :
//    Contains the main program
// -----------------------------------------------------------

#include <iostream>
#include "thread.h"

using namespace std;

int main(void)
{
    int numVals;
    int i;
    // Get the first value
    cin >> numVals;

    int xArr[numVals];
    for (i = 0; i < numVals; i++)
    {
        cin >> xArr[i];
    }

    for (i = 0; i < numVals; i++)
    {
        cout << xArr[i] << ' ';
    }
    cout << endl;

    MyThread *newThread;

    newThread = new MyThread(20);
    newThread->Print();

    return 0;
}
