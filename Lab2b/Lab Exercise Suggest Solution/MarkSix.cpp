// ---------------------------------------------------
//
//   AST21105 Object Oriented Programming and Design
//   Lab02 Part B - Suggested Solution
//
// ---------------------------------------------------

// #include is a pre-processor command denoted by #,
// which tells the compiler to take iostream and ctime,
// compile them into the program which is anothor file
// that has the implementation of cin, cout and time function

#include <iostream>
#include <ctime>
#include <limits>
using namespace std;

int main()
{
    int generateNo[7];
	int guessNo[7];

	// Code for random numbers generation
    srand((unsigned int)time(NULL));
    for(int i=0; i<7; i++)
    {
      do{
         generateNo[i] = rand() % 49 + 1;
	 bool isDistinct = true;
         for(int j=0; j<i; j++)
         {
           if(generateNo[i] == generateNo[j])
           {
              isDistinct = false;
              break;
           }
         }
      }while(!isDistinct);
    }
	
	// Display randomly generated numbers
	cout << "[ Mark Six Simulation ]" << endl;
	cout << "Six regular numbers drawn are ";
	for(int i=0; i<6; i++)
		cout << generateNo[i] << " ";
	cout << endl;
	cout << "Extra number drawn is " << generateNo[6] << endl;
	cout << "---------------------------------------------------" << endl;

	// Code for user input
	bool valid;
	do{
		valid = true;
		cout << "Enter guess numbers: ";
		for(int i=0; i<6; i++)
			cin >> guessNo[i];
		for(int i=0; i<6; i++)
		{
			bool leave = false;
			if(guessNo[i] < 1 || guessNo[i] > 49)
			{
				valid = false;
				cout << "Out of range number found, please re-enter" << endl;
				break;
			}
			for(int j=0; j<i; j++)
			{
				if(guessNo[i] == guessNo[j])
				{
					valid = false;
					cout << "Repeated number found, please re-enter" << endl;
					leave = true;
					break;
				}
			}
			if(leave)
				break;
		}
	}while(!valid);

	// Check prize
	double correctNoCount = 0;
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<6; j++)
		{
			if(guessNo[i] == generateNo[j])
			{
				correctNoCount++;
				break;
			}
		}
	}
	for(int i=0; i<6; i++)
	{
		if(guessNo[i] == generateNo[6])
		{
			correctNoCount += 0.5;
			break;
		}
	}

	// Display result
	cout << "---------------------------------------------------" << endl;
	cout << "Number of input values matched: " << correctNoCount << endl;

	double epsilon = numeric_limits<double>::epsilon();
	// Display prize
	if(fabs(correctNoCount - 6) < epsilon)
		cout << "1st Prize" << endl;
	else if(fabs(correctNoCount - 5.5) < epsilon)
		cout << "2nd Prize" << endl;
	else if(fabs(correctNoCount - 5) < epsilon)
		cout << "3rd Prize" << endl;
	else if(fabs(correctNoCount - 4.5) < epsilon)
		cout << "4th Prize" << endl;
	else if(fabs(correctNoCount - 4) < epsilon)
		cout << "5th Prize" << endl;
	else if(fabs(correctNoCount - 3.5) < epsilon)
		cout << "6th Prize" << endl;
	else if(fabs(correctNoCount - 3) < epsilon)
		cout << "7th Prize" << endl;
	else
		cout << "No Prize" << endl;

    system("pause");
    return 0;
}
