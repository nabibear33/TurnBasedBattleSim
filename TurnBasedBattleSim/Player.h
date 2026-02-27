#pragma once

#include "Character.h"

class Player : public Character
{
private:
	
public:
	Player(int maxHp_, int hp_, int attackPower_);
	~Player();

};