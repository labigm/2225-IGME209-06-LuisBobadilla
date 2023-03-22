#include <iostream>
#include <GravitySnake.h>
#include <iomanip>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Functions.h"
using namespace std;

/* GravitySnake.h is the header file for a dynamically linked library (dll) called
* GravitySnake.dll. The GravitySnake library is a set of functions that satisfy the
* requirements of HW2 - Gravity Snake. In order to allow you to complete HW3 without
* the need for a done version of HW2, this DLL has been created. Using it's functions,
* you can implement HW3 without the HW2 code. A full breakdown of it's functions
* can be found in the homework document.
*/

int main()
{
	// Improves formatting of console output.
	cout << fixed << showpoint << setprecision(2);

	//Sets the possible bounds of where the target can spawn (-4, -4) to (4, 4) here.
	//This function is from the DLL.
	setTargetBounds(-4.0f, 4.0f, -4.0f, 4.0f);

	//Create the physics world, and all the objects. Return a pointer to the snake body.
	//These functions are from the DLL.
	initVariables(b2Vec2(0.0f, -9.8f));
	createFloor(b2Vec2(0.0f, -6.0f), 10.0f, 1.0f);
	createCeiling(b2Vec2(0.0f, 6.0f), 10.0f, 1.0f);
	createLeftWall(b2Vec2(-6.0f, 0.0f), 1.0f, 10.0f);
	createRightWall(b2Vec2(6.0f, 0.0f), 1.0f, 10.0f);
	b2Body* snake = createSnake(b2Vec2(0.0f, 5.0f), 0.5f, 0.5f);

	int targetsCollected = 0;

	while (targetsCollected < 2)
	{
		//This function advances the physics world by deltaTime, and returns the deltaTime in seconds.
		//This function is from the DLL.
		float deltaTime = updateWorldAndReturnDeltaTime();

		//Process input and apply forces to the snake.
		//This function is in Functions.h.
		handleInput();

		//Display the current target and snake positions.
		//This function is in Functions.h, and won't be used in the final HW3.
		display(snake);

		//This function checks if the snake is close to the target. It takes in a maximum collision distance.
		//This function is from the DLL.
		if (checkCollisionAndMoveTarget(0.5f))
		{
			targetsCollected++;
		}
	}

	//REMOVE THIS CODE when swapping to the SFML window
	cout << "Press escape to exit!" << endl;
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		//Get stuck in this loop til they hit escape
	}
	releaseVariables();


	/* The following block of code is from the SFML drawing tutorial. To accomplish
	* the requirements of HW3, you will need to take the code above and modify it
	* to work within the code provided below. Rather than using the display() method
	* like above, you will need to render shapes to represent the walls, snake, and
	* target.
	* 
	* Note, you should be creating your SFML shapes BEFORE the while (window.isOpen())
	* loop, then render them WITHIN the loop. Additionally, the while(targetsCollected < 2)
	* loop from up above will need to be turned into an if statement so that it doesn't
	* block SFML from rendering new frames to the window.
	*/

	/*
	
	sf::RenderWindow window(sf::VideoMode(800, 800), "Gravity Snake");

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);

		// end the current frame
		window.display();
	}
	*/
}