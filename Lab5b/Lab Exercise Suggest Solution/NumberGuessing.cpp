// ---------------------------------------------------
//
//   AST21105 Object Oriented Programming and Design
//   Lab05a - Suggested Solution
//   
// ---------------------------------------------------

#include <iostream>
#include <ctime>
using namespace std;

/*
	"randNoArr" is a constant pointer to a dynamically created array
	"size" is the size of the dynamic array pointed by randNoArr
*/
void shuffle( int* const& randNoArr, int& size ) {
	for( int i=0; i<(size-1); i++ ) {
		int r = i + (rand() % (size-i));
		int temp = randNoArr[i];
		randNoArr[i] = randNoArr[r];
		randNoArr[r] = temp;
	}
}

/*
	Initialize number into the array
*/
void initializeNumber(int* const& ans, int& size) {
	for( int i = 0; i < size; i++)
		ans[i] = i + 1;
	shuffle(ans, size);
}

/*
	Compair the user input and answer.
	If correct cout O.
	If wrong cout X.
	If all correct, will return true, else return false.
*/
bool checkInput(const int* const& input, const int* const& ans, int& size) {
	int bingo;
	bingo = 0;
	for( int i = 0; i < size; i++) {
		if (input[i] == ans[i]) {
			cout << "O ";
			bingo++;
		} else
			cout << "X ";
	}
	cout << endl;
	if (bingo == size)
		return true;
	else
		return false;
}

/*
	Output the answer on screen for debug.
*/
void displayAns(const int* const& ans, int& size) {
	cout << "Answer: ";
	for( int i = 0; i < size; i++)
		cout << ans[i] << " ";
	cout << endl;
}

/*
	Main game.
*/
void numberGuessing (int* const& input, int* const& ans, int& size, bool& showAns) {
	int round = 0;
	bool win = false;

	initializeNumber(ans, size);

	while (!win) {
		round++;
		if (showAns)
			displayAns(ans, size);
		cout << "Number Guessing" << endl;
		cout << "Enter " << size << " digits (1-" << size << ") separated by a space" << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "Round " << round << endl;
		cout << "Enter Guess: ";
		for (int i = 0; i < size; i++)
			cin >> input[i];
		cout << "             ";
		win = checkInput(input, ans, size);
		cout << "-----------------------------------------------------------" << endl;
	}
	cout << "Congratulations! You win in "<< round << " steps" << endl << endl;
}

int main() {
	srand((unsigned int)time(NULL));
	bool showAns = true;
	
	int size;
	cout << "Enter total number: ";
	cin >> size;
	int* ans = new int[size];
	int* input = new int[size];
	numberGuessing(ans, input, size, showAns);

	delete[] ans;
	delete[] input;

	system("pause");
	return 0;
}
