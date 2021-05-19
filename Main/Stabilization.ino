

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
   
  }


}

void getOrientation(float o[]) {

  float accelX;
  float accelY;
  float accelZ;
  float magX;
  float magY;
  float magZ;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(accelX, accelY, accelZ);
    o[0] = accelX;
    o[1] = accelY;
    o[2] = accelZ;

  }

  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(magX, magY, magZ);
    o[3] = magX;
    o[4] = magY;
    o[5] = magZ;

  }
}
