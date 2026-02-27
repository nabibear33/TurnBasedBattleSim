#pragma once

class Character;

class StatusEffect
{
private:
public:
	virtual void Apply(Character& target) = 0;
	virtual void OnTurnStart(Character& target) = 0;
	virtual ~StatusEffect();
};


class Poison : public StatusEffect
{
private:
public:
	void Apply(Character& target) override;
	void OnTurnStart(Character& target) override;
};


class Burn : public StatusEffect
{
private:
public:
	void Apply(Character& target) override;
	void OnTurnStart(Character& target) override;
};


class Stun : public StatusEffect
{
private:
public:
	void Apply(Character& target) override;
	void OnTurnStart(Character& target) override;
};