/**
 * Emotion.h
 * 
 * Created on 11/23/20
 * Code by Joshua Dinerman
 */
#ifndef EMOTION_H_
#define EMOTION_H_

#include "thermistor.h"
#include "stIMU.h"
#include "Range.h"

#define NEUTRAL     0
#define SCARED      1
#define HAPPY       2
#define SURPRISED   3
#define BORED       4

int16_t z_val;

int Emotion();

#endif
