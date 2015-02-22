// variable switchState gives the state of the switch
// Variables need a data type to be declared. switchState is an integer (int)
int switchState = 0;

// setup() runs once when the Arduino is first powered on
void setup() {
    // pinMode() configure the digital pins to be either inputs or outputs
    // so pins 3, 4, and 5 are output
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    // pin 2 is input
    pinMode(2, INPUT);
}

// loop() runs continuously after the setup() function has completed
void loop() {
    // digtalRead() checks the voltage level on a digital input
    // the argument is "2," knows to check the state of pin 2
    // and stores the value in the switchState variable
    switchState = digitalRead(2);

    if (switchState == LOW) {
        // digitalWrite() sends voltage info to a pin, and expects 2 arguments:
        // to which pin to send the info, and
        // the value to set the pin, e.g., HIGH or LOW
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
    }
    else {
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        // delay() stops the Arduino from exceuting anything for a period of time
        delay(250);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        delay(250);
    }
}
