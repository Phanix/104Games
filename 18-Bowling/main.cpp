#include <iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
#define NPINS 10
//struct for the positions
struct positions{
    int x;
    int y;
    bool down = false;
};
/////variables
 bool hasPin = false;
int nBall = 10;
bool play = true;
bool runBall = false;
int pinsUp = NPINS;
positions pins[NPINS];
positions player;
positions ball;
const int height = 10;
const int width  = 50;

char ColorChar(char ch, int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout << ch;
}


void Draw(){
    //clear the scream
    system("cls");
    cout << "  ";
    for(int i = 0; i < width -2; i++)
        ColorChar('-', 4);
    cout << endl;
    for(int j =0; j < height;j++){
        ColorChar('|', 4);

        for(int i =0; i < width ;i++){
                bool flag = false;
            for(int k =0; k < 10; k++){
                if(pins[k].x == i && pins[k].y == j && !pins[k].down){
                    ColorChar('o', 3);
                    flag = true;
                }
            }
            if(player.x == i && player.y == j && flag == false){
                ColorChar('&', 2);
                flag = true;
            }
            if(ball.x == i && ball.y == j){
                ColorChar('o', 3);
                flag = true;
            }
            if(!flag)
                cout << " ";
        }
        ColorChar('|', 4);

        cout << endl;
    }

    for(int i = 0; i < width; i++)
        ColorChar('-', 4);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << endl;
    cout << "Ball : " << nBall << endl;
}
void Input(){
    if(_kbhit()){
        switch(_getch()){
        case 27:
            play = false;
            break;
        case 72:
            player.y--;
            break;
        case 80:
            player.y++;
            break;
        case 32:
            if(runBall == false){
                ball.x = player.x +1;
                ball.y = player.y;
                runBall = true;
                nBall--;
            }
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
void Initialize(){
    cout << "\n\n\t\tWelcome to Simple Bowling\n";
    cout << "\n\n\tUse Arrows keys to move and Space to throw the ball\n";
    cout << "\n\tEnter any key Start\n";
    cout << "\n\[ESC]EXIT [P]PAUSE\n";
    if(_getch() == 27)
        play = false;
    /////set pins positions
    pins[0].x = 38;
    pins[0].y = 4;
    //line 2
    //pin 2
    pins[1].x = 39;
    pins[1].y = 3;
    //pin3
    pins[2].x = 39;
    pins[2].y = 5;
    ////line 3
    //pin
    pins[3].x = 40;
    pins[3].y = 2;
    //pin5;
    pins[4].x = 40;
    pins[4].y = 4;
    //pin6
    pins[5].x = 40;
    pins[5].y = 6;
    ////line 4;
    //pin7
    pins[6].x = 41;
    pins[6].y = 1;
    //pin8 *
    pins[7].x = 41;
    pins[7].y = 3;
    //pin9 *
    pins[8].x = 41;
    pins[8].y = 5;
    // *
    pins[9].x = 41;
    pins[9].y = 7;

    //player init
    player.x = 5;
    player.y = height /2;

}
void Logic(){
    hasPin = true;
    for(int i =0; i < pinsUp; i++){

        if(pins[i].x == ball.x && pins[i].y == ball.y){
            pins[i].down = true;

            if(i < NPINS/2){
                pins[i].y++;
                pins[i].x++;
            }
            else{
                pins[i].y--;
                pins[i].x++;
            }
           for(int k =0; k < pinsUp; k++){
                if(pins[k].x == pins[i].x && pins[k].y == pins[i].y){
                        pins[k].down = true;

                        if(i < NPINS/2){
                            pins[k].y++;
                            pins[k].x++;
                            }
                        else{
                            pins[k].y--;
                            pins[k].x++;
                            }
                }
           }
        }
    if(!pins[i].down)
        hasPin = false;

    }

    if(runBall == true)
        ball.x++;
    if(ball.x > width)
        runBall = false;

    if(hasPin || nBall == 0)
        play = false;
    }



int main()
{
    Initialize();
    while(play){

        Input();
        Logic();
        Draw();
    }
    if(hasPin)
        cout << "You Win The Game\n";
    else
        cout << "You Loose The Game\n";
    cout << "Thanks to Play\n";

    return 0;
}
