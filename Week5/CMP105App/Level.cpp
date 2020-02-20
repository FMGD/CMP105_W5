#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	//Adding Zombie
	zombTexture.loadFromFile("gfx/animZombie.png");
	zombie.setInput(in);
	zombie.setTexture(&zombTexture);
	zombie.setSize(sf::Vector2f(55, 108));
	zombie.setPosition(100, 100);

	//Adding Mario
	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	mario.setInput(in);
	mario.setTexture(&marioTexture);
	mario.setSize(sf::Vector2f(15*3, 21*3));
	mario.setPosition(200, 200);

	//Adding Doraemo
	doraemonTexture.loadFromFile("gfx/Doraemon.png");
	doraemon.setInput(in);
	doraemon.setTexture(&doraemonTexture);
	doraemon.setSize(sf::Vector2f(32*4, 32*4));
	doraemon.setPosition(300, 300);


}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	zombie.handleInput(dt);
	mario.handleInput(dt);
	doraemon.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	zombie.update(dt);
	mario.update(dt);
	doraemon.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(zombie);
	window->draw(mario);
	window->draw(doraemon);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}