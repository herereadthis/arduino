// set constants for the LED pins
// these will be the outputs
const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;
// set constants for the photo sensors
// these will be the inputs
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;
// variables for the output values
int redValue = 0;
int greenValue = 0;
int blueValue = 0;
// variables for the incoming sensor values
int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

// setup() runs once when the Arduino is first powered on
void setup() {
    // open a connection between the Arduino and the computer
    // set at 9600 bits per second
    Serial.begin(9600);
    // define the output pins
    pinMode(greenLEDPin, OUTPUT);
    pinMode(redLEDPin, OUTPUT);
    pinMode(blueLEDPin, OUTPUT);
}

// loop() runs continuously after the setup() function has completed
void loop() {
    // read the sensor values on A0, A1, and A2 with analogRead() and store the
    // values in the appropriate variables
    redSensorValue = analogRead(redSensorPin);
    // ADC takes a millisecond to do its work, so put a delay
    delay(5);
    greenSensorValue = analogRead(greenSensorPin);
    delay(5);
    blueSensorValue = analogRead(blueSensorPin);

    // print out the sensor values on one line
    // \t is the equivalent of pressing the "tab" key on the keyboard
    Serial.print("Raw Sensor Values \t Red: ");
    Serial.print(redSensorValue);
    Serial.print("\t Green: ");
    Serial.print(greenSensorValue);
    Serial.print("\t Blue: ");
    Serial.println(blueSensorValue);

    // since the analog pins return a value betwen 0-1023, you have to divide
    // by 4 to convert to the duty cycle, as PVM expects a value between 0-255
    redValue = redSensorValue / 4;
    greenValue = greenSensorValue / 4;
    blueValue = blueSensorValue / 4;

    // print the new mapped values on their own line
    Serial.print("Mapped Sensor Values \t Red: ");
    Serial.print(redValue);
    Serial.print("\t Green: ");
    Serial.print(greenValue);
    Serial.print("\t Blue: ");
    Serial.println(blueValue);

    // Set the LED light levels
    // analogWrite() changes the LED's brightness via PVM
    // first argument is the pin to send the info
    // second arguent the duty cycle between 0-255
    analogWrite(redLEDPin, redValue);
    analogWrite(greenLEDPin, greenValue);
    analogWrite(blueLEDPin, blueValue);
    
    delay(1000);
}







