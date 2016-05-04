//blackjack game
//by hantaro

#include<iostream>
#include<random>
#include<vector>
#include<ctime>

using namespace std;
default_random_engine RandomGenerator(time(0));
uniform_int_distribution<int> CardsGenerator(1, 12);
void PrintCard(int card)
{
	if (card > 1 && card < 10)
		printf("Card [%d]\n", card);
	else if (card == 1)
		printf("Card [A]\n");
	else
		if (card == 10)
			cout << "Card [J]\n";
		else if (card == 11)
			cout << "Card [Q]\n";
		else
			cout << "Card [K]\n";
}
void showCards(vector<int>cards)
{
	vector<int>::iterator iter;
	cout << "Cards : \n";
	for (iter = cards.begin(); iter != cards.end(); iter++)
	{
		PrintCard(*iter);

	}
}
void NewCard(vector<int>&cards, int& ncards , int& sumCards)
{
	int card = CardsGenerator(RandomGenerator);
	cards.push_back(card);
	
	ncards++;
	cout << "New card : ";
	PrintCard(card);
	if (card == 1 && sumCards + 10 <= 21)
		card = 10;
	if (card >= 10 && card <= 12)
		card = 10;
	cout << "Card value = " << card << endl;
	ncards++;
	sumCards += card;
}
int main()
{
	
	vector<int> pcCards;
	
	vector<int>playerCards;
	//player variables
	/*
	int ncards = 0;
	int sumCards = 0;
	//pc variables
	int nPcCards = 0;
	int pcSumCards = 0;
	*/
	int money = 0;
	bool play = false;
	int choice;
	cout << "Do you want to play : [1]Yes [2]No";
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "Enter a valid choice";
		cin >> choice;
	}
	if (choice == 1)
	{
		play = true;
		cout << "Enter your money : ";
		cin >> money;
		while (money <= 0)
		{
			cout << "enter a valid money : ";
			cin >> money;
		}

	}
	while (money > 0 && play)
	{
		int bet = 0;
		int ncards = 0;
		int sumCards = 0;
		//pc variables
		int nPcCards = 0;
		int pcSumCards = 0;
		
		pcCards.clear();
		playerCards.clear();

		bool stop = false;

		int options = 0;
		bool keepPlaying = true;
		while (sumCards < 21 && keepPlaying)
		{
			cout << "\t*****Player*****\n";
			cout << "Enter a option  [1]Get a Card [2]Show Cards [3]Stop [4] Enter a bet or increase bet";
			
			cin >> options;
			
			switch(options)
			{
			case 1:
				NewCard(playerCards, ncards, sumCards);
				break;
			case 2:
				showCards(playerCards);
				continue;
				
			case 3:
				stop = true;
				if (sumCards > pcSumCards)
				{
					if (bet <= 0){
						cout << "You win the game but you don't make a bet and get just $1\n";
						bet = 1;
					}
					else
						cout << "You get $" << 2 * bet << endl;
					money += 2 * bet;
				}
				else if (sumCards == pcSumCards)
				{
					cout << "No body wins is a tie";
				}
				else
				{
					cout << "Pc win" << endl;
					cout << "you loose $" << bet << endl;
					money = money - bet;
				}
				keepPlaying = false;
				break;
			case 4:
				
				
				if (bet <= 0){
					cout << "Enter a bet : ";
					cin >> bet;
					while (bet > money && bet < money)
					{
						cout << "Invalid bet\n";
						cout << "Enter a bet : ";
						cin >> bet;
					}
				}
				else{
					cout << "increase bet : ";
					int newBet = 0;
					cin >> newBet;
					while (bet + newBet > money)
					{
						cout << "Invalid bet\n";
						cout << "Enter a bet : ";
						cin >> newBet;
					}
					bet += newBet;

				}
				
				break;
			default:
				cout << "Invalid option";
				cout << "Enter a option  [1]Get a Card [2]Show Cards [3]Stop [4] Enter a bet or increase bet";
				break;
			}
			cout << "\n\t*****PC Playing*****\n";
			if (pcSumCards < sumCards)
			{
				cout <<  "The Pc Get a Card" << endl;
				NewCard(pcCards, nPcCards, pcSumCards);
			}
			cout << "Pc";
			showCards(pcCards);
			cout << "\t*****End PC Playing*****\n";
			cout << "\tPoints Game :\n" << endl;
			cout << "Pc points = " << pcSumCards << endl;
			cout << "Player points = " << sumCards << endl;
			if (!stop && sumCards >= 21)
			{
				if (sumCards > pcSumCards)
				{
					if (bet <= 0){
						cout << "You win the game but you don't make a bet and get just $1\n";
						bet = 1;
					}
					else
						cout << "You get $" << 2 * bet << endl;
					money += 2 * bet;
				}
				else if (sumCards == pcSumCards)
				{
					cout << "No body wins is a tie\n";
				}
				else
				{
					cout << "Pc win" << endl;
					cout << "you loose $" << bet << endl;
					money = money - bet;
				}
				keepPlaying = false;
			}
		}
		cout << "You money is : " << money << endl;
		cout << "Do you want to play : [1]Yes [2]No";
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			cout << "Enter a valid choice";
			cin >> choice;
		}
		if (choice == 1)
			play = true;

		else
			play = false;

		

	}
		
	
	
	
	int x;
	cout << "Enter a key to exit...";
	cin >> x;

}