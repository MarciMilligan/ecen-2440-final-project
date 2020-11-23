#include "msp.h"
#include "Thermister.h"
#include "IMU.h"

/**
 * Emotion.c
 */
string Emotion(){
    string outputEmotion = “neutral”;
    boolean touch = Thermistor();
    boolean plannedMovement = IMU(); //Get whether the movement is going as planned from the IMU
    if(touch == true){
        outputEmotion = “happy”;
}
if(plannedMovement == false){
    outputEmotion = “surprised”;
}
    return outputEmotion;
}

