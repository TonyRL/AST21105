// ---------------------------------------------------
//
//   AST21105 Object Oriented Programming and Design
//   Lab04 - Suggested Solution
//   
// ---------------------------------------------------

// #include is a pre-processor command denoted by #,
// which tells the compiler to take iostream and ctime,
// compile them into the program which is anothor file
// that has the implementation of cin, cout and time function

#include <iostream>

// The using namespace std is inserted, so that it helps to avoid
// the needs of writing std::cout and std:cin in the code

using namespace std;

int main()
{
    // The number of primes found
    int count = 0;
    int number;
    cout << "Enter the value of n: ";
    cin >> number;
    
    // An array of primes
    bool* primes = new bool[number];
    
    // Initialize all array values to true
    for(int index = 0; index < number; index++)
       primes[index] = true;
    
    // Starting at the third value, cycle through the array and put 0
    // as the value of any greater number that is a multiple
    for(int i=2; i<number; i++)
    {
       if(primes[i])
       {
          for(int j=i+i; j<number; j+=i)
             primes[j] = false;
       }
    }
    
    cout << "Prime numbers: ";
    for(int index = 2; index < number; index++)
    {
       if(primes[index])
       {
          cout << index << " ";
          count++;
       }
    }
    cout << endl;
    
    // Deallocate the array
    delete [] primes;
    
    cout << count << " primes found." << endl;
    system("pause");
    return 0;
}
