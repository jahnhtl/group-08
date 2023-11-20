#define IN1 7 
#define IN2 6
#define IN3 5
#define IN4 4

inline void motorControl(){
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
}
