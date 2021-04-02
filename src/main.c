#include <stdio.h>
#include <stdlib.h>

#include "Hero.h"

int main() {
  Hero *champions = (Hero*)malloc(MAX_CHAMPIONS * sizeof(Hero));

  //read Archmage data
  archmageInit(&champions[ARCHMAGE]);

  //read Death Knight data
  deathKnightInit(&champions[DEATH_KNIGHT]);

  //read Draw Ranger data
  drawRangerInit(&champions[DRAW_RANGER]);

  int commandsCount = 0;
  int currAction = 0;
  scanf("%d", &commandsCount);

  for (int i = 0; i < commandsCount; ++i) {
    scanf("%d", &currAction);
  }
  
  return EXIT_SUCCESS;
}
