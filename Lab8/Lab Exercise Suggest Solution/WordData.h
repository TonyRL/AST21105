#ifndef WORDDATA_H
#define WORDDATA_H

#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class WordData
{
	private:
		char* word;
		int vowels;
		int consonants;
		int digits;
		int specialChars;
	public:
		WordData();
		~WordData();
		void setWord(const string& inWord);
		string getWord() const;
		void displayData() const;	
};

#endif