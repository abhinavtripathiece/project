//  Abhinav Tripathi
//   ForceSensor

#include <Adafruit_LiquidCrystal.h>
int forceSensor = 0;
Adafruit_LiquidCrystal lcd_1(0);

void setup(){
  pinMode(A0, INPUT);
  Serial.begin(9600);
  lcd_1.begin(16, 2);
  pinMode(13, OUTPUT);
}
void loop(){
  forceSensor = analogRead(A0);
  Serial.println(forceSensor);
  lcd_1.setCursor(0, 0);
  lcd_1.print("ForceSensor");
  lcd_1.setCursor(0, 1);
  lcd_1.print(" Force=");
  lcd_1.setCursor(8, 1);
  lcd_1.print(forceSensor);
  if (forceSensor >= 750) {
    digitalWrite(13, HIGH);
  }  
  else {
    digitalWrite(13, LOW);
  }
  delay(100);   
}