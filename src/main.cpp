#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

String message = "blank";

// the setup function runs once when you press reset or power the board
void setup() {
  // set up serial communication with host device
  Serial.begin(9600);
  while (!Serial){
    //wait for connection
  }
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // if we get a valid byte, read it:
  while (Serial.available() > 0) {
    // get incoming string:
    message = Serial.readString();
  }

  if (message.equalsIgnoreCase("on")){
    digitalWrite(LED_BUILTIN, HIGH);    // turn the LED on (HIGH is the voltage level)
    Serial.println("The LED is On.");   // tell the computer the LED is on
  }
  else if (message.equalsIgnoreCase("off")){
    digitalWrite(LED_BUILTIN, LOW);     // turn the LED off by making the voltage LOW
    Serial.println("The LED is Off.");  // tell the computer the LED is off
  }
  else if (message == "blank"){
    // do nothing
  }
  else {
    Serial.println("Unrecognized command");
  }

  message = "blank";
}


// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}