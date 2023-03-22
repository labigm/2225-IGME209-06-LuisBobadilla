#include "Functions.h"
#include <iostream>
#include <GravitySnake.h>
#include <conio.h>
using namespace std;

void display(b2Body* snake)
{
	cout << "Target: (" << getTargetPosition().x << ", " << getTargetPosition().y << ")  ";
	cout << "Snake: (" << snake->GetPosition().x << ", " << snake->GetPosition().y << ")  " << endl;
}

void handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		applyForceToSnake(b2Vec2(0.0f, 100000.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		applyForceToSnake(b2Vec2(-10000.0f, 0.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		applyForceToSnake(b2Vec2(10000.0f, 0.0f));
	}
}
