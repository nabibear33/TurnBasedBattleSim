#pragma once

class Character;

class StatusEffect
{
private:
	int remainingTurns;
public:
	StatusEffect(int leftTurn_);
	virtual std::string GetName() = 0;
	virtual void Apply(Character& target) = 0;
	virtual void OnTurnStart(Character& target);
	virtual void OnExpire(Character& target);
	void DecrementTurn();
	int GetRemainingTurns();
	bool IsExpired() const;
	virtual ~StatusEffect();
};


class Poison : public StatusEffect
{
private:
public:
	Poison(int leftTurn_);
	std::string GetName() override;
	void Apply(Character& target) override;
	void OnTurnStart(Character& target) override;
};


class Burn : public StatusEffect
{
private:
public:
	Burn(int leftTurn_);
	std::string GetName() override;
	void Apply(Character& target) override;
	void OnTurnStart(Character& target) override;
};


class Stun : public StatusEffect
{
private:
public:
	Stun(int leftTurn_);
	std::string GetName() override;
	void Apply(Character& target) override;
	void OnExpire(Character& target) override;
};