//Machine Slot
//by hantaro



#include<iostream>
#include<random>
#include<ctime>

using namespace std;

//random numbers
default_random_engine RandomGenerator(time(0));
uniform_int_distribution<int> dice(1, 7);

//Make a bet
void RollGame(int &point, int bet, int &wins, int &loosers);

//function to show the rules of the game
void GameRules();

//Print the game states
void printStates(int points, int loosers, int wins);

int main()
{
	//variables
	int loosers = 0;
	int wins = 0;
	int credits = 10;
	int bet = 0;
	int choice = 0;
	bool game = true;
	while (game){
		cout << "Enter [1]Bet   [2]See Stats [3]Exit [4]Game Rules";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "You have : " << credits << endl;
			cout << "Enter your bet : " << endl;
			cin >> bet;
			if (bet <= credits)
			{
				RollGame(credits, bet, wins, loosers);
			}
			else{
				cout << "You don't have credit Enough" << endl;
				cout << "Enter a bit between 0 - " << credits << endl;
			}
			break;
		case 2:
			printStates(credits, wins, loosers);
			break;
		case 3:
			game = false;
			break;
		case 4:
			GameRules();
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}

		if (credits <= 0){
			break;
		}
		
	}
	printStates(credits, loosers, wins);
	if (loosers > wins)
		cout << "Try Another \nYou looser the game" << endl;
	else if (loosers < wins)
		cout << "Nice job You win the game" << endl;
	else{
		cout << "Good job" << endl;
	}
	int a;
	cout << "Enter a key than Enter to exit...";
	cin >> a;
}

//function to show the rules of the game
void GameRules()
{
	printf("\tGame Rules\n\n");
	printf("When 3 numbers equal and not 7 \n");
	printf("You win is 2 times the bet\n");
	printf("When  3 numbers equal 7\n");
	printf("Now you got a JackPot and your win is 3 times the bet\n");
	printf("When the numbers is different , than you looser your bet in credits\n");

}

//Make a bet
void RollGame(int &point, int bet, int &wins, int &loosers)
{
	if (point > 0){
		int roll1 = dice(RandomGenerator);
		int roll2 = dice(RandomGenerator);
		int roll3 = dice(RandomGenerator);
		printf("{[%d][%d][%d]}\n", roll1, roll2, roll3);
		if (roll1 == 7 && roll2 == 7 && roll3 == 7)
		{
			point = point + (bet * 3);
			cout << "\t*****JackPot*****\n";
			printf("Win = 3 * %d = %d Credits \n", bet, (bet * 3));
			wins += 1;
		}
		else if (roll1 == roll2 && roll3 == roll1)
		{
			cout << "\t***Win***\n";
			printf("Win = 2 * %d = %d Credits \n", bet, (bet * 2));
			point = point + (bet * 2);
			cout << "here hre";
			wins += 1;
		}
		else{
			cout << "\tSorry you loose :" << bet << " Credit" << endl;;
			point -= bet;
			loosers += 1;
		}
		cout << "Credits Actual : " << point << endl;

	}
	else{
		cout << "\nGame over Thx to play\n";

	}
}

//Print the game states
void printStates(int points, int loosers, int wins)
{
	printf("\tWins = %d\nLoosers = %d\nCredits = %d\n", wins, loosers, points);
}