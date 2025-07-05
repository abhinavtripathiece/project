//  Abhinav tripathi
//  Smart Door closer

#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>

int pir = 0;
Adafruit_LiquidCrystal lcd_1(0);
Servo servo_6;

void setup(){
  pinMode(4, INPUT);
  lcd_1.begin(16, 2);
  servo_6.attach(6, 500, 2500);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop(){
  pir = digitalRead(4);
  lcd_1.setCursor(0, 0);
  lcd_1.print(pir);
  if (pir == 1) {
    lcd_1.setCursor(0, 1);
    lcd_1.print("Door open ");
    servo_6.write(90);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
  }
  else {
    lcd_1.setCursor(0, 1);
    lcd_1.print("Door close ");
    servo_6.write(0);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
  }
  delay(10); 
}