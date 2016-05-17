// ---------------------------------------------------
//
//   AST21105 Object Oriented Programming and Design
//   Lab03 - Suggested Solution
//
// ---------------------------------------------------

// #include is a pre-processor command denoted by #,
// which tells the compiler to take iostream and ctime,
// compile them into the program which is anothor file
// that has the implementation of cin, cout and time function

#include <iostream> 
#include <ctime>

// The using namespace std is inserted, so that it helps to avoid
// the needs of writing std::cout and std:cin in the code

using namespace std; 

int main()
{
    // Initialize random seed
    srand(time(NULL));
    
    int step = 1;
    int guessNo[4];
    int userNo[4];
    
    // A boolean array used to keep track which number has been generated
    bool valueTable[6] = { false, false, false, false, false, false };

    // Repeatedly generate random numbers until 4 distinct values are found
    int no = 0;
    do{
       int value = rand() % 6 + 1;
       if(!valueTable[value - 1]) {
         guessNo[no] = value;
         valueTable[value - 1] = true;
         no++;
       }
    }while(no < 4);
  
    cout << "MasterMind ( ";
    for(int i=0; i<4; i++)
       cout << guessNo[i] << " ";
    cout << ")" << endl << endl;
    
    cout << "Enter four digits (1 - 6) separated by a space" << endl; 
    cout << "----------------------------------------------" << endl; 

    int vCorrect = 0;
    int pCorrect = 0;  
    do{ 
       vCorrect = 0;
       pCorrect = 0;        
       cout << "Round " << step << ":" << endl; 
       cout << "Enter Guess: ";
       
       // Obtain 4 integers from user
       for(int i=0; i<4; i++)
          cin >> userNo[i];
  
       cout << "             "; 
       
       // Check how many input integers are "right value, right position"
       for(int i=0; i<4; i++) {
          if(userNo[i] == guessNo[i])
             pCorrect++;
       }
       
       // Check how many input integers are "right value"
       // This code segment also takes those with 
       // "right value, right position" into consideration
       for(int i=0; i<4; i++) {
          for(int j=0; j<4; j++) {
             if(userNo[i] == guessNo[j])
                vCorrect++;
          }
       }
       
       // This is a piece of code used to check how many
       // repeated input values
       int countOccur[6] = { 0, 0, 0, 0, 0, 0 };
       for(int i=0; i<4; i++)
          countOccur[userNo[i] - 1]++;
       int total = 0;
       for(int i=0; i<6; i++)
       {
          if(countOccur[i] > 1)
             total += (countOccur[i] - 1);
       }

       // This line of code checks the actual number
       // of input integers are "right value"
       vCorrect = vCorrect - pCorrect - total;
  
       // Output result
       for(int i=0; i<pCorrect; i++) 
            cout << "O " ; 
       for(int j=0; j<vCorrect; j++) 
            cout << "# " ; 
       cout << endl; 
       cout << "----------------------------------------------" << endl;   
       step++;
    }while(pCorrect < 4);
    cout << "Congratulations! You win in " << step - 1 << " steps!" << endl; 
    system("pause");
    return 0; 
}
