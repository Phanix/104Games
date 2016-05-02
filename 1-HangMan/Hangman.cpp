#include "Hangman.h"
#include<fstream>
#include<random>
#include<ctime>
#include<string>
#include<iostream>
using namespace std;
Hangman::Hangman()
{

}
void Hangman::CreateBoad()
{
	default_random_engine randomGenerator(time(0));
	uniform_int_distribution<int> secretSort(1, 500);
	ifstream teste;
	teste.open("wordlist.txt");
	if (teste.fail()){
		perror("wordlist.txt");
		

	}
	string line;
	while (getline(teste, line))
		if (secretSort(randomGenerator) == 10)
			break;


	
	vector<char> words(line.size(), '-');
	_board = words;
	_word = line;
}
void Hangman::printBoard()
{
	
	for (iter = _board.begin(); iter != _board.end(); iter++)
		cout << *iter << " ";
}
bool Hangman::add(char choice)
{
	if (_word.find(choice) != string::npos){
		for (iter = _missed.begin(); iter != _missed.end(); iter++)
			if (choice == *iter)
				return false;
		for (int i = 0; i < _word.size(); i++)
			if (_word[i] == choice){
				if (!(_positions.find((char)i) != string::npos)){
					_positions += (char)i;
					_board[i] = choice;
					return true;
				}
			}
	}

	else
		_missed.push_back(choice);
}
bool Hangman::CheckWin()
{
	
	for (iter = _board.begin(); iter != _board.end(); iter++)
		if (*iter == '-')
			return false;
	
	return true;
}

void Hangman::printSecret()
{
	cout << _word << endl;
}
bool Hangman::looser()
{
	if (_missed.size() > _word.size()){
		cout << "You loose" << endl;
		cout << "Secret work = " << _word << endl;
		return true;
	}
	else
		return false;
}
void Hangman::printMan()
{
	
}