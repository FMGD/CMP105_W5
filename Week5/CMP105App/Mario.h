#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include <vector>
#include <string>
#include <iostream>

class Mario : public GameObject
{
protected:

	std::vector<Animation*> animations;
	Animation walk;
	Animation swim;
	Animation duck;

public:

	// Constructor
	Mario();

	// Destructor
	~Mario();

	// Functions
	void update(float dt) override;
	void handleInput(float dt) override;

};

