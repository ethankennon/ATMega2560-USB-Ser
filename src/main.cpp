#include <Arduino.h>

// put function declarations here:
char message = '\n';

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

    if (message == 'e' || message == 'E'){   //e for enable
      digitalWrite(LED_BUILTIN, HIGH);    // turn the LED on (HIGH is the voltage level)
      Serial.println("The LED is On.");   // tell the computer the LED is on
    }
    else if (message == 'd' || message == 'D'){  //d for disable
      digitalWrite(LED_BUILTIN, LOW);     // turn the LED off by making the voltage LOW
      Serial.println("The LED is Off.");  // tell the computer the LED is off
    }
    else if (message == 't' || message == 'T'){  //t for toggle
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));     // turn the LED off by making the voltage LOW
      if(digitalRead(LED_BUILTIN)){
        Serial.println("The LED is On.");  // tell the computer the LED is off
      }
      else{
        Serial.println("The LED is Off.");  // tell the computer the LED is off
      }
    }
    else if (message == '\r' || message == '\n'){
      // do nothing
    }
    else {
      Serial.print("Unrecognized command:");
      Serial.println(message);
    }

    message = '\n';
/*
    // read the remainder of the message to clear the serial buffer - holds for the serial timeout so can delay receipt of follow up commands
    while (Serial.available() > 0) {
      // get incoming string:
      String junk = Serial.readString();
    } 
*/
  }
}


// put function definitions here:
