#include "msp.h"
#include "Actions.h"
#include "Emotion.h"
// #include "Movement.h"
// #include "Piezo.h"
#include "oled.h"
#include "bitmaps.h"

/**
 * Actions.c
 *  
 * Created on 11/23/20
 * Code by Joshua Dinerman
 */

void Actions(){
    currentEmotion = Emotion(); //Emotion
    //piezo_noise(currentEmotion);
    if (currentEmotion != previousEmotion) {
        switch(currentEmotion) {
        case NEUTRAL:
            oled_display(neutral);
            break;
        case SCARED:
            oled_display(scared);
            break;
        case HAPPY:
            oled_display(happy);
            break;
        case SURPRISED:
            oled_display(surprised);
            break;
        case BORED:
            oled_display(bored);
            break;
        }
    }
    previousEmotion = currentEmotion;
}
