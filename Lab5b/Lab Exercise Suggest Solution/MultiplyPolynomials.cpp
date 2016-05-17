// ---------------------------------------------------
//
//   AST21105 Object Oriented Programming and Design
//   Lab05b - Suggested Solution
//   
// ---------------------------------------------------

#include <iostream>
using namespace std;

/*
	By passing first and second polynomials array and their size into this function
	It will return a new array with answer inside
*/
double* multiplyPolynomials(const double* const p, const double* const q, int& np, int& nq{
	int ansSize = (np + nq - 1);
	double* ans = new double[ansSize];
	for (int i = 0; i < ansSize; i++)
		ans[i] = 0.0;

	for (int a = 0; a < np; a++)
		for (int b = 0; b < nq; b++) 
			ans[a + b] += p[a] * q[b];

	return ans;
}

int main() {
	int aSize = 0;
	int bSize = 0;
	cout << "Polynomial Solver" << endl;
	cout << "-----------------" << endl;

	while (aSize >= 0) {
		cout << "Number of terms for the first polynomial p: ";
		cin >> aSize;
		if (aSize < 0)
			break;

		double* aArr = new double[aSize];
		cout << "Terms (from lowest order term to the highest): ";
		for (int i = 0; i < aSize; i++)
			cin >> aArr[i];

		cout << "Number of terms for the second polynomial q: ";
		cin >> bSize;
		double* bArr = new double[bSize];
		cout << "Terms (from lowest order term to the highest): ";
		for (int i = 0; i < bSize; i++)
			cin >> bArr[i];

		double* ans;
		ans = multiplyPolynomials(aArr, bArr, aSize, bSize);
		cout << "Result: " << ans[0];
		for (int i = 1; i < (aSize + bSize - 1); i++)
			if (ans[i] != 0)
				cout << ", " << ans[i] << " x" << i;
		cout << endl << endl;

		/*
			Clean up memory
		*/		
		delete[] aArr;
		aArr = NULL;
		delete[] bArr;
		bArr = NULL;
		delete[] ans;
		ans = NULL;

	}
	cout << "Thanks for using our program!" << endl << endl;

	system("pause");
	return 0;
}