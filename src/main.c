#include <stdio.h>
#include <stdlib.h>

#include "Hero.h"

int main() {
  Hero *champions = (Hero*)malloc(MAX_CHAMPIONS * sizeof(Hero));

  //read Archmage data
  archmageInit(&champions[0]);

  //read Death Knight data
  deathKnightInit(&champions[1]);

  //read Draw Ranger data
  drawRangerInit(&champions[2]);

  int commandsCount = 0;
  int currAction = 0;
  scanf("%d", &commandsCount);

  for (int i = 0; i < commandsCount; ++i) {
    scanf("%d", &currAction);
  }
  
  // for (int i = 0; i < MAX_CHAMPIONS; i++) {
  //   deinit((champions + i));
  // }
  return EXIT_SUCCESS;
}
