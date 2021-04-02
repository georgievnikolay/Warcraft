#ifndef MANA_H_
#define MANA_H_

#include "HeroesInit.h"

bool hasEnoughMana(int currentMana , int manaCost);

void reduceMana(Hero *hero, SpellType spelltype);

void regenerateMana(Hero *hero);

#endif /* MANA_H_ */