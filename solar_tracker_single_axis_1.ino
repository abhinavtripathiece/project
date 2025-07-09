 // Abhinav tripathi Ece 
// single axis Solar system

#include <Servo.h>
Servo myServo;
int ldrLeft = A0;      
int ldrRight = A1;    
int servoPin = 9;      

int position = 90;     
int threshold = 10;    

void setup() {
  myServo.attach(servoPin);
  myServo.write(position);   
  delay(100);
}

void loop() {
  int leftValue = analogRead(ldrLeft);   
  int rightValue = analogRead(ldrRight);   

  int difference = leftValue - rightValue;

  if (abs(difference) > threshold) {
    if (difference > 0 && position < 180) {
      position++;   
    } else if (difference < 0 && position > 0) {
      position--;  
    }
    myServo.write(position);
    delay(15);   
  }

  delay(100);   
}