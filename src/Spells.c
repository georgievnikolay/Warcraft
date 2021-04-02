#include "Spells.h"

void archmageBasicSpell(Hero *archmage) {
    if (hasCastedSpell(archmage, BASIC, NOT_FREE)) {
        reduceMana(archmage, BASIC);
    }
}

void deathKnightBasicSpell(Hero *deathKnight) {
    if (hasCastedSpell(deathKnight, BASIC, NOT_FREE)) {
        reduceMana(deathKnight, BASIC);
    }
}

void drawRangerBasicSpell(Hero *drawRanger) {
    if (hasCastedSpell(drawRanger, BASIC, NOT_FREE)) {
        reduceMana(drawRanger, BASIC);
        hasCastedSpell(drawRanger, BASIC, FREE);
    }
}

void archmageUltimateSpell(Hero *archmage) {
    if (hasCastedSpell(archmage, ULTIMATE, NOT_FREE)) {
        reduceMana(archmage, ULTIMATE);
        regenerateMana(archmage);
    }
}

void deathKnightUltimateSpell(Hero *deathKnight) {
    if (hasCastedSpell(deathKnight, ULTIMATE, NOT_FREE)) {
        reduceMana(deathKnight, ULTIMATE);
        hasCastedSpell(deathKnight, BASIC, FREE);
    }
}

void drawRangerUltimateSpell(Hero *drawRanger) {
    if (hasCastedSpell(drawRanger, ULTIMATE, NOT_FREE)) {
        reduceMana(drawRanger, ULTIMATE);
    }
}


bool hasCastedSpell(Hero *hero, SpellType spelltype, SpellCost isFree) {
    if(isFree) {
        printf("%s casted %s for 0 mana\n", hero->name, hero->spells[spelltype].name);
        return true;
    }

    if (hasEnoughMana(hero->currMana, hero->spells[spelltype].manaCost)) {
        printf("%s casted %s for %d mana\n", hero->name, hero->spells[spelltype].name, hero->spells[spelltype].manaCost);
        return true;
    }
    else {
        printf("%s - not enough mana to cast %s\n", hero->name, hero->spells[spelltype].name);
        return false;
    }
}

void action(Hero *champion,ActionType currAction) {
    switch (currAction) {

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