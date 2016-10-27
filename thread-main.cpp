// -----------------------------------------------------------
// NAME : Zachary Hill                   User ID: zahill
// DUE DATE : 10/28/2016
// PROGRAM ASSIGNMENT #3
// FILE NAME : thread-main.cpp
// PROGRAM PURPOSE :
//    Contains the main program
// -----------------------------------------------------------

#include <iostream>
#include <math.h>
#include "thread.h"

using namespace std;

int main(void)
{
    int numVals;
    int i;
    int h;
    int k;
    // Get the first value
    cin >> numVals;

    k = (int) log2(numVals);

    int bArr[k + 1][numVals];
    for (i = 0; i < numVals; i++)
    {
        cin >> bArr[0][i];
    }

    for (i = 0; i < numVals; i++)
    {
        cout << bArr[0][i] << ' ';
    }
    cout << endl;

    cout << "K: " << k << endl;

    MyThread *newThread[numVals];
    for (h = 1; h < k + 1; h++)
    {
        for (i = 0; i < numVals; i++)
        {
            // cast to int array and use 2D array as a 1D array
            newThread[i] = new MyThread(h, i, numVals, (int *) bArr);
            newThread[i]->Begin();
        }
        for (i = 0; i < numVals; i++)
        {
            newThread[i]->Join();
        }
    }

    cout << "Printing the final result" << endl;
    for (i = 0; i < numVals; i++)
    {
        cout << bArr[k][i] << ' ';
    }

    cout << endl;

    /*MyThread *newThread;

    newThread = new MyThread(20);
    newThread->Print();
    */

    return 0;
}
