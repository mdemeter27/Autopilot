#include <Arduino_LSM9DS1.h>

float orientation[6];

void lsmSetup() {
  if (!IMU.begin()) {
    if (serialConnected)Serial.println("Failed to Initialize LSM. Setting to manual mode");
    mode = 1;
  } else if (serialConnected) {
    Serial.println("Initialized LSM");
  }
}

void stabilize() {
  getOrientation(orientation);
  if (serialConnected) {
    Serial.print("X: ");
    Serial.print(orientation[0]);
    Serial.print("  Y: ");
    Serial.print(orientation[1]);
    Serial.print("  Z: ");
    Serial.print(orientation[2]);
    Serial.print("  magX: ");
    Serial.print(orientation[3]);
    Serial.print("  magY: ");
    Serial.print(orientation[4]);
    Serial.print("  magZ: ");
    Serial.println(orientation[5]);
    delay(100);
  }


}

void getOrientation(float o[]) {

  float x;
  float y;
  float z;
  float magX;
  float magY;
  float magZ;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    o[0] = x;
    o[1] = y;
    o[2] = z;

  }

  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(magX, magY, magZ);
    o[3] = magX;
    o[4] = magY;
    o[5] = magZ;

  }
}
