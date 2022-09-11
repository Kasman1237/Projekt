// Kolokwium.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Statek.h"
#include "planszaa.h"
#include "AnimatedSprite.h"
#include "statki.h"
#include "Legenda.h"
#include <ctime>
using namespace std;
int main() {
    // create the window
    bool x = true;
    int s1 = 0;
    int s2 = 0;
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Statki");
    //Tworzenie tablicy ze statkami
    plansza stat2(1);
    Ball ball(&window);
    Legenda Legenda;


    //Tworzenie planszy ze statkami bota
    std::vector<CustomRectangleShape> rectangles;

    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++)
        {
            sf::Vector2f size(20.0, 20.0);
            sf::Vector2f position(i * 31 + 300, j * 31 + 30);

            rectangles.emplace_back(CustomRectangleShape(size, position, stat2.T[i][j]));
        }
    }
    //Tworzenie tablicy ze statkami
    for (auto& rec : rectangles) {
        rec.setFillColor(sf::Color(0, 0, 255));
        rec.set_bound(0.5, window.getSize().y + 0.5, 0.5, window.getSize().x + 0.5);
    }
    //Tworzenie planszy ze statkami gracza
    std::vector<CustomRectangleShape> rectanglesbot;
    plansza statbot(2);
    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++)
        {
            sf::Vector2f size(20.0, 20.0);
            sf::Vector2f position(i * 31 + 300, j * 31 + 30 + 400);
            rectanglesbot.emplace_back(CustomRectangleShape(size, position, statbot.T[i][j]));
        }
    }

    for (auto& rec2 : rectanglesbot) {
        rec2.setFillColor(sf::Color(0, 0, 255));
        rec2.set_bound(0.5, window.getSize().y + 0.5, 0.5, window.getSize().x + 0.5);

    }





    while (window.isOpen()) {


        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed) {
                std::cout << "Closing Window" << std::endl;
                window.close();
            }
            //Strzały gracza
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                ball.swapp1();
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                for (auto& rec : rectangles)
                {
                    //Pozycje trafione przy strzale
                    sf::FloatRect rec_bound = rec.getGlobalBounds();
                    if (rec.if_inside(mouse_pos, rec_bound) == true && rec.numer <= 4 && rec.numer >= 1 && rec.selected() == false)
                    {
                        rec.select();
                        rec.setFillColor(sf::Color(255, 0, 0));
                        s2++;

                        x = false;

                    }
                    //Pokazanie pozycji nie trafionych
                    if (rec.if_inside(mouse_pos, rec_bound) == true && (rec.numer >= 5 || rec.numer <= 0) && rec.selected() == false)
                    {
                        rec.select();
                        rec.setFillColor(sf::Color(234, 221, 202));
                        x = false;
                    }
                    //Zakonczenie wygrana Gracza
                    if (rec.game_status("Gracz", s2))
                    {
                        return 0;
                    }
                }
            }

        }

        ball.Animate();
        //Losowanie przez bota strzału 
        for (auto& rec2 : rectanglesbot)
        {

            if (x == false)
            {   //Losowanie elementu ktory bedzie strzelony
                int y = 1;
                int ran = rand() % 100 + 1;
                //Pokazanie pozycji  trafionych
                if (rec2.numer <= 4 && rec2.numer >= 1 && rec2.selected() == false && y == ran
                    )
                {
                    rec2.select();
                    rec2.setFillColor(sf::Color(255, 0, 0));
                    x = true;
                    s1++;


                }
                //Pokazanie pozycji nie trafionych
                if ((rec2.numer >= 5 || rec2.numer <= 0) && rec2.selected() == false && y == ran)
                {
                    rec2.select();
                    rec2.setFillColor(sf::Color(234, 221, 202));
                    x = true;
                }
                y++;
            }
            ball.swapp2();
            //Zakonczenie wygrana bota
            if (rec2.game_status("Bot", s1))
            {
                return 0;
            }
        }



        window.clear(sf::Color::White);


        for (const auto& rec : rectangles)
        {
            window.draw(rec);
        }
        for (const auto& rec2 : rectanglesbot)
        {
            window.draw(rec2);
        }
        ball.draw(&window);
        Legenda.draw(&window);


        window.display();
    }

    return 0;
}



