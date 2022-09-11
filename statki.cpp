#include "statki.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

using namespace std;

void CustomRectangleShape::set_bound(float top, float bottom, float left, float right) {
    top_b = top;
    bottom_b = bottom;
    left_b = left;
    right_b = right;
}
//Zwracanie wartoœci czy statek jest wybrany
bool CustomRectangleShape::selected()
{
    if (is_selected == true)
    {
        return true;
    }
    else
    {
        return false;
    }

}
//Zwracanie czy kursor myszki jest w granicy statku
bool CustomRectangleShape::if_inside(sf::Vector2i pos, sf::FloatRect rb)
{
    if ((pos.x <= (rb.left + rb.width)) && (pos.x >= rb.left) && (pos.y <= (rb.top + rb.height)) && (pos.y >= rb.top))
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Zaznaczanie 
void CustomRectangleShape::select()
{
    is_selected = true;

}
//Funkcja do koñczenia gry 
bool  CustomRectangleShape::game_status(string x, int s) {
    if (s == 20) {
        std::cout << x << " wygra³";
        return 1;
    }
    return 0;
}



