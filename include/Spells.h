#ifndef SPELLS_H_
#define SPELLS_H_
#include "Mana.h"

void archmageBasicSpell(Hero *archmage);

void deathKnightBasicSpell(Hero *deathKnight);

void drawRangerBasicSpell(Hero *drawRanger);

void archmageUltimateSpell(Hero *archmage);

void deathKnightUltimateSpell(Hero *deathKnight);

void drawRangerUltimateSpell(Hero *drawRanger);




bool hasCastedSpell(Hero *hero , SpellType spelltype, SpellCost cost);


void action(Hero *champion,ActionType currAction);

#endif /*SPELLS_H_*/