#include <iostream>

#include "StatusEffect.h"
#include "Character.h"


StatusEffect::~StatusEffect() {}


void Poison::Apply(Character& target)
{
	std::cout << "Get poisoned.\n";
}


void Poison::OnTurnStart(Character& target)
{
	target.TakeDamage(3);
}


void Burn::Apply(Character& target)
{
	std::cout << "Get burned.\n";
}


void Burn::OnTurnStart(Character& target)
{
	target.TakeDamage(5);
}


void Stun::Apply(Character& target)
{
	std::cout << "Get stunned.\n";
}


void Stun::OnTurnStart(Character& target)
{
	
}