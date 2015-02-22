# arduino

### Board

#### Pins

- **Pins A0-A5** - analog pins that report back a value between 0-1023, which maps to a range from 0-5 volts
- **Pins 3, 5, 6, 10, and 11** pins set aside for PVM - note the ```~``` symbol on the board

========

### definitions

#### Components

- **Transducer** - components that change one type of energy into electrical energy, or vice versa.
  - **Sensor** - things that convert other forms of energy into electrical energy.
  - **Actuator** - things that chance electrical energy into other forms of energy.
- **Resister** - component that resists the flow of energy by converting some of the energy to heat.
- **Switch** - component that interrupts the flow of energy, such as a pushbutton
- **Datasheet** - manuals for electrical components
- **Servo Motor** - special type of moter that doesn't spin, but moves to a specific position and stays there. Servo Motors epect a number of pulses that tell them to which angle to move between 1000-2000 microseconds

#### Electrical circuits

- **Current** - the amount of electrical charge flowing past a specific point in your circuit, measured in amps (**A**)
- **Voltage** - the difference in energy between one point in a circuit and another, measured in volts (**V**)
- **Resistance** - how much a component resists the flow of electrical energy, measured in ohms (**Ω**)
- **Anode** - positive side, connects to power
- **Cathode** - negative side, connects to ground
- **Series** - components in series come one after the other
- **Ohm's Law** - V = I*R, I = V/R, R = V/I

#### Programming

- **Argument** - information that you pass to functions, goes inside the parenthesis
- **Variable** - a place for storing information in the Arduino's memory. Variables can change.
  - *int* - integer
  - *float* - floating point number, use for numbers that can be expressed with decimals
- **Constants** - similar to variables, but they cannot change.
- **ADC** - Analog to Digital Converter
- **PVM** - Pulse Width Modulation, a way to simulate an analog output when using a digital device, involves turning a pin on and off at a very rapid rate from ```HIGH``` to ```LOW```
  - *duty cycle* - percentage of time a pin is ```HIGH``` in a period. If a pin is ```HIGH``` for half the time in a period and ```LOW``` for the other half, the *duty cycle* is 50%.

========

### Coding

#### Functions

- ```setup()``` - runs once when the Arduino is first powered on
- ```loop()``` - runs continuously after the ```setup()``` has completed
- ```pinMode()``` - configures the digital pins on the Arduino board to be either inputs or outputs
- ```analogRead()``` - checks the voltage level on an analog input, e.g., A0-A5
- ```analogWrite()``` - sends PVM voltage to a digital output pin and expects 2 arguments: to which pin to send the info, and a value betwen 0-255, which represents the *duty value.*
- ```digitalRead()``` - checks the voltage level on a digital input
- ```digitalWrite()``` - sends voltage info to a pin, and expects 2 arguments: to which pin to send the info, and the value to set the pin, e.g., ```HIGH``` or ```LOW```
- ```delay()``` - stops the Arduino from exceuting anything for a period of time, argument is in milliseconds

#### Methods
- ```Serial.begin()``` - opens up a connection between the Arduino and the computer, argument is the the speed at which the arduino will communicate
- ```Serial.print()``` - sends information from the Arduino to a connected computer
- ```Serial.println()``` - similar to ```Serial.print()``` but makes a new line
