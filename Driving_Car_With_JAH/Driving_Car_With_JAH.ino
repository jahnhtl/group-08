bool driving = false;

void setup() {
  // put your setup code here, to run once:
  buttonSetup();
  serialSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  do{ // only checking if we received something from the Bluetooth Module until we start.
	bluetoothModuleStartStop();
  }while(!driving);
  while(driving){
	motorControl();
    bluetoothModuleStartStop();
  }
}
