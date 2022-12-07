#include "BattleField.h"
#include "Protoss.h"
#include "Terran.h"
#include "Vector.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void generateTerranFleet(BattleField *battleField, const char *terranFleetStr) {
  int stringLen = strlen(terranFleetStr);
  vectorInit(&(battleField->terranFleet), stringLen - 1);

  for(int i = 0; i < stringLen; i++){
    char ship = terranFleetStr[i];
    switch (ship){
    case 'b':
      BattleCruiser *newBattleCruiser = NULL;
      newBattleCruiser = battleCruiserInit(i);
      vectorPush(&(battleField->terranFleet), newBattleCruiser);
      break;      
    default:
      break;
    }
  }
}

void generateProtossFleet(BattleField *battleField, const char *protossFleetStr) {
  int stringLen = strlen(protossFleetStr);
  vectorInit(&(battleField->protossFleet), stringLen - 1);

  for (int i = 0; i < stringLen; i++){
    char ship = protossFleetStr[i];
    switch (ship){
    case 'c':
      Carrier *newCarrier = NULL;
      newCarrier = carrierInit(i);
      vectorPush(&(battleField->protossFleet), newCarrier);
      break;
    
    default:
      break;
    }
  }
}

// void startBattle(BattleField *battleField) {
//   while (true) {
//     if (processTerranTurn(battleField)) {
//       printf("TERRAN has won!\n");
//       break;
//     }

//     if (processProtossTurn(battleField)) {
//       printf("PROTOSS has won!\n");
//       break;
//     }
//   }
// }

// void deinit(BattleField *battleField) {
// }

// bool processTerranTurn(BattleField *battleField) {
//   return false;
// }

// bool processProtossTurn(BattleField *battleField) {
//   return false;
// }

