#include "msp.h"
#include "thermistor.h"
#include "stlIMU.h"

/**
 * Emotion.c
 */
string Emotion(){
    string outputEmotion = “neutral”;
    boolean plannedMovement = true;
    
    //plannedMovement = IMU(); //Get whether the movement is going as planned from the IMU
    if(pet_check() == 1){ //If being pet, set to happy
        outputEmotion = “happy”;
    }
    if(plannedMovement == false){
        outputEmotion = “surprised”;
    }
    return outputEmotion;
}

