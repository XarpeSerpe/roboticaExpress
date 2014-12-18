#include "DualMC33926MotorShield.h"
#include <NewPing.h>
#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     6  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 50 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

DualMC33926MotorShield robot;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup()
{
  robot.init();
}

void loop()
{
 delay(50);
 unsigned int uS = sonar.ping_cm();
 if (uS < 20 || uS == 0)// Si la distancia es mayor de 50 cm, sonar.ping() devuelve 0
  {
    robot.setSpeeds(200,200);
  }
 else
  {
    robot.setSpeeds(-200,-200);
  }
}
