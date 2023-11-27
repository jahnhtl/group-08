bool driving = false;

void setup() {
  // put your setup code here, to run once:
  buttonSetup();
  serialSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
    do{ /* NOTHING */ }while(!driving);
  while(driving){
      motorControl();
      bluetoothModuleStartStop();
  }
}
