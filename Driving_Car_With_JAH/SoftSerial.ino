#include <SoftwareSerial.h>

SoftwareSerial bluetoothModule(12, 13); // RX | TX pins.  Can be reassigned to other pins if needed

#define BAUDRATE_BLUETOOTH_MODULE 9600
#define BAUDRATE_SERIAL_MONITOR 9600

inline void serialSetup(){
  bluetoothModule.begin(BAUDRATE_BLUETOOTH_MODULE);
  bluetoothModule.listen();
  //Serial.begin(BAUDRATE_SERIAL_MONITOR);
}
void bluetoothModuleStartStop(){
  //bluetoothModule.println("Text");
  char text[5];
  uint8_t bits = 0;
  while(bluetoothModule.available() && bits < 5) {
    text[bits] = bluetoothModule.read();
    bits++;
  }
  if( strcmp(text, "Start") == 0 ){
    driving = true;
    bluetoothModule.println("Motor started!");
  } else if( strcmp(text, "Stop") == 0 ){
    driving = false;
    bluetoothModule.println("Motor stopped!");
  } else
    bluetoothModule.println("Something else got received");
}
