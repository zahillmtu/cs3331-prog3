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

    int bArr[numVals][numVals];
    for (i = 0; i < numVals; i++)
    {
        cin >> bArr[0][i];
    }

    for (i = 0; i < numVals; i++)
    {
        cout << bArr[0][i] << ' ';
    }
    cout << endl;

    k = (int) log2(numVals);
    cout << "K: " << k << endl;

    for (h = 1; h < k + 1; h++)
    {
        for (i = 0; i < numVals; i++)
        {
            if (i - pow(2, h - 1) < 0)
            {
                bArr[h][i] = bArr[h - 1][i];
            }
            else {
                bArr[h][i] = bArr[h - 1][i] + bArr[h - 1][( i - ((int) pow(2, h - 1)))];
            }
        }
    }

    cout << "Printing the final result" << endl;
    for (i = 0; i < numVals; i++)
    {
        cout << bArr[k][i] << ' ';
    }

    cout << endl;

    MyThread *newThread;

    newThread = new MyThread(20);
    newThread->Print();

    return 0;
}
