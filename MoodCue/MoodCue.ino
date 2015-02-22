#include <Servo.h>
Servo myServo;
const int potPin = A0;
int potVal;
int angle;

// the setup function runs once when you press reset or power the board
void setup() {
    myServo.attach(9);
    Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {    
    potVal = analogRead(potPin);

    Serial.print("potVal: ");
    Serial.print(potVal);

    angle = map(potVal, 0, 1023, 0, 179);
    Serial.print(", angle: ");
    Serial.println(angle);

    myServo.write(angle);
    delay(20);  
}
