#include <Servo.h>

Servo feederServo;

int sensorPin = 2;      
int servoPin = 9;       
int sensorValue = 0;

void setup() {
  pinMode(sensorPin, INPUT);
  feederServo.attach(servoPin);
  
  feederServo.write(0);   
  Serial.begin(1200);
}

void loop() {

  sensorValue = digitalRead(sensorPin);
  
  if(sensorValue == LOW)
  {
    Serial.println("Pet detected - Feeding...");
    
    feederServo.write(45);   // เปิดช่องให้อาหาร
    delay(400);             // ปล่อยอาหาร 2 วินาที
    
    feederServo.write(0);    // ปิดช่องอาหาร
    delay(5000);             // รอ 5 วินาทีก่อนตรวจใหม่
  }

}