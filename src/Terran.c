#include <stdlib.h>
#include "Defines.h"
#include "Terran.h"

BattleCruiser *battleCruiserInit(int id){
    BattleCruiser *newBattleCruiser = malloc(sizeof(BattleCruiser));
    newBattleCruiser->yamatoCount = 0;
    newBattleCruiser->baseShip = malloc(sizeof(BaseTerranShip));
    newBattleCruiser->baseShip->health = BATTLE_CRUSER_HEALTH;
    newBattleCruiser->baseShip->ID = id;
    newBattleCruiser->baseShip->type = BATTLE_CRUSER;
    return newBattleCruiser;
}

Viking *vikingInit(int id){
    Viking *newViking = malloc(sizeof(Viking));
    newViking->damage_multiplyer = 2;
    newViking->baseShip = malloc(sizeof(BaseTerranShip));
    newViking->baseShip->health = VIKING_HEALTH;
    newViking->baseShip->ID = id;
    newViking->baseShip->type = VIKING;
    return newViking;
}
