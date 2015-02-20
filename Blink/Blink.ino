// BLink adapted from http://arduino.cc Blink example
// from example by Scott Fitzgerald at 8 May 2014

// This sketch will turn on an LED for a little while, then turn it back on.

// the setup function runs once when you press reset or power the board
void setup() {
    // initialize digital pin 13 as an output, which happens to the LED on the
    // board.
    pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    // turn the LED on (HIGH is the voltage level)
    digitalWrite(13, HIGH);
    // wait
    delay(200);
    // turn the LED off by making the voltage LOW
    digitalWrite(13, LOW);
    // wait    
    delay(200);            
    digitalWrite(13, HIGH);
    delay(200);            
    digitalWrite(13, LOW); 
    delay(200);            
    digitalWrite(13, HIGH);
    delay(200);            
    digitalWrite(13, LOW); 
    delay(400);
    digitalWrite(13, HIGH);
    // wait
    delay(600);
    digitalWrite(13, LOW);
    delay(200);            
    digitalWrite(13, HIGH);
    delay(600);            
    digitalWrite(13, LOW); 
    delay(200);            
    digitalWrite(13, HIGH);
    delay(600);            
    digitalWrite(13, LOW); 
    delay(400);          
}
