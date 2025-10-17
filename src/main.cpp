#include <Arduino.h>

// put function declarations here:
char message = '\n';
int new_state = -1; //used to track changes in the LED state

// the setup function runs once when you press reset or power the board
void setup() {
  // set up serial communication with host device
  Serial.begin(115200);
  while (!Serial){
    //wait for connection
  }
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //version that gets a char from the serial host
  if (Serial.available() > 0) {
    // get incoming byte:
    message = Serial.read();

    switch (message){
      case 'e':   //e for enable
      case 'E':
        digitalWrite(LED_BUILTIN, HIGH);    // turn the LED on (HIGH is the voltage level)
        new_state = 1;
        break;
      case 'd':  //d for disable
      case 'D':
        digitalWrite(LED_BUILTIN, LOW);     // turn the LED off by making the voltage LOW
        new_state = 0;
        break;
      case 'p':  //p for ping, just respond for timing purposes
      case 'P':
        Serial.println("P");  // quick response with no change to outputs
        break;
      case '\r':
      case '\n':
        break;
      default:
        Serial.print("Unrecognized command:");
        Serial.println(message);
        /*
        // read the remainder of the message to clear the serial buffer - holds for the serial timeout so can delay receipt of follow up commands
        while (Serial.available() > 0) {
          // get incoming string:
          String junk = Serial.readString();
        } 
        */
    }

    //serial responses for state changes, eventually will be a separate input measuring the output of the relay
    if (new_state == digitalRead(LED_BUILTIN)){
      switch (new_state){
        case 0:
          Serial.println("0");  // tell the computer the LED is off
          new_state = -1; //reset new_state
          break;
        case 1:
          Serial.println("1");   // tell the computer the LED is on
          new_state = -1; //reset new_state
          break;
        default:
          //should never get here
          digitalWrite(LED_BUILTIN, LOW);     // turn the LED off by making the voltage LOW
      }
    }

    message = '\n'; //reset for when there is no new message

  }
}


// put function definitions here:
