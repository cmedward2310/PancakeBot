#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to blah blah JJJJJJJJJJJJJJJ
Stepper stepper(STEPS,5,6,7,8);
int buttonPin = 26;
int buttonRead = 0;
int pitch = 10; //threads per inch
int ratio = 2/1; //gear2 to gear 1 ratio
int plungeSteps = 0;
int stepCount = 0;
int displayCount = 0;
int stepsLeft = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Stepper test!");
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(80);
  //setup button pin as input
  pinMode(buttonPin,INPUT);
  
  
}

void loop()
{
  buttonRead = digitalRead(buttonPin);
  //Serial.println(buttonRead);
  
  while(buttonRead==1){
    Serial.println("Input plunge depth (in)");
    while(Serial.available()==0){}
      int depth = Serial.parseInt();
      plungeSteps = pitch*depth*ratio*STEPS;
      Serial.println(depth);
      while(stepCount < plungeSteps && depth >0){
        Serial.println(stepCount);
        stepCount = stepCount+200;
        stepper.step(stepCount);
        stepsLeft = plungeSteps - stepCount;
        
        
      }
      stepCount = 0;
    //Serial.println(depth);
 
  }
}
  
   


// Serial.println("Forward");
   // stepper.step(STEPS);
    //Serial.println("Backward");
    //stepper.step(-STEPS);
