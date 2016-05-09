#include <iostream>
#include<stdio.h>
#include<cstdlib>
#include<conio.h>
#include<random>
#include<ctime>

using namespace std;
int widht = 20;
int height = 20;
char shoot = '|';

bool shooter = false;
char options[] = {'o', '7', '&', '2', '8', '*', '%', '!', '.'};
uniform_int_distribution<int> option(0, 8);

char player = 'V';

bool computerShooter = false;
//random computer position
default_random_engine RandomGenerator(time(0));
uniform_int_distribution<int> computerPosition(2, widht -2);

char computerThing = options[option(RandomGenerator)];
struct position{
    int x = widht/2;
    int y = 18;
};

position computer;
position playerPosition;
int points = 0;
int level = 0;
void draw(char shoot, position shootPosition)
{
    for(int i = 0; i < widht +2; i ++)
        cout << "#";
    cout << endl;
    for(int i = 0; i < height; i++)
    {
        cout << "#";
        for(int j = 0 ; j < widht ; j++)
        {
            if(j == shootPosition.x && i == shootPosition.y && shooter)
                cout << shoot;
            else if(j == playerPosition.x && i == playerPosition.y)
                cout << player;
            else if(j == computer.x && i == computer.y)
                cout << computerThing;

            else
                cout << " ";
        }
       cout << "#";
        cout << endl;
    }
    for(int i = 0; i < widht +2; i ++)
        cout << "#";

    cout << endl;
    printf("Points : %d\tLevel : %d", points, level);
}
int main()
{

    computer.y = 2;
    int computerVel[] = {0,0};
    int velShooter[] = {0,0};
    int velShooterPC[] = {0,0};
    position shoot_p;
    shoot_p.x = playerPosition.x;
    shoot_p.y = playerPosition.y -1;
    bool game = true;
    char t;

   while(game){

    if(_kbhit())
    {

    t = _getch();
    if(t == 27)
        return 0;

    if(t == ' ' && shooter == false){
        shooter = true;
        velShooter[1] = -1;
        shoot_p.x = playerPosition.x;
        cout << "\7";
    }
    if(t == 'M')
        playerPosition.x +=1;


    if(t == 'K')
        playerPosition.x -=1;
    }

    if(shoot_p.y < computer.y)
    {
        shoot_p.y = playerPosition.y -1;
        shooter = false;
        velShooter[1] = 0;
    }
    //shooter the computer
    if(shoot_p.y == computer.y && shoot_p.x == computer.x)
    {
        computer.x = computerPosition(RandomGenerator);
        computer.y = 2;
        computerThing = options[option(RandomGenerator)];
        points+=1;

    }
    bool startPoints = false;
    if(points == 1 && !startPoints && level == 0){
        level =1;
        computerVel[0] = 1;
        startPoints = true;
    }
    if(points == 20)
        level =2;
    if(points == 30)
        level = 3;


    if(level == 32)
        game = false;
    if(computer.x > widht -1 && level > 0){
        computerVel[0] = -1;
        computer.x = widht;
        computer.y+=1;
    }
    if(computer.x < 1 && level > 0)
    {
        computerVel[0] = 1;

    }
    if(computer.x == playerPosition.x && computer.y == playerPosition.y){
        game = false;
        cout << "\7\7";
    }

    computer.x += computerVel[0];


    shoot_p.y += velShooter[1];
    system("cls");
    draw(shoot, shoot_p);
   }
   system("cls");
   if(points == 32)
   {
       cout << "\n\nWin the Game";
       return 0;
   }
   cout << "\nLose the Game";
    return 0;
}
