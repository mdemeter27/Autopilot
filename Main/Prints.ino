


void printData() {
  if (!serialConnected)return;
  Serial.print("Mode: ");
  Serial.println(mode);
  for (int i = 1; i < 17; i++) {
    Serial.print("Channel ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(channels[i]);
  }

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
  delay(5);



}
