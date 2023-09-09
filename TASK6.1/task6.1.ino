#include <Wire.h>

const int MPU6050_ADDRESS = 0x68;
const int GYRO_CONFIG = 0x1B;
const int GYRO_ZOUT_H = 0x47;
const int GYRO_ZOUT_L = 0x48;
const float GYRO_SCALE = 131.0;

int16_t gyroZ;
float gyroZangle = 0.0;
float timeInterval = 0.01;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  writeRegister(MPU6050_ADDRESS, GYRO_CONFIG, 0x08);
}

void loop() {
  // Read gyroscope data
  gyroZ = readRegister16(MPU6050_ADDRESS, GYRO_ZOUT_H);

  // Calculate Yaw angle
  gyroZangle += (gyroZ / GYRO_SCALE) * timeInterval;

  // Print Yaw angle
  Serial.print("Yaw Angle: ");
  Serial.println(gyroZangle, 2); // Display angle with 2 decimal places

  delay(10);
}

// Function to write a value to a register
void writeRegister(int deviceAddress, int registerAddress, byte value) {
  Wire.beginTransmission(deviceAddress);
  Wire.write(registerAddress);
  Wire.write(value);
  Wire.endTransmission();
}

// Function to read a 16-bit value from a register
int16_t readRegister16(int deviceAddress, int registerAddress) {
  Wire.beginTransmission(deviceAddress);
  Wire.write(registerAddress);
  Wire.endTransmission(false);
  Wire.requestFrom(deviceAddress, 2, true);

  int16_t value = (Wire.read() << 8) | Wire.read();
  return value;
}
