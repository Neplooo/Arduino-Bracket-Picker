//Basic Libraries
#include <Arduino.h>
#include <Servo.h>
#include <math.h>

//Define Servo
Servo myServo;

//Define Randomness Function
long pick;

//Define Button ports & button states
const int button = 2;
int buttonState = 0;  

//Define Math Variables


void setup() {
  //Define Servo Port
  myServo.attach(3);
  //Define the button's pin mode
  pinMode(button, INPUT_PULLUP);
  //Port that the rng runs off of
  randomSeed(analogRead(0));
  //Define how button works
  buttonState = digitalRead(button);
  //Sets the servo arm to the middle of the spectrum
  myServo.write(90);
}

void loop() {

  //Define how button works (again)
  buttonState = digitalRead(button);

  //If the button is pressed then it will pick a random number between
  //One and 500 and will check if it is even. If it is then it will
  //rotate to the right, if it is not even then it will rotate to the left.
  //After that is done then it will reset to the original position and wait for
  //the button to be pressed again.
  if (buttonState == HIGH){

    delay(250);

    pick = random(1, 501);

     if (( pick % 2) == 0 )
  {
    myServo.write(180);
  }
  else{
    myServo.write(0);
  }

  delay(5000);

  myServo.write(90);

  delay(5000);
  }
  
  
  
}