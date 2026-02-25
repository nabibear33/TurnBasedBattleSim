# 7-Day C++ Object-Oriented Design Training
## Goal
Build a console-based Turn-Based Battle Simulator in C++.
The purpose is not to make a game, but to internalize object-oriented design,
polymorphism, separation of responsibility, and extensibility.

---

# Global Constraints

- Language: C++17 or later
- IDE: Visual Studio
- No game engine
- No external libraries
- No copying full solutions from LLM
- Focus: Design through iteration and refactoring

---

# Final Deliverable

A console-based battle simulator that:

- Supports Player and Monster
- Uses inheritance
- Uses at least one abstract class
- Uses polymorphism (virtual functions)
- Uses std::vector
- Uses smart pointers (std::unique_ptr)
- Supports extensibility (new skills/status effects without modifying core logic heavily)

---

# Day 1 – Basic Combat (Make It Work)

## Objective
Create a minimal working battle loop.

## Requirements
- Class: Character
  - hp
  - attackPower
  - TakeDamage()
  - IsDead()

- Class: Player (inherits Character)
- Class: Monster (inherits Character)

- Main loop:
  - While both alive
  - Player attacks
  - Monster attacks

## Focus
- Class separation
- Header / cpp file separation
- Encapsulation (private members)

## Output
A working console battle.

---

# Day 2 – Introduce Skill Abstraction

## Problem Statement
What if we have many skills?

## Requirements
- Abstract class: Skill
  - virtual void Activate(Character& user, Character& target) = 0;

- Derived classes:
  - BasicAttack
  - Fireball
  - Heal

- Player holds multiple skills

## Focus
- Polymorphism
- virtual functions
- Removing large if/else chains

## Output
Player selects skills dynamically.

---

# Day 3 – Dynamic Skill System

## Requirements
- Player owns:
  - std::vector<std::unique_ptr<Skill>>
- Add multiple skills dynamically
- Iterate skills using polymorphism

## Focus
- Smart pointers
- Ownership model
- Heap allocation
- Avoid raw new/delete

## Output
Extensible skill list system.

---

# Day 4 – Status Effect System (Design Stress Test)

## Problem Statement
Add status effects:
- Poison
- Burn
- Stun

## Requirements
- Abstract class: StatusEffect
  - virtual void Apply(Character& target)
  - virtual void OnTurnStart(Character& target)

- Character holds:
  - std::vector<std::unique_ptr<StatusEffect>>

## Focus
- Composition over conditionals
- Avoid massive if chains
- Separation of responsibilities

## Expected Difficulty
Code structure will likely break.
This is intentional.

---

# Day 5 – Refactoring Day

## Objective
Clean up design.

## Checklist
- Remove duplicated logic
- Reduce conditionals
- Clarify class responsibilities
- Improve naming
- Ensure adding a new skill requires minimal changes

## Focus
Understanding why refactoring improves extensibility.

---

# Day 6 – Feature Expansion Test

Add:

- Critical hit system
- Randomized damage
- Defense stat
- Turn-based status ticking

## Evaluation Question
Is adding features easy or painful?

If painful:
Design still weak.

---

# Day 7 – Design Reflection

## Write a design explanation document:

Answer:

1. Why is Skill abstract?
2. Why use virtual?
3. Why use unique_ptr?
4. Why use vector?
5. What would break without inheritance?
6. How would you add a new skill now?

## Final Test
Add a new skill in under 10 minutes.
If difficult → redesign needed.

---

# Learning Philosophy

- Build first
- Break structure
- Refactor
- Repeat

Object-oriented design is learned through structural pain,
not theoretical memorization.

---

# Success Criteria

You succeed if:

- You can extend the system without modifying core battle loop
- You understand why polymorphism reduces conditionals
- You can explain your architecture clearly
- You feel structural intuition improving

---

# After 7 Days

Only then:

- Move to Unreal Engine
- Map learned design principles to engine architecture
- Recognize similar structural patterns

---

End of Training Plan