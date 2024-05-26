#include <SoftwareSerial.h>
#include "Wire.h"       
#include "I2Cdev.h"     
#include "MPU6050.h" 

#define BT_NAME   "BT_Master"

#define SLAVE_ADDRESS "0022,09,011802"  

SoftwareSerial mySerial(3, 2); // RX, TX

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

//Define packet for the direction (X axis and Y axis)
int data[2];

void setup()
{
  
  Serial.begin(38400);
  mySerial.begin(38400);
  Wire.begin();
  mpu.initialize();
  Serial.println("Arduino Sender");
  
}

void updateSerial(void) {
  while (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  while (Serial.available()) {
    mySerial.write(Serial.read());
  }
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  
  data[0] = map(ax, -17000, 17000, 300, 400); // X-axis data
  data[1] = map(ay, -17000, 17000, 100, 200); // Y-axis data
  
  mySerial.print(data[0]);
  mySerial.print(",");
  mySerial.println(data[1]);

  delay(100);
}