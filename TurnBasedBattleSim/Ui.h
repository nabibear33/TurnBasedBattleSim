#pragma once

#include "Types.h"

class Character;

class Ui
{
private:
public:
	void PrintSkillResult(const SkillInfo& result);
	void PrintLearnedSkills(Character& user);
	void PrintAvailableSkills(Character& user);
	void PrintStatusEffects(Character& user);
};