#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Zombie : public GameObject
{
protected:
	Animation walk;

public:
	// Constructors
	Zombie();

	// Destructor
	~Zombie();

	// Functions
	void update(float dt) override;
	void handleInput(float dt) override;

};

