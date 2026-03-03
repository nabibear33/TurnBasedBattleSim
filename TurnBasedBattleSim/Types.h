#pragma once

#include <string>


enum class SkillType
{
    DAMAGE,
    HEAL,
    BUFF
};


struct SkillInfo
{
    SkillType type;
    std::string skillName;
    std::string casterName;
    std::string targetName;
    bool isCritical;
    int value;
};


struct DamageResult
{
    int damage;
    bool isCritical;
};