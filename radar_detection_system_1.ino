 #include <Servo.h>
#include <LiquidCrystal.h>

#define trigPin 9
#define echoPin 10
#define servoPin 11
#define buzzer 12
#define redLED A0
#define greenLED A1
#define potPin A2  // Potentiometer pin

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
Servo myServo;

long duration;
int distance;
int angle;
int threshold;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  myServo.attach(servoPin);
  lcd.begin(16, 2);
  lcd.print("Radar Starting...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read threshold from potentiometer (range: 50 to 250 cm)
  int potValue = analogRead(potPin);
  threshold = map(potValue, 0, 1023, 50, 250);

  for (angle = 0; angle <= 180; angle += 10) {
    myServo.write(angle);
    delay(200);
    distance = getDistance();

    displayData(angle, distance, threshold);
    checkObject(distance, threshold);
  }

  for (angle = 180; angle >= 0; angle -= 10) {
    myServo.write(angle);
    delay(200);
    distance = getDistance();

    displayData(angle, distance, threshold);
    checkObject(distance, threshold);
  }
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;  // Convert to cm
}

void displayData(int angle, int distance, int threshold) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ang:");
  lcd.print(angle);
  lcd.print(" Dis:");
  lcd.print(distance);

  lcd.setCursor(0, 1);
  lcd.print("Thres:");
  lcd.print(threshold);
}

void checkObject(int distance, int threshold) {
  if (distance < threshold) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, HIGH);

    lcd.setCursor(10, 1);
    lcd.print("Detect");
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzer, LOW);

    lcd.setCursor(10, 1);
    lcd.print("Clear ");
  }
}
