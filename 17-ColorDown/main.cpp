//tower of hanoi
#include<windows.h>
#include<conio.h>
#include <iostream>
#include<random>
const int width = 15;
const int height = 20;
using namespace std;
#define NLETTERS 100
default_random_engine RandomGenerator;
uniform_int_distribution<int> velEnemy(0, 10);
uniform_int_distribution<int> enemyY(-200, -5);
uniform_int_distribution<int> pEnemy(0, width);
uniform_int_distribution<int> img(36, 126);
uniform_int_distribution<int> colors(1, 5);
struct positions{
    int x;
    int y;
    char img = '@';
};
int nLetters= 0;
int life = 20;
positions enemy[NLETTERS];
positions player;
bool play = true;
char ColorChar(char ch, int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout << ch;
}
void Draw(){
    system("cls");

    for(int i =0; i < width + 2 ; i++)
        cout << "-";
    cout << "\n";
    for(int j = 0; j < height  ; j++){

        for(int i =0;i<width; i++){
            bool flag =false;
            if(i == player.x && j == player.y){
                ColorChar(player.img, 2);
                flag = true;
            }
            for(int k =0; k < NLETTERS; k++){
                if(enemy[k].x == i && enemy[k].y == j){
                    ColorChar(enemy[k].img, colors(RandomGenerator));
                     flag = true;
                }

            }
            if(!flag)
                cout << " ";

        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

        cout << endl;
    }

    for(int i =0; i < width + 2 ; i++)
        cout << "-";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "\nLife : " << life << endl;
}

void Input(){
    if(_kbhit()){
        switch(_getch())
        {


            case 27:
                play = false;
                break;
            case 's':
                player.x--;

                break;
            case 'd':
                player.x++;
                break;
            case 'p':
                system("cls");
                cout << "\n\n\t\tPAUSE\n\n";
                cout << "Enter any key to continue";
                _getch();
                break;
            default:
                break;

            }
        }



    }
bool Logic(){
    bool logic = true;
    for(int i =0; i < NLETTERS ; i++){
        if(enemy[i].x == player.x && enemy[i].y == player.y){
            life--;
            player.x = 1 + rand() % width - 1;
        }
        if(enemy[i].y < height)
            logic = false;

    }
    if(player.x > width - 1)
        player.x = width  -1;
    if(player.x < 0)
        player.x = 0;
    return logic;

}
void InitializeGame(){
    //the bigger plate
    cout << "\n\n\t\tWelcome to Colors Down\n";
    cout << "\n\n\tYou are the @, use the letter [s]Left [d] to move\n";
    cout << "\n\n\t\tYou need to scape of the Colors  " ;
    cout << "\n\tEnter any key Start\n";
    cout << "\n\[ESC]EXIT [P]PAUSE\n";
    if(_getch() == 27)
        play = false;
    player.x = 2;
    player.y = 15;
    //start enemy positions
    for(int i = 0; i < 100; i++){
        enemy[i].x = rand() % width;
        enemy[i].y = enemyY(RandomGenerator);
        char letter = ' ';
        do{
            letter = (char)img(RandomGenerator);
        }while(letter == 'a' || letter == '7');
        enemy[i].img = letter;

    }




}
void Update(){
    for(int i = 0; i < NLETTERS; i++){
            if(velEnemy(RandomGenerator) == 5)
                enemy[i].y+=1;

    }

}
int main()
{

   InitializeGame();
    while(play && !Logic()){
        Input();
        Update();
        Draw();




    }
    system("cls");
    if(Logic() && life > 0)
        cout << "You win the game\n";
    else
        cout << "You loose the game\n";
    cout << "Thanks to play\n\n";

    return 0;
}
