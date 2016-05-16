#include<iostream>>
#include "Point.h"
#include<cstdlib>
#include<conio.h>
#include<cstdio>
#include<random>>
using namespace std;
#define COUNTER 10
#define BULLETS 100
int counter =6;
Point boss;
Point enemies[COUNTER];
Point shooters[BULLETS];
int height = 20;
int width  =20;

bool play = true;
bool shootStart = false;
struct positions{
    int x;
    int y;
};
bool endGame = false;
int bullets =0;
positions shooter;
positions player;

int points=0;
void Draw(){
    system("cls");
    for(int i =0; i < width + 2 ; i++)
        cout << "#";
    cout << "\n";
    for(int j = 0; j < height ; j++){
        cout << "#";
        for(int i =0;i<width; i++){
            bool flag = false;
            if(i == player.x && j == player.y)
                cout << "Y";
            else if(i == boss._x && j == boss._y)
                cout << "B";

            else{
            for(int k =0; k < counter ; k++){
                if( i == enemies[k].getX() && j == enemies[k].getY()){
                    cout << enemies[k].ship;
                    flag= true;
            }
             }

            for(int z =0; z <bullets;z++){
                if(i == shooters[z].getX() && j == shooters[z].getY()){
                    cout << "|";
                    flag = true;
                }
            }



            if(!flag)
                cout <<" ";
            }
        }
        cout << "#";
        cout << "\n";

    }
    for(int i =0; i < width  + 2; i++)
        cout << "#";
    cout << "\n";
    printf("Boss life %d bullets remainder : %d", boss.life, 50 - bullets);


}
void Input(){
    if(_kbhit()){
        shootStart = false;
        switch(_getch())
        {
        case 'a':
            player.x--;
            break;

        case 'd':
            player.x++;

             break;
        case 'k':
            if(bullets < 50){
            bullets++;
            shootStart = true;


            }

            else{
                cout << "No more bullets" << endl;
                play = false;
            }
            break;
        //take of the comment to reload the gun
        /*
        case 'u':
            bullets = 0;
            for(int i = 0; i < BULLETS; i++){
                shooters[i]._y = 15;
                shooters[i]._x = 15;
                }

            break;
            */
        case 27:
            play = false;
            break;

        case 'p':
            system("cls");
            cout<<"\n\n\t\tPAUSE\n\n";
            cout << "\t\tEnter a key to continue";
            _getch();

        }
    }
}
void Update(){

    for(int i =0; i < counter; i++)
        if(enemies[i].getX() > 19){
            enemies[i]._x = 0;
            enemies[i]._y++;
        }
        else
            enemies[i]._x ++;

    for(int u = 0; u < bullets; u++){
        if(!shooters[u].go){
            shooters[u]._x = player.x;
            shooters[u].go = true;

        }

    }
    for(int u = 0; u < bullets; u++){

           shooters[u]._y--;



    }


}
void Logic()
{
    //player logic
    if(player.x < 0)
        player.x = 0;
    if(player.x >= width)
        player.x = width -1;
    for(int i =0; i < bullets;i++)
    {
        for(int y =0; y < counter ;y ++){
            if(shooters[i]._x == enemies[y]._x && shooters[i]._y == enemies[y]._y && enemies[y].ship == '%'){
                enemies[y].ship = ' ';
                points++;
                counter--;
            }
            if(enemies[y]._x == player.x && enemies[y]._y == player.y){
                play = false;
                endGame = true;
            }
        }
        if(shooters[i]._x == boss._x && shooters[i]._y == boss._y){
            boss._x = 1 + rand() %  width - 1;
            boss.life-=1;
        }
        if(boss.life == 0){

            points+=10;
            play = false;
            endGame = false;

        }
    }

    bool restartEnemies = true;
    for(int i =0; i < counter ; i++){
        if(enemies[i].ship == '%')
            restartEnemies = false;
    }
    if(restartEnemies)
    {

    enemies[0]._x = 1;
    enemies[0]._y = 3;
    enemies[0].ship = '%';
    for(int i = 1; i < COUNTER ; i++)
    {
        enemies[i]._x = enemies[i-1]._x + i;;
        enemies[i]._y = 3;
        enemies[i].ship = '%';

    }
        counter = 6;
        }



}

int main()
{
    cout << "Welcome To Simple Space Invaders\n\n";
    cout << "[k]To Shoot [ESC]Exit\n\n";
    cout << "[a]Move LEFT [d]Move Right\n\n";
    cout << "[P]Pause\n\n";
    cout << "Enter a key to Start\n\n";
    if(_getch() == 27)
        return 0;
    //set boss position
    boss._x = 1 + rand() % width - 1;
    boss._y = 2;
    //set player position
    player.x = width/2; //player position  x to middle of width
    player.y = height - 2;  //player position  y to height botton
    //init the enemies objects
    enemies[0]._x = 1;
    enemies[0]._y = 3;
    for(int i = 1; i < COUNTER ; i++)
    {
        enemies[i]._x = enemies[i-1]._x + i;;
        enemies[i]._y = 3;

    }
    //set example bullet positions
    for(int i = 0; i < BULLETS; i++){
        shooters[i]._y = player.y ;
        shooters[i]._x = 15;
    }
    while(play){
        Input();
        Update();
        Logic();
        Draw();


    }
    system("cls");
    cout << "Points : " << points << endl;
    if((!endGame && bullets < 50 || boss.life == 0) && points > 0)
        cout << "You win the battle\n";
    else if(bullets >= 49)
        cout << "Bullets over\n";
    else
        cout << "You loose the battle\n";
    int key;
    cout << "Enter a key and type  Enter to exit";
    cin >> key;
   return 0;

}
