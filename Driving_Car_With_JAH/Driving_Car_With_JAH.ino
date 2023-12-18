#include <avr/io.h>

#include "Driving_Car_With_JAH.h"
#include "SoftSerial.h"
#include "buttons.h"

bool driving = false;

int main(void)
{
  init();
  buttonSetup();
  serialSetup();
  while(1){
    do{
      /* NOTHING */ 
    }while(!driving);
    while(driving){ 
      //motorControl();
      SoftSerialTest();
    }
  }
  return 0;
}
