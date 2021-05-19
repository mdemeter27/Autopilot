







// a SBUS object, which is on hardware
// serial port 1




void receiverSetup(){
    xsr.begin();

}

 void receiverLoop() {
  if (xsr.read(&channels[1], &failSafe, &lostFrame)) {
    
    delay(0);
  }
 }



void setMode() { //run constantly, changes mode
  if (channels[5] < 500) mode = 0; //FIXME - make so this only disarms when plane is not flying
  else if (channels[6] < 300) mode = 1;
  else if (channels[6] > 1300) mode = 2;
  if (serialConnected) {
   // Serial.print("Mode: ");
    //Serial.println(mode);
  }
}
