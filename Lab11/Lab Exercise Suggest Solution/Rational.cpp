#include <iostream>
#include <sstream>
#include <cmath>
#include "Rational.h"

using namespace std;

void Rational::initialize(int& theNumerator, int& theDenominator) {
	// initialze numerator.
	setNumerator(theNumerator);
	// initialze numerator.
	setDenominator(theDenominator);
	// after initialze, reduce it.
	reduce();
}

const int Rational::getNumerator() {
	// return valuse of numerator.
	return numerator;
}

const int Rational::getDenominator() {
	// return value of denominator.
	return denominator;
}

void Rational::setNumerator(int& theNumerator) {
	// set valuse of numerator.
	numerator = theNumerator;
}

void Rational::setDenominator(int& theDenominator) {
	// set value of denominator.
	denominator = theDenominator;
}

Rational* Rational::add(const Rational& right)const {
	// create a new rational for storing result.
	Rational* result = new Rational;
	// calculate new numerator and denominator.
	int resultNumerator = (numerator)*(right.denominator)+(right.numerator)*(denominator);
	int resultDenominator = (denominator)*(right.denominator);
	// store it in result and return it.
	result->initialize(resultNumerator,resultDenominator);
	return result;
}

Rational* Rational::subtract(const Rational& right)const {
	// create a new rational for storing result.
	Rational* result = new Rational;
	// calculate new numerator and denominator.
	int resultNumerator = (numerator)*(right.denominator)-(right.numerator)*(denominator);
	int resultDenominator = (denominator)*(right.denominator);
	// store it in result and return it.
	result->initialize(resultNumerator,resultDenominator);
	return result;
}

Rational* Rational::multiply(const Rational& right)const {
	// create a new rational for storing result.
	Rational* result = new Rational;
	// calculate new numerator and denominator.
	int resultNumerator = (numerator)*(right.numerator);
	int resultDenominator = (denominator)*(right.denominator);
	// store it in result and return it.
	result->initialize(resultNumerator,resultDenominator);
	return result;
}

Rational* Rational::divide(const Rational& right)const {
	// create a new rational for storing result.
	Rational* result = new Rational;
	// calculate new numerator and denominator.
	int resultNumerator = (numerator)*(right.denominator);
	int resultDenominator = (denominator)*(right.numerator);
	// store it in result and return it.
	result->initialize(resultNumerator,resultDenominator);
	return result;
}

const string Rational::getRationalString() {
	// return XX/XX in string.
	stringstream result;
	// Undifine
	if (denominator == 0)
		result << "Undifine (divide by 0)";
	else
		result << numerator << "/" << denominator;
	return result.str();
}

const string Rational::getFloatString() {
	// return X.XXXXX in string.
	stringstream result;
	// Undifine
	if (denominator == 0)
		result << "Undifine (divide by 0)";
	else
		result << numerator/1.0/denominator;
	return result.str();
}

void Rational::reduce() {
	// find the minimum in numerator and denominator
	int minvalue;
	minvalue = (abs(numerator)<abs(denominator))?abs(numerator):abs(denominator);
	// find HCF
	for (int i = minvalue; i > 0; i--)
		if ((numerator % i == 0) && (denominator % i == 0)){
			// Divide both by HCF
			numerator /= i;
			denominator /= i;
			break;
		}
	// Check negative valuse
	if (denominator < 0) {
		numerator *= -1;
		denominator *= -1;
	}
}

