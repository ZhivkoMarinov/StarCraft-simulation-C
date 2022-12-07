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