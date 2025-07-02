// Gas sensor 
// Abhinav tripathi

int gassensor = 0;
void setup(){
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(4, OUTPUT);
}
void loop(){
  gassensor = analogRead(A0);
  Serial.println(gassensor);
  if (gassensor >= 400){
    digitalWrite(2, HIGH);
  } 
  else {
    digitalWrite(2, LOW);
  }
  if (gassensor >= 600) {
    tone(4, 523, 200);  
  } 
  else {
    digitalWrite(4, LOW);
  }
  delay(10);  
}