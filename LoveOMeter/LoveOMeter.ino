// set a constant, sensorPin, analog pin 0  
// using the TMP36 temperature sensor
// datasheet url: http://arduino.cc/documents/datasheets/TEMP-TMP35_36_37.pdf
// TMP36 sensor reading: 10 millivolts of change is equal to 1˚ Celsius change
const int sensorPin = A0;
const float baselineTemp = 18.0;
// increments for ranges for the temperature sensor
const float increment = 1;


// setup() runs once when the Arduino is first powered on
void setup() {
    // Serial.begin() comman opens up a connection between the Arduino and the
    // computer
    // the argument 9600 means 9600 bits per second
    // use the Arduino IDE's serial monitor to view the info you choose to send
    // send from the microcontroller. The baud rate will be 9600.
    Serial.begin(9600);

    for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
        // Configure pins 2-4 as output
        pinMode(pinNumber, OUTPUT);
        // Set voltage for pins 2-4 as LOW
        digitalWrite(pinNumber, LOW);
    } 
}

// loop() runs continuously after the setup() function has completed
void loop() {
    // local variable sensorVal stores the reading from the sensor
    // the argument is which analog pin to read.
    // the value will be between 0 to 1023, which represents voltage
    int sensorVal = analogRead(sensorPin);
    // convert the ADC reading to voltage
    // ADC = Analog to Digital Converter
    float voltage = (sensorVal / 1024.0) * 5.0;
    // convert the voltage to temperature in degrees
    // since the sensor can read temperatures below 0˚, subtract 0.5 to fix the
    // offset.
    float temp = (voltage - 0.5) * 100;

    // Serial.print() sends info from the Arduino to a connected computer
    Serial.print("Sensor Value: ");
    Serial.print(sensorVal);
    Serial.print(", Volts: ");
    Serial.print(voltage);
    Serial.print(", degrees C: ");
    // Serial.println() will make a new line
    Serial.println(temp);

    float baselineTempPlus1 = baselineTemp + 1 * increment;
    float baselineTempPlus2 = baselineTemp + 2 * increment;
    float baselineTempPlus3 = baselineTemp + 3 * increment;
    
    // if temperature is below baseline, all LEDs are off
    if (temp < baselineTemp) {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
    }
    else if (temp >= baselineTempPlus1  && temp < baselineTempPlus2) {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }
    else if (temp >= baselineTempPlus2 && temp < baselineTempPlus3) {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    }
    else if (temp >= baselineTempPlus3) {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
    }
    delay(200);
}
