#pragma once

#include<iostream>
using namespace std;
class Board
{
public:
	Board();
	bool Win(char player);
	bool Tie();
	void PrintBoard();
	bool AddPosition(int position, char player);
	void InitializeBoard();
	
	
private:
	//the board
	char _board[9];
	
	
};

