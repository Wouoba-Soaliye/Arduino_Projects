/*
This code needs more precision.
I plan to do it when I get time.
*/

#define in1 4
#define in2 5
#define in3 6
#define in4 7

#define trigPin 10
#define echoPin 11



#include <Servo.h>
Servo myservo;
int pos = 0;    

void setup() {
  Serial.begin(9600);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  
  myservo.attach(9);
  myservo.write(100);
}

void avancer(){
  analogWrite(in1, HIGH);
  analogWrite(in2, LOW);

  analogWrite(in3, HIGH);
  analogWrite(in4, LOW);
}
void reculer(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void arreter(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void gauche(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void droite(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

int getDistance() {
  // Trigger the sensor by sending a pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the time it takes for the echo pulse to return
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance based on the speed of sound and the duration
  int distance = duration / 58.2;
  
  return distance;
}

void loop() {
  
  getDistance();
  if(getDistance()>20){
    avancer();
  }else if(getDistance()<20){
    arreter();
    myservo.write(180);
    delay(500);
    getDistance();
    int gDist = getDistance();
    if(gDist>20){
      droite();
      delay(250);
      myservo.write(100);
    }else if(gDist<20){
      myservo.write(0);
      delay(500);
      getDistance();
      int dDist = getDistance();
      if(getDistance()>20){
        gauche();
        delay(250);
        myservo.write(100);
      }else{
        arreter();
      }
    }
    
  }
}
   
  
//  int dist = getDistance();
//  if(dist < 10){
//    arreter();
//    myservo.write(170);
//    int gDist = getDistance();
//    myservo.write(10);
//    int dDist = getDistance();
//    delay(500);
//    
//    if(gDist < 10){
//      droite();
//      delay(random(2, 500));
//      avancer();
//    }else if(dDist < 10){
//      gauche();
//      delay(random(2, 500));
//      avancer();
//    }else{
//      droite();
//      delay(random(2, 500));
//      avancer();
//    }
//  }else{
//    avancer();
//  }




//void maDistance(){
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  
//  float valeur = pulseIn(echoPin, HIGH);
//  float distance = valeur*(0.017);
//
//  return distance;
//}
