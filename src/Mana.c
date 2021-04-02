#include "Mana.h"

bool hasEnoughMana(int currentMana, int manaCost)
{

    if (currentMana >= manaCost)
        return true;

    return false;
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