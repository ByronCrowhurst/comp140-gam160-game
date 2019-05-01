#include <Wire.h>

// Gyro measurements
long gyroX, gyroY, gyroZ;
float rotX, rotY, rotZ;

int incomingByte;      // a variable to read incoming serial data into


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  pinMode(LED_BUILTIN, OUTPUT);

  setupMPU();
}

void loop()
{
// see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'u') {
      sendData();
    }
  }
  
 
  delay(50);
}

void sendData(){
  recordGyroRegisters();
  
  int leftPotValue = analogRead(A0);
  int rightPotValue = analogRead(A1);
  float leftPotVolt = leftPotValue * (5.0 / 1023.0);
  float rightPotVolt = rightPotValue * (5.0 / 1023.0);
  
  // put your main code here, to run repeatedly:
 
  Serial.print(leftPotVolt);
  Serial.print(",");
  Serial.print(rightPotVolt);
  Serial.print(",");
  Serial.println(rotX);
}

void setupMPU()
{
  // Setup MPU
  Wire.beginTransmission(0B1101000);
  Wire.write(0x6B);
  Wire.write(0b0000000);
  Wire.endTransmission();
  Wire.beginTransmission(0b1101000);
  Wire.write(0x1B);
  Wire.write(0x0000000);
  Wire.endTransmission();
  Wire.beginTransmission(0b1101000);
  Wire.write(0x1C);
  Wire.write(0b0000000);
  Wire.endTransmission();
}

void recordGyroRegisters()
{
  Wire.beginTransmission(0b1101000);
  Wire.write(0x3B);
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6);
  //while(Wire.available()<10);
  gyroX = Wire.read()<<8|Wire.read();
  gyroY = Wire.read()<<8|Wire.read();
  gyroZ = Wire.read()<<8|Wire.read();
  processGyroData();
}

void processGyroData()
{
  rotX = gyroX / 16384.0;
  rotY = gyroY / 16384.0;
  rotZ = gyroZ / 16384.0;
}
