#include "Hero.h"

char name[MAX_HERO_NAME_SIZE + 1];
int maxMana = 0;
int baseManaRegenRate = 0;
int manaRegenModifier = 0;

void heroSpellsInit(Hero *hero, const char *basicSpellName,
                    int basicSpellManaCost, const char *ultimateSpellName,
                    int ultimateSpellManaCost)
{

    strcpy(hero->spells[BASIC].name, basicSpellName);
    hero->spells[BASIC].manaCost = basicSpellManaCost;
    strcpy(hero->spells[ULTIMATE].name, ultimateSpellName);
    hero->spells[ULTIMATE].manaCost = ultimateSpellManaCost;
}

void heroBaseInit(Hero *hero, const char *inputName, int inputMaxMana,
                  int inputManaRegenRate)
{

    strcpy(hero->name, inputName);
    hero->maxMana = inputMaxMana;
    hero->currMana = inputMaxMana;
    hero->manaRegenRate = inputManaRegenRate;
}

void archmageInit(Hero *hero)
{

    scanf("%s %d %d %d", name, &maxMana, &baseManaRegenRate, &manaRegenModifier);
    heroBaseInit(hero, name, maxMana, baseManaRegenRate * manaRegenModifier);
    heroSpellsInit(hero, ARCHMAGE_BASIC_SPELL_NAME, ARCHMAGE_BASIC_SPELL_MANA_COST, ARCHMAGE_ULTIMATE_SPELL_NAME, ARCHMAGE_ULTIMATE_SPELL_MANA_COST);
}

void deathKnightInit(Hero *hero)
{

    scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
    heroBaseInit(hero, name, maxMana, baseManaRegenRate);
    heroSpellsInit(hero, DEATH_KNIGHT_BASIC_SPELL_NAME, DEATH_KNIGHT_BASIC_SPELL_MANA_COST, DEATH_KNIGHT_ULTIMATE_SPELL_NAME, DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST);
}

void drawRangerInit(Hero *hero)
{

    scanf("%s %d %d", name, &maxMana, &baseManaRegenRate);
    heroBaseInit(hero, name, maxMana, baseManaRegenRate);
    heroSpellsInit(hero, DRAW_RANGER_BASIC_SPELL_NAME, DRAW_RANGER_BASIC_SPELL_MANA_COST, DRAW_RANGER_ULTIMATE_SPELL_NAME, DRAW_RANGER_ULTIMATE_SPELL_MANA_COST);
}

void archmageBasicSpell(Hero *archmage)
{
    if (hasCastedSpell(archmage, BASIC, NOT_FREE))
    {
        reduceMana(archmage, BASIC);
    }
}
void deathKnightBasicSpell(Hero *deathKnight)
{
    if (hasCastedSpell(deathKnight, BASIC, NOT_FREE))
    {
        reduceMana(deathKnight, BASIC);
    }
}

void drawRangerBasicSpell(Hero *drawRanger)
{
    if (hasCastedSpell(drawRanger, BASIC, NOT_FREE))
    {
        reduceMana(drawRanger, BASIC);
        hasCastedSpell(drawRanger, BASIC, FREE);
    }
}
void archmageUltimateSpell(Hero *archmage)
{
    if (hasCastedSpell(archmage, ULTIMATE, NOT_FREE))
    {
        reduceMana(archmage, ULTIMATE);
        regenerateMana(archmage);
    }
}
void deathKnightUltimateSpell(Hero *deathKnight)
{
    if (hasCastedSpell(deathKnight, ULTIMATE, NOT_FREE))
    {
        reduceMana(deathKnight, ULTIMATE);
        hasCastedSpell(deathKnight, BASIC, FREE);
    }
}
void drawRangerUltimateSpell(Hero *drawRanger)
{
    if (hasCastedSpell(drawRanger, ULTIMATE, NOT_FREE))
    {
        reduceMana(drawRanger, ULTIMATE);
    }
}
bool hasEnoughMana(int currentMana, int manaCost)
{

    if (currentMana >= manaCost)
        return true;

    return false;
}

bool hasCastedSpell(Hero *hero, SpellType spelltype, SpellCost cost)
{
    if(cost) {
        printf("%s casted %s for 0 mana\n", hero->name, hero->spells[spelltype].name);
        return true;
    }
    if (hasEnoughMana(hero->currMana, hero->spells[spelltype].manaCost))
    {
        printf("%s casted %s for %d mana\n", hero->name, hero->spells[spelltype].name, hero->spells[spelltype].manaCost);
        return true;
    }
    else
    {
        printf("%s - not enough mana to cast %s\n", hero->name, hero->spells[spelltype].name);
        return false;
    }
    
}
void reduceMana(Hero *hero, SpellType spelltype)
{
    hero->currMana -= hero->spells[spelltype].manaCost;
}
void regenerateMana(Hero *hero)
{
    hero->currMana += hero->manaRegenRate;
    if (hero->currMana > hero->maxMana)
    {
        hero->currMana = hero->maxMana;
    }
}
void action(Hero *champion,ActionType currAction){
    switch (currAction)
    {
    case CAST_BASIC_SPELL:
        archmageBasicSpell(&champion[ARCHMAGE]);
        deathKnightBasicSpell(&champion[DEATH_KNIGHT]);
        drawRangerBasicSpell(&champion[DRAW_RANGER]);
        break;
    case CAST_ULTIMATE_SPELL:
        archmageUltimateSpell(&champion[ARCHMAGE]);
        deathKnightUltimateSpell(&champion[DEATH_KNIGHT]);
        drawRangerUltimateSpell(&champion[DRAW_RANGER]);
        break;
    case REGENERATE_MANA:
        regenerateMana(&champion[ARCHMAGE]);
        regenerateMana(&champion[DEATH_KNIGHT]);
        regenerateMana(&champion[DRAW_RANGER]);
        break;
    default:
        printf("Invalid command. No action executed\n");
        break;
    }
}
void deinit(Hero **hero)
{
    free(*hero);
    (*hero) = NULL;
}
