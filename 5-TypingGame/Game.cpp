#include <iostream>
#include<random>
#include<conio.h>
#include<ctime>
#include<cstdio>
#include<windows.h>
using namespace std;

int score;
int missed = 0;
int level = 1;
const int width = 20;
const int height = 20;
default_random_engine RandomGenerator(time(0));
uniform_int_distribution<int> RandomLetter(65, 90);
char letter = RandomLetter(RandomGenerator);
int letter_position_x = 0;
int letter_position_y = width/2;
bool play = true;
bool win = false;


void Draw()
{
    letter_position_x+=level;

    for(int i = 0; i < width +2; i++)
            cout << "#";
    cout << endl;
    for(int i = 0; i < width; i++)
    {
        cout << "#";
        for(int j = 0; j < height; j++)
            if(letter_position_x == i && letter_position_y == j)
                cout << letter;
            else
                cout << " ";
        cout << "#";
        cout << endl;
    }
     for(int i = 0; i < width +2; i++)
            cout << "#";
    cout << endl;
    cout << "Score : " << score <<" Level : " << level << " Letter Missed : " << missed << endl;
}

int main()
{

    cout << "Welcome to Typing Game\t\n";
    cout << " To win The Game you need to make 50 points\n";
    cout << " If you miss 100 letters than you loose the Game\n";
    cout << " Enter a key to Start or Esc to Exit or Space Pause";

    if(_getch() == 27){
        play = false;
        return 0;
    }

    while(play)
    {
        system("cls");
        Draw();
        //game has two levels
        if(score == 10)
            level = 2;
        if(score == 50){
            play = false;
            win = true;
        }

        if(letter_position_x > height){
            letter_position_x = 0;
            letter_position_y = rand() % width;
            letter = RandomLetter(RandomGenerator);
            missed++;
        }
        if(_kbhit())
        {
            char teste = _getch();
            //upper the letter

            if(teste-32 == letter)
            {
                score++;
                letter_position_x = 0;
                letter_position_y = rand() % width;
                letter = RandomLetter(RandomGenerator);
            }
            if(teste == 27)
            {
                play = false;
                break;
            }
            if(teste == 32)
            {
                system("cls");
                cout << "\n\n\t\tPAUSE\n\n";
                cout << "Enter a Key to continue";
                _getch();
            }
        }
        Sleep(10);
    }
    if(win)
        cout << "You win The game" << endl;
    else
        cout << "You lost the game" << endl;
    printf("Score : %d Missed Letters : %d Level %d\n\n", score, missed, level);

    system("pause");

    return 0;
}
