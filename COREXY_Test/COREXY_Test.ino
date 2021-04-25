#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
Stepper stepper(STEPS,5,6,7,8);
 deltaA = 
 deltaY = .5 * (deltaA + deltaB);
 deltaX = .5 * (deltaA - deltaB);
void setup()
{
  Serial.begin(9600);
  Serial.println("Stepper test!");
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(80);

}

void loop(){ 
  Serial.println("Forward");
  stepper.step(STEPS);
  delay(1000);
  Serial.println("Backward");
  stepper.step(-STEPS);
  
}
  
   


// Serial.println("Forward");
   // stepper.step(STEPS);
    //Serial.println("Backward");
    //stepper.step(-STEPS);
