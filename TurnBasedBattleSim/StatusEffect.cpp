#include <iostream>

#include "StatusEffect.h"
#include "Character.h"


StatusEffect::StatusEffect(int remainingTurns_) : remainingTurns(remainingTurns_) {}
StatusEffect::~StatusEffect() {}


void StatusEffect::OnTurnStart(Character& target) {}
void StatusEffect::OnExpire(Character& target) {}


void StatusEffect::DecrementTurn()
{
	remainingTurns--;
}


int StatusEffect::GetRemainingTurns()
{
	return remainingTurns;
}


bool StatusEffect::IsExpired() const
{ 
	return remainingTurns <= 0;
}


Poison::Poison(int remainingTurns_) : StatusEffect(remainingTurns_) {}

std::string Poison::GetName()
{
	return "Poisoned";
}


void Poison::Apply(Character& target)
{
	std::cout << "Get poisoned.\n";
}


void Poison::OnTurnStart(Character& target)
{
	target.TakeDamage(3);
}


Burn::Burn(int leftTurn_) : StatusEffect(leftTurn_) {}


std::string Burn::GetName()
{
	return "Burning";
}


void Burn::Apply(Character& target)
{
	std::cout << "Get burned.\n";
}


void Burn::OnTurnStart(Character& target)
{
	target.TakeDamage(5);
}


Stun::Stun(int leftTurn_) : StatusEffect(leftTurn_) {}


std::string Stun::GetName()
{
	return "Stunned";
}


void Stun::Apply(Character& target)
{
	std::cout << "Get stunned.\n";
}


void Stun::OnExpire(Character& target)
{
	target.SetIsStunned(false);
}