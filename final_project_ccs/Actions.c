#include "msp.h"
#include "Emotion.h"
#include "Movement.h"
#include "Piezo.h"

/**
 * Actions.c
 */
void Actions(){
    string currentEmotion = Emotion(); //Emotion
    Movement(currentEmotion); //Movement takes current emotion and acts accordingly
    if(currentEmotion == “bored” || currentEmotion == “happy” || currentEmotion == “surprised”){ //If current emotion is one of the emotions that outputs sound
        piezo_noise(currentEmotion);
        oled_draw(currentEmotion);
    }
}