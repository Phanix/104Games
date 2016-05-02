#pragma once
#include<vector>
using namespace std;

class Hangman
{
public:
	Hangman();
	void printBoard();
	void CreateBoad();
	void Rate();
	bool add(char choice);
	bool CheckWin();
	void printSecret();
	bool looser();
	void printMan();
private:
	vector<char>_board;
	string _word;
	vector<char> _missed;
	vector<char>::iterator iter;
	string _positions = "";
	vector<string> _man;

	
};

