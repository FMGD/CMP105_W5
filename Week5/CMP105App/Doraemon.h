#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Doraemon :	public GameObject
{
protected:
	Animation walk;

public:
	// Constructors
	Doraemon();

	// Destructor
	~Doraemon();

	// Functions
	void update(float dt) override;
	void handleInput(float dt) override;

};

