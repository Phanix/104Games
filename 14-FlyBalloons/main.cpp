//fly game
#include<cstdlib>
#include<random>
#include<conio.h>
#include<iostream>
#include<ctime>
#include<windows.h>
#include<cstdio>
#define NBALLS 15
using namespace std;

//variables
int nBalls =  15;
bool play = true;
int caught =0;
int lost = 0;
const int height = 20;
const int width = 20;
struct positions{
    int x =height;
    int y = height-1;
    char img = 'O';
    bool noMore = true;
};
struct player{
    int y = height - 1;
    int x = 2;
    char img = 'T';

};

player player1;
positions balls[NBALLS];

void Draw(){
    //draw the game
    system("cls");
    for(int i =0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    for(int j =0; j < height; j++){
        cout << "#";

        for(int i =0; i < width ; i++){
            bool flag = true;
            if(player1.x == i && player1.y == j){
                cout << "T";
                flag = false;
            }
            for(int k=0; k < nBalls; k++){
                if(balls[k].x == i && balls[k].y == j && !balls[k].noMore){
                    cout << balls[k].img;
                    flag = false;
                }


            }
            if(flag)
                    cout << " ";


        }
        cout << "#" << endl;

    }
     for(int i =0; i < width + 2; i++)
            cout << "#";
    printf("\nballoons : %d Lost : %d Caught : %d\n", nBalls, lost, caught);
}

int Input(){
    //command receive
    if(_kbhit()){
        switch(_getch()){
    case 27:
        play = false;
        break;
    case 32:
        player1.y-=3;
        break;

    case 77:
        player1.x++;
        return 2;
        break;
    case 75:
        player1.x--;
        return 1;
        break;
    case 'p':
        system("cls");
        cout << "\n\n\n\t\t\tPAUSE\n\n\n";
        cout << "\t\tEnter a key to continue\n";
        _getch();
        break;
    default:
        return 0;
        }

    }

}



int main()
{
    cout << "\n\n\t\tWelcome to fly to catch the balloons\n\n";
    cout << "\n\n\tTo control the [T] use Arrow keys left and right\n";
    cout << "\n\n\tEnter [P]To Pause [ESC]Exit\n";
    cout << "\n\n\tPress continuously [SPACE] to fly\n";
    cout <<"\nGood luck end Be careful with the wind , he takes the balloon Far away \n";
    cout << "\n\tEnter any key to start\n";
    _getch();

    int goBall = 0;
    balls[goBall].noMore = false;
    balls[goBall].x = 2 + rand() % 10;
    balls[goBall].y = 2 + rand() % 10;
    while(play){
        //random numbers positions
        if((balls[goBall].x == player1.x && balls[goBall].y == player1.y) || balls[goBall].x < 1 || balls[goBall].x > width-1){
            if(balls[goBall].x == player1.x && balls[goBall].y == player1.y)
                caught++;
            else
                lost++;
            balls[goBall].noMore = true;
            goBall++;
            balls[goBall].x = 3 + rand() % 15;
            balls[goBall].y = 3 + rand() % 15;
            balls[goBall].noMore = false;

            nBalls--;
        }
        if(nBalls == 0)
            play = false;
        //wind south
        if((1+rand() % 10) == 2){

            balls[goBall].x--;
            cout << "Sout wind" << endl;
        }
        //wind east
        if((rand() % 10) == 3){
            balls[goBall].x++;
            cout << "East wind" << endl;
        }
        //fly
        int teste = Input();
        if(player1.y < height-1){
            player1.y ++;
            if(teste == 2)
                player1.x++;
            if(teste == 1)
                player1.x--;
        }
        //player
        if(player1.x < 1)
            player1.x = 1;
        if(player1.x > width-1)
            player1.x = width-1;
        Draw();
        Sleep(50);


    }
    system("cls");
    if(lost > caught)
        cout << "you lost\n";
    else if(lost < caught)
        cout << "Ýou win\n";
    else
        cout << "Nobody wins\n";
    cout << "Thanks to play\n";

    return 0;
}

