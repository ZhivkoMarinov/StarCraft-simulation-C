#include <stdio.h>
#include <stdlib.h>
#include "Terran.h"
#include "Protoss.h"

BaseTerranShip *terranShipInit(int id, int type, int health){
    BaseTerranShip *terranShip = malloc(sizeof(BaseTerranShip));
    if(terranShip == NULL){
        printf("Failed to alloc memory!");
        exit(-1);
    }
    terranShip->health = health;
    terranShip->ID = id;
    terranShip->type = type;
    return terranShip;
}

void terranAttack(BaseTerranShip *currentShip, Vector *protossFleet, int round){
    int damage = 0;
    BaseProtossShip *enemy = vectorBack(protossFleet);
    if(currentShip->type == BATTLE_CRUSER){
        if(round % YAMATO_CANNON_LOADING_TURNS == 0){
            damage = BATTLE_CRUSER_DAMAGE * 5;
        }
        else{
            damage = BATTLE_CRUSER_DAMAGE;
        }
    }
    else{
        damage = (enemy->type == PHOENIX) ? VIKING_DAMAGE * 2 : VIKING_DAMAGE;
    }
    
    protossTakeDamage(enemy, damage, protossFleet);
}

void terranTakeDamage(BaseTerranShip *currentShip, int damage, Vector *terranFleet){
    if(currentShip->health > damage){
        currentShip->health -= damage;
        return;
    }
    currentShip->health = 0;
    free(currentShip);
    vectorPop(terranFleet);
}