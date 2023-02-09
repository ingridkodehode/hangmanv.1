#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>

using namespace std;

const int MAXTRIES=4;
int letterFill (char, string, string&);


int main ()
{
	string name;
	char letter;
	int numwrongguess=0;
	string word;
	string words[] =
	{
		"linger",
		"switch",
		"scrape",
		"ghosts",
		"deputy",
		"stride",
		"meadow",
		"manage",
		"moment",
		"scream"
	};


	srand(time(NULL));
	int n=rand()% 10;
	word=words[n];


	string unknown(word.length(),'*');


	cout << "\n\nWelcome.";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAXTRIES << " tries to try and guess the word.";


	while (numwrongguess < MAXTRIES)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;

		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "That letter isn't in there." << endl;
			numwrongguess++;
		}
		else
		{
			cout << endl << "You found a letter!" << endl;
		}

		cout << "You have " << MAXTRIES - numwrongguess;
		cout << " guesses left." << endl;

		if (word==unknown)
		{
			cout << word << endl;
			cout << "You can tell me if you cheated.";
			break;
		}
	}
	if(numwrongguess == MAXTRIES)
	{
		cout << "\nSorry, you've been hanged :(" << endl;
		cout << "The word was : " << word << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}


int letterFill (char guess, string secretword, string &guessword)
{
	int i;
	int matches=0;
	int len=secretword.length();
	for (i = 0; i< len; i++)
	{

		if (guess == guessword[i])
			return 0;

		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}
