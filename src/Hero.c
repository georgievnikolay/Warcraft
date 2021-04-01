#include "Hero.h"

char name[MAX_HERO_NAME_SIZE + 1];
int maxMana = 0;
int baseManaRegenRate = 0;
int manaRegenModifier = 0;

void heroSpellsInit(Hero *hero, const char *basicSpellName,
                    int basicSpellManaCost, const char *ultimateSpellName,
                    int ultimateSpellManaCost) {

    strcpy(hero->spells[0].name, basicSpellName);
    hero->spells[0].manaCost = basicSpellManaCost;
    strcpy(hero->spells[1].name, ultimateSpellName);
    hero->spells[1].manaCost = ultimateSpellManaCost;

                    }

void heroBaseInit(Hero *hero, const char *inputName, int inputMaxMana,
                    int inputManaRegenRate) {

    strcpy(hero->name, inputName);
    hero->maxMana = inputMaxMana;
    hero->currMana = inputMaxMana;
    hero->manaRegenRate = inputManaRegenRate;

                  }

void archmageInit(Hero *hero) {

    scanf("%s %d %d %d", name, &maxMana, &baseManaRegenRate, &manaRegenModifier);                    
    heroBaseInit(hero, name, maxMana, baseManaRegenRate * manaRegenModifier);
    heroSpellsInit(hero, ARCHMAGE_BASIC_SPELL_NAME, ARCHMAGE_BASIC_SPELL_MANA_COST, ARCHMAGE_ULTIMATE_SPELL_NAME, ARCHMAGE_ULTIMATE_SPELL_MANA_COST);

                  }

void deathKnightInit(Hero *hero) {

    scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);                    
    heroBaseInit(hero, name, maxMana, baseManaRegenRate);
    heroSpellsInit(hero, DEATH_KNIGHT_BASIC_SPELL_NAME, DEATH_KNIGHT_BASIC_SPELL_MANA_COST, DEATH_KNIGHT_ULTIMATE_SPELL_NAME, DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST);

                    }

void drawRangerInit(Hero *hero) {

    scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);                    
    heroBaseInit(hero, name, maxMana, baseManaRegenRate);
    heroSpellsInit(hero, DRAW_RANGER_BASIC_SPELL_NAME, DRAW_RANGER_BASIC_SPELL_MANA_COST, DRAW_RANGER_ULTIMATE_SPELL_NAME, DRAW_RANGER_ULTIMATE_SPELL_MANA_COST);
                        
                    }


// void deinit(Hero *hero) {
//   free(hero);
//   hero = NULL;
// }
