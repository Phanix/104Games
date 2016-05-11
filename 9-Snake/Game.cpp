#include<iostream>
#include<ctime>
#include<random>
#include<cstdio>
#include<conio.h>
#include<windows.h>
using namespace std;
const int width = 30;
const int height = 20;
int vel[] = {0, 0};
struct position{
    int x =width / 2;
    int y =height / 2;
};
int points = 0;
int level = 1;
bool play = true;
position fruit;
position player;

//test tail
int tailX[100], tailY[100];
int nTail;
//end teste tail
void draw()
{
    system("cls");
    for(int i = 0; i < width +2 ; i ++ )
        cout << "#";
    cout << endl;

    for(int i =0; i < height ; i++)
    {
        cout << "#";
        for(int j =0; j < width ; j++)
        {
            if(i == player.y && j == player.x)
                cout << "O";
            else if(i == fruit.y && j == fruit.x)
                cout << "&";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
        }
        cout << "#";
        cout << endl;
    }


     for(int i = 0; i < width +2 ; i ++ )
        cout << "#";
    cout << endl;
    printf("Points : %d\tLevel : %d\n", points,level);

}
void add_vel()
{
    player.x +=vel[0];
    player.y +=vel[1];
}
void Input()
{
    if(_kbhit())
    {
        char key = _getch();


        if(key == 'd'){
            vel[0] = 1;
            vel[1] = 0;
        }
        if(key == 's'){
            vel[1] = 1;
            vel[0] = 0;
        }
        if(key == 'a'){
            vel[0] = -1;
            vel[1] = 0;
        }
        if(key == 'w'){
            vel[1] = -1;
            vel[0] = 0;
        }
        if(key == 't'){
            vel[0] = 0;
            vel[1] = 0;
        }
    }
}
void logic(){
    //logic for tail
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = player.x;
    tailY[0] = player.y;

    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    //end logic tail
    if(player.x >= width)
        player.x = 0;
    if(player.x < 0)
        player.x = width - 1;
    if(player.y >= height)
        player.y = 0;
    if(player.y < 0)
        player.y = height -1;
    if(player.x == fruit.x && player.y == fruit.y)
    {
        points +=1;
        level = points / 3;
        fruit.x = 2 + rand() % width - 2;
        fruit.y = 2 + rand() % height - 2;
        nTail++;

    }

    for(int i =0 ; i < nTail ;i++)
        if(tailX[i] == player.x && tailY[i] == player.y)
                play = false;


    if(level == 10)
        play = false;
}
int main()
{
    fruit.x = 2 + rand() % width - 2;
    fruit.y = 2 + rand() % height - 2;
    while(play){
        Sleep(100 - level * 10);
        Input();
        logic();
        add_vel();
        draw();
    }
    if(level == 10)
        cout << "\n\n\t\tYou win the game\n\n\t\t";
    cout << "Thanks to play" << endl;
    return 0;
}
