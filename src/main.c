#include <stdio.h>
#include <stdlib.h>

#include "BattleField.h"
#include "ProcessInput.h"

int main() {
  const int buffSize = 50;
  char terranFleet[buffSize];
  char protossFleet[buffSize];
  TakeInputData(terranFleet, protossFleet, buffSize);

  // BattleField battleField;
  // generateTerranFleet(&battleField, terranFleet);
  // generateProtossFleet(&battleField, protossFleet);
  // startBattle(&battleField);
  // deinit(&battleField);

  return EXIT_SUCCESS;
}
