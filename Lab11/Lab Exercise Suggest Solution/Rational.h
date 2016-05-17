#ifndef Rational_h
#define Rational_h

#include <iostream>
#include <sstream>

using namespace std;

class Rational {
// Data Member.
private:
	int numerator;
	int denominator;

// Member Function.
public:
	void initialize(int& theNumerator, int& theDenominator);	//initialze numerator and denominator
	
	const int getNumerator();		// return valuse of numerator
	const int getDenominator();		// return valuse of denominator

	void setNumerator(int& theNumerator);		// set numerator.
	void setDenominator(int& theDenominator);	// set denominator.

	Rational* add(const Rational& right)const;		// add 2 rational.
	Rational* subtract(const Rational& right)const;	// subtract 2 rational.
	Rational* multiply(const Rational& right)const;	// multiply 2 rational.
	Rational* divide(const Rational& right)const;	// divide 2 rational.

	void reduce();	// reduce numerator and denominator.

	const string getRationalString();	// return XX/XX in string.
	const string getFloatString();		// return X.XXX in string.
};

#endif