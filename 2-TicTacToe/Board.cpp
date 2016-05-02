#include "Board.h"
Board::Board()
{
	cout << "\tWelcome To Tic Tac Toe\n";
}



void Board::PrintBoard()
{
	cout << "\n";
	for (int i = 0; i < 9; i++){
		cout << "\t" << _board[i];
		if (i == 2 || i == 5)
			cout << "\n";
	}
	cout << "\n";
}
void Board::InitializeBoard()
{

	char board[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	for (int i = 0; i < 9; i++)
		_board[i] = board[i];
}
bool Board::AddPosition(int position, char player)
{
	if (position < 1 || position > 9){
		cout << "The position is beyond the board" << endl;
		cout << "Enter a position between [1 - 9]\n";
		return false;
	}
	if (_board[position - 1] == 'x' || _board[position - 1] == 'o')
	{
		cout << "The space is occupied , Choose another one";
		false;
	}
	if (_board[position - 1] != 'x' && _board[position - 1] != 'o')
	{
		_board[position - 1] = player;
		return true;
	}
	
}
bool Board::Win(char player)
{

	//the x positions
	if (_board[0] == player && _board[1] == player && _board[2] == player)
		return true;
	if (_board[3] == player && _board[4] == player && _board[5] == player)
		return true;
	if (_board[6] == player && _board[7] == player && _board[8] == player)
		return true;
	//the y postions
	if (_board[0] == player && _board[3] == player && _board[6] == player)
		return true;
	if (_board[1] == player && _board[4] == player && _board[7] == player)
		return true;
	if (_board[2] == player && _board[5] == player && _board[8] == player)
		return true;
	//a cross the board
	if (_board[0] == player && _board[4] == player && _board[8] == player)
		return true;
	if (_board[2] == player && _board[4] == player && _board[6] == player)
		return true;
	
	return false;
}

bool Board::Tie()
{
	for (int i = 0; i < 9; i++)
	{
		if (_board[i] != 'x' && _board[i] != 'o')
			return false;
	}
	
	return true;
}
