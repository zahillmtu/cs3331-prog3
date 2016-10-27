// -----------------------------------------------------------
// NAME : Zachary Hill                   User ID: zahill
// DUE DATE : 10/28/2016
// PROGRAM ASSIGNMENT #3
// FILE NAME : thread.h
// PROGRAM PURPOSE :
//    Contains all the class definitions
// -----------------------------------------------------------
#include "ThreadClass.h"

class MyThread : public Thread
{
    public:
        MyThread(int hVal, int iVal, int num, int * bArrPtr);
        void Print(void);
    private:
        int h;
        int i;
        int * bArr;
        int numVals;
        void printWrap(char*);
        void ThreadFunc();
};
