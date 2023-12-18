#include <avr/io.h>

#include "Driving_Car_With_JAH.h"
#include "SoftSerial.h"
#include "buttons.h"
#include "Motor_controll.h"

bool driving = false;

int main(void)
{
  init();
  buttonSetup();
  serialSetup();
  while(true){
    do{ /* NOTHING */ SoftSerial.println("Do Nothing"); delay(2000); }while(!driving);
    SoftSerial.println("Test inbetween while loop");
    while(driving){ 
      SoftSerial.println("Inside Driving = true\n\n\n\n\n\n\n");
      delay(25);
      motorControl();
      SoftSerialTest();
    }
    
  }
  return 0;
}
