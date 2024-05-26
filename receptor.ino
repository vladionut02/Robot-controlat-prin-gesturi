#include <SoftwareSerial.h>

#define BT_NAME   "BT_Slave"

SoftwareSerial mySerial(3, 2); // RX, TX

const int enbA = 6;
const int enbB = 10;
 
const int IN1 = 11;    //Right Motor (-)
const int IN2 = 12;    //Right Motor (+)
const int IN3 = 4;    //Left Motor (+)
const int IN4 = 5;    //Right Motor (-)

int RightSpd = 200;
int LeftSpd = 250;
void setup()
{
  pinMode(enbA, OUTPUT);
  pinMode(enbB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(38400);

  mySerial.begin(38400);
  
  Serial.println("Arduino receiver");
}

void loop() {
  if (mySerial.available()) {
    String receivedData = mySerial.readStringUntil('\n');
    Serial.println(receivedData);
    int data[2];
    int commaIndex = receivedData.indexOf(',');
    if (commaIndex > 0) {
      data[0] = receivedData.substring(0, commaIndex).toInt();
      data[1] = receivedData.substring(commaIndex + 1).toInt();
      
      Serial.print("Data 0: ");
      Serial.println(data[0]);
      Serial.print("Data 1: ");
      Serial.println(data[1]);

      if(data[0] < 340){
      //forward            
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      Serial.println("forward");
    }
   
    if(data[0] > 360){
      //backward              
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      Serial.println("backward");
    }
     
    if(data[1] > 160){
       //right
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      Serial.println("right");
    }
 
    if(data[1] < 140){
     //left
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      Serial.println("left");
    }
 
    if(data[0] > 340 && data[0] < 360 && data[1] > 140 && data[1] < 160){
      //stop car
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      Serial.println("stop");
    }
  }
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}