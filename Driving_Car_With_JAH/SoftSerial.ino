#include <SoftwareSerial.h>

SoftwareSerial SoftwareSerial(0, 1); // RX | TX pins.  Can be reassigned to other pins if needed

#define BAUDRATE_BLUETOOTH_MODULE 9600
#define BAUDRATE_SERIAL_MONITOR 9600

inline void serialSetup(){
  SoftwareSerial.begin(BAUDRATE_BLUETOOTH_MODULE);
  SoftwareSerial.listen();
  SoftwareSerial.println("We did start the Module and are listening");
  //Serial.begin(BAUDRATE_SERIAL_MONITOR);
}
void SoftwareSerialStartStop(){
  //SoftwareSerial.println("Text");
  char text[5];
  uint8_t bits = 0;
  char symbol;
  if(SoftwareSerial.available()){
    symbol = SoftwareSerial.read();
    SoftwareSerial.println("A");
    switch(symbol){
    case 's':
    case 'S':
      driving = true;
      SoftwareSerial.println("R");
      break;
    case 'P':
    case 'p':
      driving = true;
      SoftwareSerial.println("Q");
      break;
    default:
      SoftwareSerial.println("X");
      break;
    }
  }
  /*while(SoftwareSerial.available() && bits < 5) {
    text[bits] = SoftwareSerial.read();
    bits++;
  }*/
//  SoftwareSerial.print("I received ");
//  SoftwareSerial.println(text);
//  if( strcmp(text, "Start") == 0 ){
//    driving = true;
//    SoftwareSerial.println("Motor started!");
//  } else if( strcmp(text, "Stop") == 0 ){
//    driving = false;
//    SoftwareSerial.println("Motor stopped!");
//  } else
//    SoftwareSerial.println("Something else got received");
}
