#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ProcessInput.h"

void TakeInputData(char *terranFleet, char *protossFleet, int buffsize){
    char terran[buffsize];
    char protoss[buffsize];

    fgets(terran, buffsize, stdin);
    fgets(protoss, buffsize, stdin);
    
    if(IsValid(terran, strlen(terran)) && IsValid(protoss, strlen(protoss))){
        strncpy(protossFleet, protoss, buffsize);
        strncpy(terranFleet, terran, buffsize);
        LowerCase(terranFleet, strlen(terranFleet));
        LowerCase(protossFleet, strlen(protossFleet));
    }
    else{
        printf("Invalid input. Use letters only!\n");
        TakeInputData(terranFleet, protossFleet, buffsize);
    }
}

bool IsValid(char *inputData, int size){
    for(int i = 0; i < size - 1; i++){
        if(isalpha(inputData[i]) == 0){
            return false;
        }
    }
    return true;
}

void LowerCase(char *data, int size){
    for(int i = 0; i < size - 1; i++){
        data[i] = tolower(data[i]);
    }
}