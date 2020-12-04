#include "msp.h"
#include "thermistor.h"
#include "stlIMU.h"

/**
 * Emotion.c
 * 
 * Created on 11/23/20
 * Code by Joshua Dinerman
 */
string Emotion(){
    string outputEmotion = “neutral”; //Emotion neutral by default
    uint32_t in_range = 0; //Nothing is on range of the distance sensor by default
    range(&in_range); //Get whether something is on range of the sensor
    boolean plannedMovement = true; //Movement is going as planned by default
    int16_t z_val = read_magnetometer_z(); //Detect if near magnetic field
    
    if(in_range != 0){ //If something is in range
        plannedMovement = false;
    }
    
    //plannedMovement = IMU(); //Get whether the movement is going as planned from the IMU
    if(abs(z_val) > 5000){ //If near magnet, set to scared
        outputEmotion = “scared”;
    } else if(pet_check() == 1){ //If being pet, set to happy
        outputEmotion = “happy”;
    } else if(plannedMovement == false){ //If not moving as planned, set to surprised
        outputEmotion = “surprised”;
    }
    return outputEmotion;
}

