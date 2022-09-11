#include "Legenda.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//Konstruktor tworz¹cy tekstury legendy oraz daje jej pozycje
Legenda::Legenda()
{
	sprite.setPosition(sf::Vector2f(100, 461));
	texture.loadFromFile("Legenda.png");
	sprite.setTexture(texture);

}
//Rysowanie tekstury
void Legenda::draw(sf::RenderWindow* window)
{

	window->draw(sprite);


}