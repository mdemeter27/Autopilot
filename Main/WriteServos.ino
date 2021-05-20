
Servo throttleServo;
Servo aileronServo;
Servo elevonServo;
Servo rudderServo;

void writeServosSetup() {
  throttleServo.attach(throttlePin);
  aileronServo.attach(aileronPin);
  elevonServo.attach(elevonPin);
  rudderServo.attach(rudderPin);

}




void writeServosLoop() {
  if (mode == 1) {
    throttleServo.write(map(channels[3], 172, 1810, 0, 170));
    aileronServo.write(map(channels[1], 172, 1810, controlSurfacesMiddle-aileronRange, controlSurfacesMiddle+aileronRange));
    elevonServo.write(map(channels[2], 172, 1810, controlSurfacesMiddle-elevonRange, controlSurfacesMiddle+elevonRange));
    rudderServo.write(map(channels[4], 172, 1810, controlSurfacesMiddle-rudderRange, controlSurfacesMiddle+rudderRange));

  }


}
