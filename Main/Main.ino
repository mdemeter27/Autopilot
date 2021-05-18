

bool serialConnected = true;//MUST TURN THIS TO FALSE FOR FLIGHT
int mode = 0;
// 0 is unArmed
// 1 is manual control
// 2 is stabilized mode
//
//


void setup() {
  if (serialConnected) {
    Serial.begin(115200);
    while (!Serial);
  }
  lsmSetup();
  receiverSetup();
}

void loop() {

  while (mode == 0) {
    receiverLoop();
    setMode();

  }
  while (mode == 1) {
    receiverLoop();
    setMode();

  }

  while (mode == 2) {//FIXME Receiver will not work while reading lsm
    receiverLoop();
    setMode();

    stabilize();
  }
}

void error(String s) {
  // mode = 1;
  //if(serialConnected){
  //  Serial.println(s + " going to manual control");
  //}

}
