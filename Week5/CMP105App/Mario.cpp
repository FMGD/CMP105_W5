#include "Mario.h"

// Constructor
Mario::Mario()
{
	velocity = sf::Vector2f(80.f, 80.f);

	//Setup walk animation
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 10.f);
	animations.push_back(&walk);

	//Setup swim animation
	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 10.f);
	animations.push_back(&swim);

	//Setup duck animation
	duck.addFrame(sf::IntRect(0, 41, 16, 20));
	duck.addFrame(sf::IntRect(16, 41, 16, 20));
	duck.setFrameSpeed(1.f / 10.f);
	animations.push_back(&duck);

}

// Destructor
Mario::~Mario()
{

}

// Functions
void Mario::update(float dt)
{
	/*for (int i = 0; i < animations.size(); i++)
	{
		if (animations[i]->getPlaying() == true)
			setTextureRect(animations[i]->getCurrentFrame());
	}*/
}

void Mario::handleInput(float dt)
{

	if (input->isKeyDown(sf::Keyboard::W)) //Swim up
	{
		move(0 * dt, -velocity.y * dt);
		setTextureRect(swim.getCurrentFrame());
		swim.animate(dt);	
	}
	else if (input->isKeyDown(sf::Keyboard::S)) //Swim down
	{
		move(0 * dt, velocity.y * dt);
		setTextureRect(swim.getCurrentFrame());
		swim.animate(dt);
	}

	if (input->isKeyDown(sf::Keyboard::A)) //Walk left
	{
		if (walk.getFlipped() == false) walk.setFlipped(true); // Flipped to left
		move(-velocity.x * dt, 0 * dt);
		setTextureRect(walk.getCurrentFrame());
		walk.animate(dt);
	}
	else if (input->isKeyDown(sf::Keyboard::D)) //Walk right
	{
		if (walk.getFlipped() == true) walk.setFlipped(false);  // Not Flipped to left
		move(velocity.x * dt, 0 * dt);
		setTextureRect(walk.getCurrentFrame());
		walk.animate(dt);
	}

	if (!input->isKeyDown(sf::Keyboard::W) && !input->isKeyDown(sf::Keyboard::S) && //If the player is stopped then duck
		!input->isKeyDown(sf::Keyboard::A) && !input->isKeyDown(sf::Keyboard::D))
	{
		setTextureRect(duck.getCurrentFrame());
		duck.animate(dt);
	}
}