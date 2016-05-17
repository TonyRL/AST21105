#ifndef Rational_h
#define Rational_h

#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
class Rational {
// Data Member.
private:
	T numerator;
	T denominator;

// Member Function.
public:
	void initialize(T& theNumerator, T& theDenominator) {
		// initialze numerator.
		setNumerator(theNumerator);
		// initialze numerator.
		setDenominator(theDenominator);
		// after initialze, reduce it.
		reduce();
	}
	
	const T getNumerator() {
		// return valuse of numerator.
		return numerator;
	}

	const T getDenominator() {
		// return value of denominator.
		return denominator;
	}

	void setNumerator(T& theNumerator) {
		// set valuse of numerator.
		numerator = theNumerator;
	}

	void setDenominator(T& theDenominator) {
		// set value of denominator.
		denominator = theDenominator;
	}

	Rational<T>* add(const Rational<T>& right)const {
		// create a new rational for storing result.
		Rational<T>* result = new Rational<T>;
		// calculate new numerator and denominator.
		T resultNumerator = (numerator)*(right.denominator) + (right.numerator)*(denominator);
		T resultDenominator = (denominator)*(right.denominator);
		// store it in result and return it.
		result->initialize(resultNumerator, resultDenominator);
		return result;
	}

	Rational<T>* subtract(const Rational& right)const {
		// create a new rational for storing result.
		Rational<T>* result = new Rational<T>;
		// calculate new numerator and denominator.
		T resultNumerator = (numerator)*(right.denominator) - (right.numerator)*(denominator);
		T resultDenominator = (denominator)*(right.denominator);
		// store it in result and return it.
		result->initialize(resultNumerator, resultDenominator);
		return result;
	}

	Rational<T>* multiply(const Rational& right)const {
		// create a new rational for storing result.
		Rational<T>* result = new Rational<T>;
		// calculate new numerator and denominator.
		T resultNumerator = (numerator)*(right.numerator);
		T resultDenominator = (denominator)*(right.denominator);
		// store it in result and return it.
		result->initialize(resultNumerator, resultDenominator);
		return result;
	}

	Rational<T>* divide(const Rational& right)const {
		// create a new rational for storing result.
		Rational<T>* result = new Rational<T>;
		// calculate new numerator and denominator.
		T resultNumerator = (numerator)*(right.denominator);
		T resultDenominator = (denominator)*(right.numerator);
		// store it in result and return it.
		result->initialize(resultNumerator, resultDenominator);
		return result;
	}

	const string getRationalString() {
		// return XX/XX in string.
		stringstream result;
		// Undifine
		if (denominator == 0)
			result << "Undifine (divide by 0)";
		else
			result << numerator << "/" << denominator;
		return result.str();
	}

	const string getFloatString() {
		// return X.XXXXX in string.
		stringstream result;
		// Undifine
		if (denominator == 0)
			result << "Undifine (divide by 0)";
		else
			result << numerator / 1.0 / denominator;
		return result.str();
	}

	void reduce() {
		// find the minimum in numerator and denominator
		T minvalue;
		minvalue = (abs(numerator)<abs(denominator)) ? abs(numerator) : abs(denominator);
		// find HCF
		for (T i = minvalue; i > 0; i--)
			if ((numerator % i == 0) && (denominator % i == 0)) {
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
};

#endif