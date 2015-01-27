//#define DEBUG
#include <DualMC33926MotorShield.h>
#include <NewPing.h>
#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     6  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 50 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define EYE_RIGHT A0
#define EYE_LEFT A1


DualMC33926MotorShield robot;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup()
{
  robot.init();
  #ifdef DEBUG
    Serial.begin(9600);
  #endif
  delay(1500);
}

void loop()
{
 delay(50);
 unsigned int uS = sonar.ping_cm();
 #ifdef DEBUG
   Serial.println(uS);
 #endif
 if (uS > 20 || uS == 0)// Si la distancia es mayor de 50 cm, sonar.ping() devuelve 0
  {
    light();  
  }
 else
  {
    robot.setSpeeds(-90,-100);
    delay(50);
    robot.setSpeeds(0,-200);
  }
}

void light()
{
  int light_right = analogRead(EYE_RIGHT);
  int light_left = analogRead(EYE_LEFT);
  int difference = light_right-light_left;
  
  if (light_left > light_right) { robot.setSpeeds(195,65);}
  else if (light_left < light_right) { robot.setSpeeds(63,200);}
  else { robot.setSpeeds(195,200);}
}
