#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_

#include <stdbool.h>

#include "Vector.h"

typedef struct {
  Vector terranFleet;
  Vector protossFleet;
} BattleField;

void generateTerranFleet(BattleField *battleField, const char *terranFleetStr);
void generateProtossFleet(BattleField *battleField, const char *protossFleetStr);
void startBattle(BattleField *battleField);
void deinit(BattleField *battleField);
bool processTerranTurn(BattleField *battleField, int round);
bool processProtossTurn(BattleField *battleField);
void deinit(BattleField *battleField);

#endif /* BATTLEFIELD_H_ */
