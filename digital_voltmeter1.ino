// Abhinav Tripathi Ece 
// Digital Voltmeter
#include <LiquidCrystal.h>
// LCD pin connections: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 float voltage=0.00;
 float temp= 0.00, R1=90900, R2=10000;
 int analog_value=0;

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Digital Voltmtr");
}

void loop(){
  analog_value =analogRead(A0);
  temp= (analog_value*5.0)/1024.0;
  voltage=temp/(R2/(R1+R2));
  
  lcd.setCursor(0,1);
  Serial.println(voltage);
  lcd.print(voltage);
  delay(500);
}