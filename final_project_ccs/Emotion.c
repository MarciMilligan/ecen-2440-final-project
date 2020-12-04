#include "msp.h"
#include "emotion.h"

/**
 * Emotion.c
 * 
 * Created on 11/23/20
 * Code by Joshua Dinerman
 */
int Emotion(){
    int outputEmotion = NEUTRAL; //Emotion neutral by default
    uint32_t in_range = 0; //Nothing is on range of the distance sensor by default
    // range(&in_range); //Get whether something is on range of the sensor
    bool plannedMovement = true; //Movement is going as planned by default
    z_val = read_magnetometer_z(); //Detect if near magnetic field
    
    if(in_range != 0){ //If something is in range
        plannedMovement = false;
    }
    
    if(abs(z_val) > 5000){ //If near magnet, set to scared
        outputEmotion = SCARED;
    /*
      else if(pet_check() == 1){ //If being pet, set to happy
        outputEmotion = HAPPY;
    */
    } else if(plannedMovement == false){ //If not moving as planned, set to surprised
        outputEmotion = SURPRISED;
    }
    return outputEmotion;
}

