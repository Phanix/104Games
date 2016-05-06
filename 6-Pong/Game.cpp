#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<conio.h>
using namespace std;


const int width = 50;
const int height = 20;
char padPrint = '|';
struct pad{
    int x = 0;
    int y = height/2;

};
struct ballGame{
    int x;
    int y;
};
ballGame ball;
pad player2Pad;
pad playerPad;
//points
int p1Points = 0;
int p2Points = 0;

void draw(){
        for(int j =0; j < width +2; j++)
            cout << "-";
        cout << endl;
        for(int j =0; j < height; j++)
        {
            cout << "|";
            for(int i= 0 ; i<width;i++)
            {
                bool option = false;
                //ball
                if(i == ball.x && j == ball.y)
                {
                    cout << 'o';
                    option = true;
                }

                //end ball
                //player 2
                if(i == player2Pad.x && j == player2Pad.y)
                {
                    cout << padPrint;
                    option = true;
                }
                if(i == player2Pad.x && j == player2Pad.y + 1)
                {
                    cout << padPrint;
                    option = true;
                }
                //and player 2
                //player 1
                if(i == playerPad.x && j == playerPad.y){

                    cout << padPrint;
                    option = true;
                }
                else if(i == playerPad.x && j == playerPad.y + 1){
                    cout << padPrint;
                    option = true;
                }
                if(!option)
                        cout << " ";
            }
            cout << "|\n";

        }

        for(int j = 0; j < width + 2; j++)
            cout << "-";
        cout << endl;
        printf("Player 1 : %d Player 2 : %d", p1Points, p2Points);


    }
   int main()
{

    int velBall[] = {1,1};
    cout << "\n\n\tWelcome To Pong\n\n";
    cout << "Enter a key to Start [ESC]Exit [SPACE]Pause ";
    if(_getch() == 27)
        return 0;


    player2Pad.x = width - 2;
    player2Pad.y = player2Pad.y - 4;
    bool play = true;
    char key;
    bool kick = false;
    while(play){
        int velPlayer = 0;
        if(_kbhit())
        {
            key = _getch();

            if(key == 'w')
                velPlayer = -2;
            if(key == 's')
                velPlayer = 2;
            if(key == 32){
                system("cls");
                cout << "\n\n\t\tPause\n\n";
                cout << "Enter a key to continue";
                _getch();
            }
        }
        playerPad.y += velPlayer;
        //player 1 move

        //player 1 colision
        if(playerPad.y < 0)
            playerPad.y = 0;
        if(playerPad.y > height - 2)
            playerPad.y = height - 2;
        //////player 2 move

        //computer AI
        if(player2Pad.y > ball.y)
            player2Pad.y --;

        if(player2Pad.y  < ball.y)
            player2Pad.y ++;
        //computer AI colision
        if(player2Pad.y < 0)
            player2Pad.y = 0;
        if(player2Pad.y > height - 2)
            player2Pad.y = height - 2;
        //end computer

        //////ball move
        ball.x +=velBall[0];
        ball.y +=velBall[1];

        if(ball.y > height)
            velBall[1] = -1;
        if(ball.y == 0)
            velBall[1] = 1;
        if(ball.x == player2Pad.x && ball.y == player2Pad.y || ball.x == player2Pad.x && ball.y == player2Pad.y +1 )
            {
                velBall[0] = -1;
                cout << "\a";
            }
        if(ball.x == playerPad.x && ball.y == playerPad.y || ball.x == playerPad.x && ball.y == playerPad.y+1)
            {
                velBall[0] = 1;
                cout << "\a";
            }
        //make point
        if(ball.x > width +1){
            ball.x = width/2;
            velBall[0] = -1;
            p1Points++;
            cout << "\7";
            cout << "\7";

        }
        if(ball.x < -1){
            ball.x = width/2;
            velBall[0] = 1;
            p2Points++;
            cout << "\7";
            cout << "\7";

        }
        /////end ball move


        if(key == 27)
        {
            play = false;
            break;
        }
        system("cls");
        draw();
    }
    if(p1Points > p2Points){
        cout << "\n\nYou win The Game\n\n";
    }
    else if(p2Points > p1Points)
        cout << "\n\nSorry you loose\n\n";
    else
        cout << "\n\nTie\n\n";
    cout << "\n\nThanks to play\n\n";
    return 0;
}
