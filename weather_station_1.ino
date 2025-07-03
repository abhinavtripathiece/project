// weather station
// Abhinav Tripathi

int Temp_Sensor = 0;

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  Temp_Sensor = map(((analogRead(A0)-20)* 3.04), 0, 1023, -20, 100); // Assuming -20 to 100 as the desired range after mapping.
  Serial.println(Temp_Sensor);
  if(Temp_Sensor < 40) {
    digitalWrite(6, HIGH);
  } 
  else {
    digitalWrite(6, LOW);
  }
  if(Temp_Sensor < 20) {
    tone(10, 92, 100); // Play tone 52 for 100 ms
  } 
  else {
    digitalWrite(10, LOW);
  }
}