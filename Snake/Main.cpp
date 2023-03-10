#include "Main.h"
/*
* This project in meant to show you the functionality of the Box2D library
*/

int main(void)
{
    std::cout << "This project in meant to show you the functionality of the Box2D library" << std::endl;
    b2Vec2 gravity(0.0, -9.8); //directional vector for gravity
    b2World world(gravity); //Space of simulation

    //Ground of the world
    b2BodyDef groundBodyDef; //floor
    sf::Vector2f floorSize(800.0f, 20.0f); //Size of the floor
    sf::Vector2f floorPos(0.0f, 0.0f); //Position of the floor
    groundBodyDef.position.Set(floorPos.x, floorPos.y); //Where in the world is located
    b2Body* groundBody = world.CreateBody(&groundBodyDef); //physics body for the ground
    b2PolygonShape groundBox;//Shape for this object
    groundBox.SetAsBox(floorSize.x / 2.0f, floorSize.y / 2.0f); //Half-width of the ground
    groundBody->CreateFixture(&groundBox, 0.0f);//fixed into the world density affects how the object reacts

    //Box in the world
    b2BodyDef boxDef; //object
    sf::Vector2f boxSize(20.0f, 20.0f); //Size of the box
    sf::Vector2f boxPos(100.0f, 100.0f); //Position of the box
    boxDef.type = b2_dynamicBody; //will it move?
    boxDef.position.Set(boxPos.x, boxPos.y); //position in the world
    b2Body* boxBody = world.CreateBody(&boxDef); //physics Body of the box
    b2PolygonShape dynamicBox;//Shape of this object
    dynamicBox.SetAsBox(boxSize.x / 2.0f, boxSize.y / 2.0f); //Half-width of the box
    b2FixtureDef fixtureDef; //fixture of the box
    fixtureDef.shape = &dynamicBox; //this is a movable object
    fixtureDef.friction = 0.3f; //friction will not really do anything for this application but this is an example
    boxBody->CreateFixture(&fixtureDef);

    b2Vec2 position; //position of the falling box
    sf::Clock deltaClock; //Clock to keep track of our frames
    sf::Time deltaTime; //time between frames

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            switch (event.type)
            {
            case sf::Event::Closed:
                    window.close();
                    break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::Space:
                    boxBody->ApplyForceToCenter(b2Vec2(0.0f, 10000.0f), true);
                    break;
                default:
                    break;
                }
            }
        }

        deltaTime = deltaClock.getElapsedTime();//check the time between frames
        deltaClock.restart(); //restart the clock to measure for the next frame
        world.Step(deltaTime.asSeconds(), 6, 2); //Simulate in real time
        position = boxBody->GetPosition(); //Get the position of the falling box
        std::cout << "(" << position.x << ", " << position.y << ")" << std::endl;

        // clear the window with black color
        window.clear(sf::Color::Black);

        sf::Vector2u dimensions = window.getSize();
        sf::Vector2f floorPosInv;
        floorPosInv.x = floorPos.x;
        floorPosInv.y = dimensions.y - floorPos.y - floorSize.y;
        
        // ground display
        sf::RectangleShape floor(floorSize);
        floor.setFillColor(sf::Color(250, 0, 0));
        floor.setPosition(floorPosInv);
        floor.setOutlineThickness(1);
        floor.setOutlineColor(sf::Color(255, 255, 255));
        window.draw(floor);

        // falling box display
        sf::RectangleShape box(boxSize);
        box.setFillColor(sf::Color(0, 0, 255));
        box.setPosition(sf::Vector2f(position.x, dimensions.y - position.y - boxSize.y));
        box.setOutlineThickness(1);
        box.setOutlineColor(sf::Color(255, 255, 255));
        window.draw(box);

        // end the current frame
        window.display();
    }

    return 0;
}