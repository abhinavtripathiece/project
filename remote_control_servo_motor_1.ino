// C++ code
//
#include <IRremote.h>

#include <Servo.h>

int tsop = 0;

// Map the IR code to the corresponding remote button.
// The buttons are in this order on the remote:
//    0   1   2
//    4   5   6
//    8   9  10
//   12  13  14
//   16  17  18
//   20  21  22
//   24  25  26
//
// Return -1, if supplied code does not map to a key.
int mapCodeToButton(unsigned long code) {
  // For the remote used in the Tinkercad simulator,
  // the buttons are encoded such that the hex code
  // received is of the format: 0xiivvBF00
  // Where the vv is the button value, and ii is
  // the bit-inverse of vv.
  // For example, the power button is 0xFF00BF000

  // Check for codes from this specific remote
  if ((code & 0x0000FFFF) == 0x0000BF00) {
    // No longer need the lower 16 bits. Shift the code by 16
    // to make the rest easier.
    code >>= 16;
    // Check that the value and inverse bytes are complementary.
    if (((code >> 8) ^ (code & 0x00FF)) == 0x00FF) {
      return code & 0xFF;
    }
  }
  return -1;
}

int readInfrared() {
  int result = -1;
  // Check if we've received a new code
  if (IrReceiver.decode()) {
    // Get the infrared code
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    // Map it to a specific button on the remote
    result = mapCodeToButton(code);
    // Enable receiving of the next value
    IrReceiver.resume();
  }
  return result;
}

Servo servo_2;

Servo servo_3;

Servo servo_4;

Servo servo_5;

void setup()
{
  IrReceiver.begin(8);

  Serial.begin(9600);
  servo_2.attach(2, 500, 2500);
  servo_3.attach(3, 500, 2500);
  servo_4.attach(4, 500, 2500);
  servo_5.attach(5, 500, 2500);
}

void loop()
{
  tsop = readInfrared();
  Serial.println(tsop);
  if (tsop == 16) {
    servo_2.write(0);
  }
  if (tsop == 17) {
    servo_2.write(180);
  }
  if (tsop == 18) {
    servo_3.write(0);
  }
  if (tsop == 20) {
    servo_3.write(180);
  }
  if (tsop == 21) {
    servo_4.write(0);
  }
  if (tsop == 22) {
    servo_4.write(180);
  }
  if (tsop == 24) {
    servo_5.write(0);
  }
  if (tsop == 25) {
    servo_5.write(180);
  }
  if (tsop == 0) {
    servo_2.write(0);
    servo_3.write(0);
    servo_4.write(0);
    servo_5.write(0);
  }
  if (tsop == 14) {
    servo_2.write(120);
    servo_3.write(120);
    servo_4.write(120);
    servo_5.write(120);
  }
  if (tsop == 26) {
    servo_2.write(60);
    servo_3.write(60);
    servo_4.write(120);
    servo_5.write(120);
  }
  if (tsop == 10) {
    servo_2.write(90);
    servo_3.write(90);
    servo_4.write(0);
    servo_5.write(0);
  }
  if (tsop == 8) {
    servo_2.write(0);
    servo_3.write(0);
    servo_4.write(90);
    servo_5.write(90);
  }
  if (tsop == 13) {
    servo_2.write(60);
    servo_3.write(60);
    servo_4.write(60);
    servo_5.write(60);
  }
  delay(100); // Delay a little bit to improve simulation performance
}