bool driving = false;

void setup() {
  // put your setup code here, to run once:
  buttonSetup();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
    do{ /* NOTHING */ }while(!driving);
  while(driving){
      motorControl();
      softSerialTest();
  }
}
