/*
 * 
 * Created by: Emerson Medeiros Noberto
 * Created by: Jamylli Vitória Guedes Pereira
 * 16/10/2023
 * 
 */

#include <Servo.h>

Servo myservo;

#define ldr1 A2
#define ldr2 A1

int pos = 90;
int tolerance = 100;

void setup(){
  Serial.begin(9600);
  myservo.attach(10);
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  myservo.write(pos);
  delay(1000);
}

void loop(){      
  int val1 = analogRead(ldr1);
  int val2 = analogRead(ldr2);
  
  if((abs(val1 - val2) <= tolerance) || (abs(val2 - val1) <= tolerance)) {
    // No servo motor horizontal movement will take place if the ldr value is within the allowable tolerance
  } else {
    if(val1 > val2) {
      pos = pos + 1;
    }
    if(val1 < val2) {
      pos = pos - 1;
    }
  }
  
  if(pos > 90) {pos = 90;} // Limita a posição máxima para 150 graus
  if(pos < 0) {pos = 0;}   // Limita a posição mínima para 45 graus
  
  myservo.write(pos);
  delay(30);
  Serial.print("LDR1: ");
  Serial.println(pos);
  
}
