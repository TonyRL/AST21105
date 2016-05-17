#include "WordData.h"		

WordData::WordData()
{
	word = new char[1];
	word[0] = '\0';
	vowels = 0;
	consonants = 0;
	digits = 0;
	specialChars = 0;
}

WordData::~WordData()
{
	delete [] word;
}

void WordData::setWord(const string& inWord)
{
	if(word != NULL)
		delete [] word;
	int len = (int)(inWord.size());	
	word = new char[len + 1];
	vowels = 0;
	consonants = 0;
	digits = 0;
	specialChars = 0;
	for(int i=0; i<len; i++)
	{
		word[i] = inWord[i];
		if((word[i] >= 65 && word[i] <= 90) ||
		   (word[i] >= 97 && word[i] <= 122))
		{
			if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
			   word[i] == 'o' || word[i] == 'u' || word[i] == 'A' ||
			   word[i] == 'E' || word[i] == 'I' || word[i] == 'O' ||
			   word[i] == 'U')
		       vowels++;
		    else
		       consonants++;
		}
		else if(word[i] >= 48 && word[i] <= 57)
			digits++;
		else
			specialChars++;		
	}
	word[len] = '\0';
}

string WordData::getWord() const
{
	string str(word);
	return str;
}

void WordData::displayData() const
{
	cout << word << "\t\t" << vowels << "\t" << consonants << "\t"
		 << digits << "\t" << specialChars << endl;
}