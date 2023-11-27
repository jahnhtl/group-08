bool driving = false;

void setup() {
  // put your setup code here, to run once:
  buttonSetup();
  serialSetup();
}

void loop() {

  do{ // only checking if we received something from the Bluetooth Module until we start.
	  SoftwareSerialStartStop();
  }while(!driving);
  
  while(driving){
	  motorControl();
    SoftwareSerialStartStop();
  }
}
