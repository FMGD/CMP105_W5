#include "Doraemon.h"

// Constructors
Doraemon::Doraemon()
{
	velocity = sf::Vector2f(80.1f, 80.1f);

	//Setup walk animation
	walk.addFrame(sf::IntRect(0, 0, 32, 32)); // Each Doraemon frame is 32 * 96 px
	walk.addFrame(sf::IntRect(32, 0, 32, 32)); // IntRect(desplacement-x, desplacement-y, 32, 96)
	walk.addFrame(sf::IntRect(64, 0, 32, 32));
	walk.setFrameSpeed(1.f / 10.f);

}

// Destructor
Doraemon::~Doraemon()
{

}

// Functions
void Doraemon::update(float dt)
{
	setTextureRect(walk.getCurrentFrame());
}

void Doraemon::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		move(0 * dt, -velocity.y * dt);
		walk.animate(dt);
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		move(0 * dt, velocity.y * dt);
		walk.animate(dt);
	}
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		if (walk.getFlipped() == false) walk.setFlipped(true); // Flipped to left
		move(-velocity.x * dt, 0 * dt);
		walk.animate(dt);
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		if (walk.getFlipped() == true) walk.setFlipped(false);  // Not Flipped to left
		move(velocity.x * dt, 0 * dt);
		walk.animate(dt);
	}

}

