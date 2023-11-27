 #include <SoftwareSerial.h>

SoftwareSerial SoftSerial(12, 13); // RX | TX pins.  Can be reassigned to other pins if needed

#define BAUDRATE_BLUETOOTH_MODULE 9600
#define BAUDRATE_SERIAL_MONITOR 9600

inline void serialSetup(){
  SoftSerial.begin(BAUDRATE_BLUETOOTH_MODULE);
  Serial.begin(BAUDRATE_SERIAL_MONITOR);
}
void softSerialTest(){
  static char c;
  SoftSerial.println("Test started - Enter something to send to Serial Monitor Window");
  // Read from the Bluetooth module and send to the Arduino Serial Monitor
  if (SoftSerial.available()) {
    c = SoftSerial.read();
    Serial.write(c);
  }
  // Read from the Serial Monitor and send to the Bluetooth module
  if (Serial.available()) {
    c = Serial.read();
    SoftSerial.write(c);   

    return;
  }
  return;
}
