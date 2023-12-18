#define sensorFront A2
#define sensorRight A0
#define sensorLeft A4
#define IN1 7 
#define IN2 6
#define IN3 5
#define IN4 4

/*
  IN3 und IN4 sind die linken Räder
  IN3 < IN4 Auto fährt vorwärts
  IN3 > IN4 Auto fährt rückwerts
  
  IN1 und IN2 sind die rechten Räder
  IN1 < IN2 Auto fährt vorwärts
  IN1 > IN2 Auto fährt rückwerts  
*/
void motorSetup(){
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
inline void motorControl(){
  int distanceFront, distanceRight, distanceLeft;
  int diff;
  static int motorSpeed=200;


  distanceFront = analogRead(sensorFront);
  Serial.print("vorne: ");
  Serial.println(distanceFront);
  distanceRight = analogRead(sensorRight);
  Serial.print("Rechts: ");
  Serial.println(distanceRight);
  distanceLeft = analogRead(sensorLeft);
  Serial.print("Links: ");
  Serial.println(distanceLeft);

  diff = distanceLeft - distanceRight;
  
  if(diff <= 50 && diff >= -50){ 
   
     if(distanceFront < 250){
      Serial.println("Beschleunigen");
      while(motorSpeed<200){
        motorSpeed = motorSpeed+25;
        digitalWrite(IN4, motorSpeed);
        digitalWrite(IN3, LOW);
        digitalWrite(IN2, motorSpeed);
        digitalWrite(IN1, LOW);
      }
    }
  
    if(distanceFront >= 250){
      Serial.println("Bremsen");
      while(motorSpeed > 0){
         motorSpeed = motorSpeed-25 ;
        digitalWrite(IN4, motorSpeed);
        digitalWrite(IN3, LOW);
        digitalWrite(IN2, motorSpeed);
        digitalWrite(IN1, LOW);
      }
    }
  }
  
  else if(distanceRight < distanceLeft){  // kurve Rechts
    Serial.println("Rechts kurve");
    //Linken Räder
    digitalWrite(IN4,100+(diff/4));
    digitalWrite(IN3, LOW);

    //Rechten Räder
    digitalWrite(IN2,100-(diff/4));
    digitalWrite(IN1, LOW);
  }
  else if(distanceRight > distanceLeft){    // kurve Links
    Serial.println("kurve Links");
    //Linken Räder
    digitalWrite(IN4,100-(diff/4));
    digitalWrite(IN3, LOW);

    //Rechten Räder
    digitalWrite(IN2,100+(diff/4));
    digitalWrite(IN1, LOW);
  }
  

    delay(1000);
}
