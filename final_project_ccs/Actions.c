#include "msp.h"
#include "Emotion.h"
#include "Movement.h"
#include "Piezo.h"
#include "oled.h"
#include "bitmaps.h"

/**
 * Actions.c
 *  
 * Created on 11/23/20
 * Code by Joshua Dinerman
 */
void Actions(){
    string currentEmotion = Emotion(); //Emotion
    //Movement(currentEmotion); //Movement takes current emotion and acts accordingly
    //piezo_noise(currentEmotion);
    oled_display(currentEmotion);
}