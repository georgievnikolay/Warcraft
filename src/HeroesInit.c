#include "HeroesInit.h"

static char name[MAX_HERO_NAME_SIZE + 1];
static int maxMana = 0;
static int baseManaRegenRate = 0;
static int manaRegenModifier = 0;

void archmageInit(Hero *hero) {

    scanf("%s %d %d %d", name, &maxMana, &baseManaRegenRate, &manaRegenModifier);
    heroBaseInit(hero, name, maxMana, baseManaRegenRate * manaRegenModifier);
    heroSpellsInit(hero, ARCHMAGE_BASIC_SPELL_NAME, ARCHMAGE_BASIC_SPELL_MANA_COST, 
                   ARCHMAGE_ULTIMATE_SPELL_NAME, ARCHMAGE_ULTIMATE_SPELL_MANA_COST);
}

void deathKnightInit(Hero *hero) {

    scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
    heroBaseInit(hero, name, maxMana, baseManaRegenRate);
    heroSpellsInit(hero, DEATH_KNIGHT_BASIC_SPELL_NAME, DEATH_KNIGHT_BASIC_SPELL_MANA_COST, 
                   DEATH_KNIGHT_ULTIMATE_SPELL_NAME, DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST);
}

void drawRangerInit(Hero *hero) {

    scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
    heroBaseInit(hero, name, maxMana, baseManaRegenRate);
    heroSpellsInit(hero, DRAW_RANGER_BASIC_SPELL_NAME, DRAW_RANGER_BASIC_SPELL_MANA_COST, 
                   DRAW_RANGER_ULTIMATE_SPELL_NAME, DRAW_RANGER_ULTIMATE_SPELL_MANA_COST);
}

void deinit(Hero **hero) {
    free(*hero);
    (*hero) = NULL;
}