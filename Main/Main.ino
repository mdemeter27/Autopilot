
bool serialConnected = true;//MUST TURN THIS TO FALSE FOR FLIGHT
int mode = 2;
// 0 is unArmed
// 1 is manual control
// 2 is stabilized mode
//
//


void setup() {
  if (serialConnected) {
    Serial.begin(9600);
    while (!Serial);
  }
  lsmSetup();
}

void loop() {
  while (mode == 0) {

  }
  while (mode == 1) {
    //Do something
  }

  while (mode == 2) {
    stabilize();
  }
}

void error(String s){
 // mode = 1;
  //if(serialConnected){
  //  Serial.println(s + " going to manual control");
  //}
  
}
