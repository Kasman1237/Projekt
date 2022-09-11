#ifndef STATKI_H
#define STATKI_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "planszaa.h"


using namespace std;


class CustomRectangleShape : public sf::RectangleShape {
public:
    int numer = 0;

    CustomRectangleShape(sf::Vector2f size, sf::Vector2f pos, int num)
        : RectangleShape(size)
    {
        setPosition(pos);
        numer = num;
    }
    void set_bound(float top, float bottom, float left, float right);
    bool game_status(string x, int s);
    bool selected();
    void select();
    bool if_inside(sf::Vector2i pos, sf::FloatRect rb);
private:
    bool is_selected = false;
    float top_b = 0;
    float bottom_b = 0;
    float left_b = 0;
    float right_b = 0;

};


#endif // STATKI_H
