#pragma once

#include "Character.h"

class Player : public Character
{
private:
	
public:
	Player(std::string name_, int hp_, int attackPower_);
	~Player();

};