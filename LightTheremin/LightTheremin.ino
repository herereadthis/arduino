// Analog Pin 0 will read values
const int sensorPin = A0;
// output for sound
const int soundPin = 8;
// output for light calibration
const int ledPin = 13;
// output for light+sound sync
const int lightPin = 7;

int sensorValue;
// sensor values are set on opposite because we will recalibrate
// minimum sensor value
int sensorLow = 1023;
// maximum sensor value
int sensorHigh = 0;

// low end of pitch
int lowPitch = 50;
// high end of pitch
int highPitch = 1000;

// how often to play the sound
int cycleRate = 250;
// how long to play the sound during each cycle
int soundDuration = 125;



// setup() runs once when the Arduino is first powered on
void setup() {
    // open a connection between the Arduino and the computer
    Serial.begin(9600);

    // sout output for light during calibration
    pinMode(ledPin, OUTPUT);
    // set output for light when sound is playing
    pinMode(lightPin, OUTPUT);
    digitalWrite(ledPin, HIGH);

    // basically, we are going to calibrate for 4 seconds
    // millis() checks the time since the Arduino started
    while (millis() < 4000) {
        sensorValue = analogRead(sensorPin);
        // the problem is the reading from the sensor will never achieve its 
        // true max or min (0-1023). So we will redefine its actual max and min
        // during the 4 second calibration

        // find the max possible value for sensor value
        if (sensorValue > sensorHigh) {
            sensorHigh = sensorValue;
        }
        // find the min possible value
        if (sensorValue < sensorLow) {
            sensorLow = sensorValue;
        }
    }
    // turn off the LED pin after calibration
    digitalWrite(ledPin, LOW);
}

// loop() runs continuously after the setup() function has completed
void loop() {
    sensorValue = analogRead(sensorPin);

    // pitch is a map function: take the min and max of the sensor and map them
    // to the pitch range
    int pitch = map(sensorValue, sensorLow, sensorHigh, lowPitch, highPitch);

    // printout of what's coming back
    Serial.print("sensorValue: ");
    Serial.print(sensorValue);
    Serial.print("\t pitch: ");
    Serial.println(pitch);

    // tone() takes 3 arguments: pin output, pitch, and sound duration
    tone(soundPin,pitch,soundDuration);
    // then turn on the light for that same period
    digitalWrite(lightPin, HIGH);
    delay(soundDuration);

    // light is off during the gap time until the next cycle starts
    digitalWrite(lightPin, LOW);
    delay(cycleRate - soundDuration);
}
