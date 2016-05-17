/*
	Name		:
	Student ID	: 
	Lab6		:	Separate Compilation
*/
#include <iostream>
#include "DataEntry.h"
#include "Engine.h"
#include "Histogram.h"
#include "Search.h"
#include "Sort.h"
using namespace std;

int main()
{
	bool quit;
	int size;
	int* arr = NULL;
	do {	   
       quit = executeMenu(selectMenu(), arr, size);
    } while (!quit);
	if(arr != NULL)
		delete [] arr;
    system("pause");
    return 0;
}
