#include <stdio.h>
#include <stdlib.h>
#include "Defines.h"
#include "Protoss.h"

Carrier *carrierInit(int id){
    Carrier *newCarrier = malloc(sizeof(Carrier));
    newCarrier->isHealthFull = true;
    newCarrier->baseShip = malloc(sizeof(BaseProtossShip));
    newCarrier->baseShip->health = CARRIER_HEALTH;
    newCarrier->baseShip->shield = CARRIER_SHIELD;
    newCarrier->baseShip->shieldRegen = CARRIER_SHIELD_REGENERATE_RATE;
    newCarrier->baseShip->ID = id;
    newCarrier->baseShip->type = CARRIER;
    return newCarrier;
}

Phoenix *phoenixInit(int id){
    Phoenix *newPhenix = malloc(sizeof(Phoenix));
    newPhenix->baseShip = malloc(sizeof(BaseProtossShip));
    newPhenix->baseShip->health = PHOENIX_HEALTH;
    newPhenix->baseShip->ID = id;
    newPhenix->baseShip->shield = PHOENIX_SHIELD;
    newPhenix->baseShip->shieldRegen = PHOENIX_SHIELD_REGENERATE_RATE;
    newPhenix->baseShip->type = PHOENIX;
    return newPhenix;

}