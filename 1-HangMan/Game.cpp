//Hangman
//by hantaro
#include<random>
#include<iostream>
#include<fstream>
#include<string>
#include<istream>
#include<ctime>
#include<vector>
#include "Hangman.h"
using namespace std;

int main()
{
	
	Hangman newGame;
	newGame.CreateBoad();
	newGame.printSecret();
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