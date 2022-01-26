## Automatic Hand Dryer System using ESP32

#### User Requirements
To design an embedded system for an automated hand drying system in washrooms.
On detecting our hand near the device, motor turns ON 

#### Technical Specifications
1. System should check the presence of hand near the hand dryer every 1 second
2. Motor should turn on for a minimum of 5 seconds on detecting the hand
3. Motor should turn off after this period, if no hand is present
4. Motor should stay on throughout the presence of hand
5. External override switch for the dryer should stop operation

#### Components Used
1. ESP32 DevKit V4
2. DC 3.7V 50,000 RPM CoreLess Motor (Analog output)
3. InfraRed Transmitter + Receiver module (Analog Input)
4. 2-mode toggle switch (Digital Input)
5. Misc Electronic wiring

#### Operation
1. The system is off if the switch is turned off.
2. The system constantly checks for inputs from the IR module at a frequency of 1Hz
3. Upon receiving a sensor input of less than 4000 (in a range of 0 to 4096) the polling loop is changed.
4. The microcontroller gives a pwm output of maximum speed to the motor as 255 if <4000 IR value received
5. Fan remains on for a minimum of 5 seconds after it receives the first value below 4000.
