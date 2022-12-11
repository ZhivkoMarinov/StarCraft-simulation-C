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
    BaseTerranShip *newTerranShip = NULL;

    switch (ship){
    case 'b':
      newTerranShip = terranShipInit(i, BATTLE_CRUSER, BATTLE_CRUSER_HEALTH);
      vectorPush(&(battleField->terranFleet), newTerranShip);
      break;
    case 'v':
      newTerranShip = terranShipInit(i, VIKING, VIKING_HEALTH);
      vectorPush(&(battleField->terranFleet), newTerranShip);
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
    BaseProtossShip *newProtossShip = NULL;

    switch (ship){
    case 'c':
      newProtossShip = protossShipInit(i, CARRIER, CARRIER_HEALTH, CARRIER_SHIELD, CARRIER_SHIELD_REGENERATE_RATE);
      vectorPush(&(battleField->protossFleet), newProtossShip);
      break;
    case 'p':
      newProtossShip = protossShipInit(i, PHOENIX, PHOENIX_HEALTH, PHOENIX_SHIELD, PHOENIX_SHIELD_REGENERATE_RATE);
      vectorPush(&(battleField->protossFleet), newProtossShip);
      break;    
    default:
      break;
    }
  }
}

void startBattle(BattleField *battleField) {
  int round = 1;
  while (true) {
    if (processTerranTurn(battleField, round)) {
      printf("TERRAN has won!\n");
      break;
    }

    if (processProtossTurn(battleField)) {
      printf("PROTOSS has won!\n");
      break;
    }
    round++;
  }
}

bool processTerranTurn(BattleField *battleField, int round){
  int fleetSize = battleField->terranFleet.size;
  for(int ship = 0; ship < fleetSize; ship++){
    BaseTerranShip *currentShip = vectorGet(&(battleField->terranFleet), ship);
    terranAttack(currentShip, &(battleField->protossFleet), round);

    if(battleField->protossFleet.size == 0){
      return true;
    }
  }
  return false;
}

bool processProtossTurn(BattleField *battleField){
  //regenerate shield
  BaseProtossShip *lastShip = vectorBack(&(battleField->protossFleet));
  shieldRegen(lastShip);

  //proccess attacks
  int fleetSize = battleField->protossFleet.size;
  for(int ship = 0; ship < fleetSize; ship++){
    BaseProtossShip *currentShip = vectorGet(&(battleField->protossFleet), ship);
    protossAttack(currentShip, &(battleField->terranFleet));

    if(battleField->protossFleet.size == 0){
      return true;
    } 
  }
  return false;
}

// void deinit(BattleField *battleField) {
// }

// bool processProtossTurn(BattleField *battleField) {
//   return false;
// }

