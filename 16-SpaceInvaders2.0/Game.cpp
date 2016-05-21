#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstdio>
using namespace std;
#define COUNTER 10
#define BULLETS 100
//variables
int points = 0;
bool play = true;
bool shootStart = false;
int height = 20;
int width  =20;
bool endGame = false;
struct Point{
     char ship = '%';
     int _x = 100, _y = 100;
     int life = 10;
     bool go = false; //to not repeat the same bullet
};

struct Positions{
    int x;
    int y;
};
int counter =6;
Point boss;
Point enemies[COUNTER];
Point shooters[BULLETS];
Positions player;
int bullets =0;
enum Colors { blue=1, green, cyan, red, purple, yellow, grey, dgrey, hblue, hgreen, hred, hpurple, hyellow, hwhite };
char ColorChar(char ch, int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout << ch;
}

void Draw(){
    system("cls");
    for(int i =0; i < width + 2 ; i++)
         ColorChar('-', blue);
    cout << "\n";
    for(int j = 0; j < height ; j++){
        ColorChar('|', blue);
        for(int i =0;i<width; i++){
            bool flag = false;
            if(i == player.x && j == player.y)
                ColorChar('U', yellow);
            else if(i == boss._x && j == boss._y)
                ColorChar('B', red);

            else{
            for(int k =0; k < counter ; k++){
                if( i == enemies[k]._x && j == enemies[k]._y){
                    ColorChar(enemies[k].ship, green);

                    flag= true;
            }
             }

            for(int z =0; z <bullets;z++){
                if(i == shooters[z]._x && j == shooters[z]._y){
                    cout << "|";
                    flag = true;
                }
            }



            if(!flag)
                cout <<" ";
            }
        }
         ColorChar('|', blue);
        cout << "\n";

    }
    for(int i =0; i < width  + 2; i++)
         ColorChar('-', blue);
    cout << "\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), hwhite);
    printf("Boss life %d bullets remainder : %d", boss.life, 50 - bullets);


}
void Update(){

    for(int i =0; i < counter; i++)

        {
            if(enemies[i]._x > 19){
                enemies[i]._x = 0;
                enemies[i]._y++;
        }
        else
            enemies[i]._x ++;

        }
    for(int u = 0; u < bullets; u++){
        if(!shooters[u].go){
            shooters[u]._x = player.x;
            shooters[u]._y = player.y;
            shooters[u].go = true;

        }

    }
    for(int u = 0; u < bullets; u++){

           shooters[u]._y--;



    }


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
        case 's':
             player.y++;
             break;
        case 'w':
            player.y--;
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
            break;

        }
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
            cout << "\a";
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
    for(int i =0; i < counter ; i++){
        if(enemies[i]._y < 0)
            restartEnemies = true;
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
void Start(){
    cout << "\n\n\t\tWelcome To SpaceInvaders 2.0\n\n\t\t";
    cout << "\n\n\t\tTo control the ship use\n";
    cout << "\n[w] UP [s] DOWN [d] RIGHT [a] LEFT\n";
    cout << "\n\t[k] Shot [p] Pause\n\n";
    cout << "\n\n\t\tTo win the game kill 10 times the boss , GOOD LUCK\n";
    cout << "\n\n\t\tEnter any key to start\n";
    _getch();
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
}
int main()
{
   Start();
    while(play){
        Input();
        Update();
        Logic();
        Draw();
    }
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), hwhite);
    if(boss.life == 0){
        cout << "\n\tYou Win the Game\n" ;
    }
    else
        cout << "\n\tYou loose the Game\n";
    cout << "Thanks to play";
    _getch();
    return 0;
}
