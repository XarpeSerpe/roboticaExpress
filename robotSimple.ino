// Robot que avanza a media velocidad

#include "DualMC33926MotorShield.h"

DualMC33926MotorShield robot;

void setup()
{
  robot.init();
}

void loop()
{
 robot.setSpeeds(200,200);
 //Esta funcion admite valores entre -400 y 400 
 //pero se debe limitar en funcion de la batria
 // y del tipo de motor
}
