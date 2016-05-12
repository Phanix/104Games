#include<iostream>
#include<ctime>
#include<random>
#include<conio.h>
#include<cstdlib>
using namespace std;

/*

*/
//////variables

char key = ' ';
bool play = true;

//board
int array[3][3] = {{0,0,2},{2,2,0},{0,2,2}};

//points
int points = 0;

//print the board
void print()
{
    points =0;
    for(int y =0; y < 3 ;y ++){
        for(int x =0; x < 3; x++){
            cout << array[y][x] << "\t";
            points += array[y][x];
        }
        cout << endl;
    }
    cout << "\nPoints : "<<points << endl;
    cout << "\n\n";
}

void left()
{
   for(int x =0; x < 3 ; x++)
        if(array[x][2] == 0)
            array[x][2] = 2;
   for(int y =0; y < 3; y++){
        for(int x =0; x < 2 ; x++){
            if(array[y][x] == array[y][x+1] || array[y][x] == 0 && array[y][x+1] != 0 || array[y][x+1] == 0 && array[y][x] != 0){
                array[y][x] += array[y][x+1];
                array[y][x+1] = 0;
            }
        }
    }
}

void up()
{
     for(int x =0; x < 3 ; x++)
        if(array[2][x] == 0)
            array[2][x] = 2;
    for(int x =0; x < 3; x++){
        for(int y =0; y < 2 ; y++){
            if(array[y][x] == array[y+1][x] || array[y][x] == 0 && array[y+1][x] != 0 || array[y+1][x] == 0 && array[y+1][x] != 0){
                array[y][x] += array[y+1][x];
                array[y+1][x] = 0;
            }
        }
    }

}
void down()
{
     for(int i =0; i < 3 ; i++)
        if(array[0][i] == 0)
            array[0][i] = 2;
    for(int x =0; x < 3; x++){
        for(int y =1; y >= 0 ; y--){
            if(array[y][x] == array[y+1][x] || array[y][x] == 0 && array[y+1][x] != 0 || array[y+1][x] == 0 && array[y][x] != 0){
                array[y+1][x] += array[y][x];
                array[y][x] = 0;
            }
        }
    }

}

void right()
{
    for(int x =0; x < 3 ; x++)
        if(array[x][0] == 0)
            array[x][0] = 2;
    for(int y =0; y < 3; y++){
        for(int x =1; x >= 0 ; x--){
            if(array[y][x] == array[y][x+1] || array[y][x] == 0 && array[y][x+1] != 0 || array[y][x+1] == 0 && array[y][x] != 0){
                array[y][x+1] += array[y][x];
                array[y][x] = 0;
            }
        }
    }

}

void input()
{
    if(_kbhit()){
            key = _getch();
            if(key == 'w'){
                up();
            }
            if(key == 'a'){
                left();
            }
            if(key == 's'){
                down();
            }
            if(key == 'd'){
                right();
            }
            if(key == 27){
                play = false;
            }
            if(key == 32){
                system("cls");
                cout << "\n\n\t\tPause\n\n\t\t";
                cout << "\n\n\t\tEnter any  key to continue" << endl;
                _getch();
            }

        }

}
int main()
{

    cout << "\n\n\t\tWelcome to 2048 Game" << endl;
    cout << "\tEnter W to up ";
    cout << "S to down ";
    cout << "A to left ";
    cout << "D to right ";
    cout << "\n\tEnter any key to Start\n";
    _getch();
    while(play){
        system("cls");
        print();
        input();
        if(points == 2048){
                system("cls"); // clear the console
                cout << "\n\n\t\tWin The game\n\n\t\t";
                cout << "\n\n\t\tEnter any key to exit\n\n\t\t";
                _getch();
                play = false;
            }

    }
    return 0;
}
