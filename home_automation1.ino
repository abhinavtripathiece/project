// Abhinav tripathi Ece
// smart home automation 

#include <IRremote.h>
int pinIR = 7;
int relay1 = 5; // Bulb1 + LED1
int relay2 = 4; // Bulb2 + LED2
int relay3 = 3; // Motor + LED3

int remoteValue;
void setup(){
  pinMode(pinIR, INPUT);
  IrReceiver.begin(pinIR);
  Serial.begin(9600);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
}
void turnOffAll(){
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
}

void loop(){
  if (IrReceiver.decode()){
    remoteValue = IrReceiver.decodedIRData.command;
    Serial.println(remoteValue);
    IrReceiver.resume();

    if (remoteValue == 0){ // Power button - All OFF
    turnOffAll();
    }
    else if (remoteValue == 16){ // Bulb1 toggle
      digitalWrite(relay1, !digitalRead(relay1));
    }
    else if (remoteValue == 17){ // Bulb2 toggle
      digitalWrite(relay2, !digitalRead(relay2));
    }
    else if (remoteValue == 18){ // Motor toggle
      digitalWrite(relay3, !digitalRead(relay3));
    }
    else if (remoteValue == 20){ // Bulb1 + Bulb2 ON
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, HIGH);
    }
    else if (remoteValue == 21){ // Bulb1 + Motor ON
      digitalWrite(relay1, HIGH);
      digitalWrite(relay3, HIGH);
    }
    else if (remoteValue == 22){ // Bulb2 + Motor ON
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, HIGH);
    }
    else if (remoteValue == 24){ // All On
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, HIGH);
    }
  }
}