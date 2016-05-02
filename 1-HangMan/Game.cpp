//Hangman
//by hantaro
#include<iostream>
#include "Hangman.h"
using namespace std;

int main()
{
	
	Hangman newGame;
	newGame.CreateBoad();
	char choice;
	while (!newGame.CheckWin()){
		cin.clear();
		
		newGame.printBoard();
		cout << "Enter a letter";
		cin >> choice;
		newGame.add(choice);
		if (newGame.looser()){
			return 0;
		}
		
	}
	cout << "You win";
	char key;
	cout << "\nEnter a key for exit";
	cin >> key;
	return 0;
}
