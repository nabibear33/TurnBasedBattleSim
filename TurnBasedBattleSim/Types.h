#pragma once

#include <string>


enum class SkillType
{
    DAMAGE,
    HEAL,
    BUFF
};


struct SkillInfo {
    SkillType type;
    std::string skillName;
    std::string casterName;
    std::string targetName;
    int value;
};