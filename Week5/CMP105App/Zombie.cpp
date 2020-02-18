#include "Zombie.h"

// Constructors
Zombie::Zombie()
{
	velocity = sf::Vector2f(80.f, 80.f);

	//Setup walk animation
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);

}

// Destructor
Zombie::~Zombie()
{

}

// Functions
void Zombie::update(float dt)
{
	setTextureRect(walk.getCurrentFrame());
}

void Zombie::handleInput(float dt)
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
