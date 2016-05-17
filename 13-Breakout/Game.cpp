#include <iostream>
#include<windows.h>
#include<random>
#include<ctime>
#include<conio.h>
using namespace std;
//global variables
int attempts = 5;
bool play = true;
#define NBLOCKS 10
int nBlocks = 10;
int height = 20;
int width = 20;

struct position{
    int x  =2;
    int y = 3;
};

position ball;
position player;
int velPlayer = 0;
int velBall[2] = {1, 1};
struct blocks{
    int positionX = 2;
    int positionY = 2;
    int life = 3;
    bool dead = false;
    char blockImage = 'H';

};
blocks gameBlocks[NBLOCKS];

void Draw(){
    system("cls");
    for(int i =0; i < width + 2; i ++)
        cout << "#";
    cout << endl;
    for(int j = 0; j < height ; j ++){
        cout << "#";

        for(int i = 0; i < width; i ++)
        {
            bool flag = false;
            if(player.x == i && player.y == j){
                cout << "_";
                flag = true;
            }
            if(ball.x == i && ball.y == j){
                cout << "o";
                flag = true;
            }
            for(int k =0; k < nBlocks; k++){
                if(i == gameBlocks[k].positionX && j == gameBlocks[k].positionY && !gameBlocks[k].dead){
                    if(!flag){
                        cout << gameBlocks[k].blockImage;
                        flag = true;
                    }
                }
            }
            if(!flag)
                cout << " ";



        }
        cout << "#" << endl;

    }
    for(int i =0; i < width + 2; i ++)
        cout << "#";
    cout << "\nattempts : " << attempts << endl;

}

void Blocks(){
    //config the blocks
    for(int i =0; i < NBLOCKS ; i ++)
    {
        gameBlocks[i].positionX = 1 + rand() % (width - 2);
        gameBlocks[i].positionY = 1 + rand() % 3;


    }

}
void Input(){
    if(_kbhit()){
        switch(_getch())
        {


            case 27:
                play = false;
                break;
            case 'd':
                player.x+= 2;

                break;
            case 'a':
                player.x+= -2;
                break;
            case 'p':
                system("cls");
                cout << "\n\n\t\tPAUSE\n\n";
                cout << "Enter any key to continue";
                _getch();
                break;


            }
        }



    }

bool Logic(){

    //destroy the blocks

    for(int i =0; i < nBlocks; i++){
        if((gameBlocks[i].positionX == ball.x + 1 ||gameBlocks[i].positionX == ball.x - 1||gameBlocks[i].positionX == ball.x) && (gameBlocks[i].positionY == ball.y +1 || gameBlocks[i].positionY == ball.y -1 || gameBlocks[i].positionY == ball.y) && !gameBlocks[i].dead){
            //gameBlocks[i].dead = true;
            gameBlocks[i].life--;
            if(velBall[1] == 1)
                velBall[1] = -1;
            else
                velBall[1] = 1;
        }
    }
    //compar play blocks
    //ball move;
    if(ball.x < 1)
        velBall[0] = 1;
    if(ball.x > width -1)
        velBall[0] = -1;
    if(ball.y < 0)
        velBall[1] = 1;
    if(ball.y > height){
        ball.x = 5;
        ball.y = 5;
        attempts--;
    }
    ball.x +=velBall[0];
    ball.y +=velBall[1];


    if(attempts == 0)
        play = false;

    //player collision with wall
    if(player.x < 0)
        player.x = 0;
    if(player.x > height -1)
        player.x = height - 1;
    bool endGame = true;
    for(int i = 0; i < nBlocks; i++){
        if(!gameBlocks[i].dead && gameBlocks[i].life == 0)
            gameBlocks[i].dead = true;
        if(!gameBlocks[i].dead)
            endGame = false;
    }
    if(endGame)
        play = false;

    //player collision with ball
    if((player.x == ball.x || player.x == ball.x + 1|| player.x == ball.x -1 ) && player.y == ball.y){
        velBall[1] = -1;
        velBall[0] = 2 - rand() % 2;
    }
    return endGame;
}

int main()
{
    cout << "\n\n\t\tWelcome to Breakout\n\n";
    cout << "\t\tYou need to hit three times the block to break it\n";
    cout << "\t\t[ESC] EXIT [P]Pause\n";
    cout << "\t\t[a]Move left\t[d]Move right [p]Pause\n";
    cout << "Enter any key to start : ";
    _getch();

    srand(time(nullptr));
    Blocks();
    player.y = height -2;
    while(play){
        Input();
        Logic();
        Draw();
        Sleep(40);

    }
    system("cls");
    if(Logic())
        cout << "You win the Game\n";
    else
        cout << "You loose the game\n";
    _getch();
    return 0;
}
