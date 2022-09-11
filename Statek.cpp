#include "Statek.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
Ball::Ball(sf::RenderWindow* window)
{
	sprite.setPosition(sf::Vector2f(100, 20));
	texture.loadFromFile("Statek.png");
	sprite.setTexture(texture);

}


//Funkcja animacji statku zmieniaj¹c siê co ruch
void Ball::Animate()
{
	if (Frame == 1)
	{
		sprite.setTextureRect(sf::IntRect(0, 0, 100, 81));

	}
	else if (Frame == 2)
	{
		sprite.setTextureRect(sf::IntRect(100, 0, 100, 81));

	}

}
//zmiana Frame 
void Ball::swapp1()
{

	Frame = 2;


}
void Ball::swapp2()
{

	Frame = 1;

}
//Rysowanie animowanego statku
void Ball::draw(sf::RenderWindow* window)
{

	window->draw(sprite);


}