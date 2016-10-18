// -----------------------------------------------------------
// NAME : Zachary Hill                   User ID: zahill
// DUE DATE : 10/28/2016
// PROGRAM ASSIGNMENT #3
// FILE NAME : thread.cpp
// PROGRAM PURPOSE :
//    Contains all the class implementations
// -----------------------------------------------------------

#include <iostream>
#include "thread.h"

using namespace std;

int count;

MyThread::MyThread(int countAmount)
{
    count = countAmount;
}

void MyThread::Print(void)
{
    int i;
    cout << "Printing from thread: " << endl;
    for (i = count; i < count + 10; i++)
    {
        cout << i << ' ';
    }
    cout << endl;
}
