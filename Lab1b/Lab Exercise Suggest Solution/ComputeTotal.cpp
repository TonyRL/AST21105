// ---------------------------------------------------
//
//   AST21105 Object Oriented Programming and Design
//   Lab01 Part B - Suggested Solution
//
// ---------------------------------------------------

// #include is a pre-processor command denoted by #,
// which tells the compiler to take iostream and compile it
// into the program which is anothor file that has the
// implementation of cin and cout

#include <iostream>

// The using namespace std is inserted, so that it helps to avoid
// the needs of writing std::cout and std:cin in the code

using namespace std;

// The starting point of the program

int main()
{
    while(true)
    {
       // Obtain the number of values to be input
       int no;
       cout << "Enter input: ";
       cin >> no;
       
       // If no = -1, quit the while loop
       if(no == -1)
          break;
          
       // Obtain inputs and calculate total
       int total = 0;
       for(int i=0; i<no; i++)
       {
          int value;
          cin >> value;
          total += value;
       }
       
       // Output the total
       cout << "Output total: " << total << endl;
    }
	system("pause");
	return 0;
}
