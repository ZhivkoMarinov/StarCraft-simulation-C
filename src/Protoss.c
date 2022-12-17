#include <stdio.h>
#include <stdlib.h>
#include "Defines.h"
#include "Protoss.h"
#include "Terran.h"

BaseProtossShip *protossShipInit(int id, int type, int health, int shield, int shieldRegen){
    BaseProtossShip *protossShip = malloc(sizeof(BaseProtossShip));
    if(protossShip == NULL){
        printf("Failed to alloc memory!");
        exit(-1);
    }
    protossShip->health = health;
    protossShip->ID = id;
    protossShip->shield = shield;
    protossShip->shieldRegen = shieldRegen;
    protossShip->type = type;
    return protossShip;
}

void protossAttack(BaseProtossShip *currentShip, Vector *terranFleet){
    int damage = 0;
    BaseTerranShip *enemy = NULL;
    if(currentShip->type == CARRIER){
        damage = CARRIER_DAMAGE;
        int attacksCount = 0;
        attacksCount = (currentShip->health == CARRIER_HEALTH) ? 8 : 4;
        for(int i = 0; i < attacksCount; i++){
            enemy = vectorBack(terranFleet);
            terranTakeDamage(enemy, damage, terranFleet);
        }
    }
    else{
        damage = PHOENIX_DAMAGE;
        enemy = vectorBack(terranFleet);
        terranTakeDamage(enemy, damage, terranFleet);
    }
}

void protossTakeDamage(BaseProtossShip *currentShip, int damage, Vector *protossFleet){
    int total_dmg = currentShip->shield - damage;
    if(total_dmg >= 0){
        currentShip->shield = total_dmg;
        return;
    }
    currentShip->shield = 0;
    currentShip->health += total_dmg;
    if(currentShip->health <= 0){
        vectorPop(protossFleet);
    }
}

void shieldRegen(BaseProtossShip *lastShip){
    int maxShield = 0;
    maxShield = (lastShip->type == CARRIER) ? CARRIER_SHIELD : PHOENIX_SHIELD;
    lastShip->shield = (lastShip->shield + lastShip->shieldRegen > maxShield) ? maxShield : lastShip->shield + lastShip->shieldRegen;
}