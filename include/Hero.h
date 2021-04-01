#ifndef HERO_H_
#define HERO_H_

#include "Defines.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SPELL_NAME_SIZE 20
#define MAX_HERO_NAME_SIZE 20
#define MAX_SPELLS 2
#define MAX_CHAMPIONS 3

typedef struct {
  char name[MAX_SPELL_NAME_SIZE];
  int manaCost;
} Spell;

typedef struct {
  Spell spells[MAX_SPELLS];
  char name[MAX_HERO_NAME_SIZE];
  int maxMana;
  int currMana;
  int manaRegenRate;
} Hero;

void heroBaseInit(Hero *hero, const char *inputName, int inputMaxMana,
                  int inputManaRegenRate);

void heroSpellsInit(Hero *hero, const char *basicSpellName,
                    int basicSpellManaCost, const char *ultimateSpellName,
                    int ultimateSpellManaCost);

void archmageInit(Hero *hero);

void deathKnightInit(Hero *hero);

void drawRangerInit(Hero *hero);

void deinit(Hero *hero);

#endif /* HERO_H_ */
