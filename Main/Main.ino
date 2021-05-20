#include <Arduino_LSM9DS1.h>
#include "SBUS.h"
#include <Servo.h> 


//GLOBALS
// channel, fail safe, and lost frames data
uint16_t channels[17]; //0 is null so each channel corresponds to array index
bool failSafe;
bool lostFrame;
SBUS xsr(Serial1);
//Stabilization
float orientation[6];
//Servos
#define throttlePin 2    //CHN 3
#define aileronPin  3    //CHN 1
#define elevonPin   4    //CHN 2
#define rudderPin   5    //CHN 4

#define throttleRange 25
#define controlSurfacesMiddle 90
#define aileronRange 25
#define elevonRange 25
#define rudderRange 25

//Etc
bool serialConnected = true;//MUST TURN THIS TO FALSE FOR FLIGHT
int mode = 0;


//


// 0 is unArmed CHN 5 < 300
// 1 is manual control CHN 5 < 300 and CHN 6 < 300
// 2 is stabilized mode CHN 5 > 300 and CHN 6 < 1300
// CHN 5 is SF on my jumper
//CHN 6 is SB on jumper


void setup() {
  if (serialConnected) {
    Serial.begin(115200);
    while (!Serial);
  }
  lsmSetup();
  receiverSetup();
  writeServosSetup();
}

void loop() {

  while (mode == 0) {
    receiverLoop();
    setMode();
    writeServosLoop();
    printData();
  }
  while (mode == 1) {
    receiverLoop();
    setMode();
    writeServosLoop();
    printData();
  }

  while (mode == 2) {//FIXME Receiver will not work while reading lsm
    receiverLoop();
    setMode();
    stabilize();
    writeServosLoop();
    printData();

  }
}

void error(String s) {
  // mode = 1;
  //if(serialConnected){
  //  Serial.println(s + " going to manual control");
  //}

}
