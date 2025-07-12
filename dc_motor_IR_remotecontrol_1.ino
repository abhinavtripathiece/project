 // Abhinav tripathi Ece 
// IR Remote control DC motor
#include <IRremote.h>
int IR_Sensor = 0;
int mapCodeToButton(unsigned long code) {
  if ((code & 0x0000FFFF) == 0x0000BF00) {
     code >>= 16;
   }
    if (((code >> 8) ^ (code & 0x00FF)) == 0x00FF) {
      return code & 0xFF;
    }
  return -1;
}
int readInfrared() {
  int result = -1; 
  if (IrReceiver.decode()) {
     unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    result = mapCodeToButton(code);
     IrReceiver.resume();
  }
  return result;
}
void setup(){
  IrReceiver.begin(10);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop(){
  IR_Sensor = readInfrared();
  Serial.println(IR_Sensor);
  if (IR_Sensor == 16) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }
  if (IR_Sensor == 17) {
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
  if (IR_Sensor == 0) {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  delay(100);  
}