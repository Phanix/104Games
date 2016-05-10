
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include<random>>
#include<ctime>
#include<windows.h>
#include<iostream>
#include<sstream>


int main()
{
    //variables
    const int width = 500;
    const int height = 500;
    float levelAdd = 3.0f;
    int level = 0;
    int points = 0;
    //font
    sf::Font font;
    if(!font.loadFromFile("Data/avaria.ttf"))
        return 0;

    //Sound
    sf::SoundBuffer hit;
    if(!hit.loadFromFile("Data/hit.wav")){
        return 0;
    }
    sf::Sound hitZombie;
    hitZombie.setBuffer(hit);
    //end sound
    //title
    sf::Text title;
    title.setFont(font);
    title.setPosition(150, 10);
    title.setCharacterSize(20);
    title.setString("Zombie Shooter Game");
    //end title

    //score
    sf::Text score;
    score.setFont(font);
    score.setPosition(10, height - 50);
    score.setString("Points : 0 Level : 0 ");
    //end score
    sf::Clock clock;
    srand(time(0));

    //rectangle for zombie sprite
    sf::RenderWindow window(sf::VideoMode(width, height), "zombie");
    sf::RectangleShape zombie;
    zombie.setSize(sf::Vector2f(50, 50));
    zombie.setPosition(10, 10);
    //end rectangle

    sf::Texture image1;
    if(!image1.loadFromFile("Data/zombie.png"))
        return 0;
    zombie.setTexture(&image1);
    int count_event =0;
    bool play = true;
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
           if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (zombie.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                {
                    points+=1;
                    zombie.setPosition(50 +  rand() % 400 ,50 +  rand() % 400);
                    hitZombie.play();
                }
            }


        }


        //up level and add velocity to sprite
        if(points == 10){
            points = 0;
            level+=1;
            if(levelAdd > 1.0)
                levelAdd -=0.5;
        }
        if(level == 5)
            play = false;
        //random sprite location
        if(clock.getElapsedTime().asSeconds() > levelAdd){

            //postion less/plus zombie size
            zombie.setPosition(50 +  rand() % 400 ,50 +  rand() % 400);
            clock.restart();

        }
        if(play){
        window.clear();
        window.draw(zombie);
        window.draw(title);
        //score
        std::stringstream text;

        text << "Points : " <<points << " Level :  " << level;

        score.setString(text.str());
        window.draw(score);
        window.display();
        }
        else{
            window.clear();
            title.setString("End Game Thanks to play");
            window.draw(title);
            window.display();
            Sleep(2000);
            return 0;
        }
    }

    return 0;
}
