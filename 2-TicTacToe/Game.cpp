#include<iostream>
using namespace std;

#include "Board.h";

int main()
{
	//Create a new game
	Board newboard;

	//Initialize the game
	newboard.InitializeBoard();

	//variables
	int position;

	//print board
	newboard.PrintBoard();

	//while no body wins or dont get a tie
	while (!newboard.Win('x') && !newboard.Win('o') && !newboard.Tie())
	{
		cout << "Player X Enter position";
		
		cin >> position;
		newboard.AddPosition(position, 'x');

		newboard.PrintBoard();
		if (newboard.Win('x'))
		{
			cout << "The player X win" << endl;
			break;
		}
		if (newboard.Tie())
		{
			cout << "Tie" << endl;
			break;
		}
		cout << "Player O Enter position";
		cin >> position;
		newboard.AddPosition(position, 'o');
		newboard.PrintBoard();
		if (newboard.Win('o'))
		{
			cout << "The player O win " << endl;
			break;
		}
	}

	cout << "Thanks to play" << endl;
	char end;
	cout << "Enter a key than Enter to exit...";
	cin >> end;
	
}