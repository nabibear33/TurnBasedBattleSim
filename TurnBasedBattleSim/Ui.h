#pragma once

#include "Types.h"

class Character;

class Ui
{
private:
public:
	void PrintSkillResult(const SkillInfo& result);
	void PrintLearnedSkills(const Character& user);
	void PrintAvailableSkills(const Character& user);
	void PrintStatusEffects(const Character& user);
};