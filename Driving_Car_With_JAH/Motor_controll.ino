#define sensorFront A0
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
  int distanceFront;
  static int motorSpeed=200;


  distanceFront = analogRead(sensorFront);
  Serial.println(distanceFront);
  
  if(distanceFront < 250){
    while(motorSpeed<200){
      motorSpeed = motorspeed+4;
      digitalWrite(IN4, motorSpeed);
      digitalWrite(IN3, LOW);
      digitalWrite(IN2, motorSpeed);
      digitalWrite(IN1, LOW);
    }
  }
  if(distanceFront >= 250){
    while(motorSpeed > 0){
       motorSpeed = motorSpeed-4 ;
       digitalWrite(IN4, motorSpeed);
       digitalWrite(IN3, LOW);
       digitalWrite(IN2, motorSpeed);
       digitalWrite(IN1, LOW);
       delay(2); 
    }
  }
}
