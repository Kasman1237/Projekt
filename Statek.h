#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "AnimatedSprite.h"
#include "planszaa.h"
class Ball :protected AnimatedSprite
{

public:
	Ball(sf::RenderWindow*);
	void swapp1();
	void swapp2();

	void draw(sf::RenderWindow* window);


	void Animate();
};

