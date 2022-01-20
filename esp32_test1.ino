// the number of the LED pin
const int ledPin = 12;  // 12 corresponds to GPIO12
const int potPin = 34;
const int switchPin = 14;
int potValue=0;
int switchValue =0;
int extracycles = 0;

// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
 
void setup(){
  Serial.begin(9600);
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(ledPin, ledChannel);
}
 
void loop(){
  Serial.write("increase the LED brightness\n");
  switchValue=digitalRead(switchPin);
  Serial.println(switchValue);
  if(switchValue==1)
  {
  Serial.write("swtich/n");
  potValue=analogRead(potPin);
  Serial.println(potValue);
  extracycles-- ;
  if(potValue<4000){
    ledcWrite(ledChannel, 255);
    Serial.println("inside active cycle");
    extracycles = 50;
  }
  
  else if(extracycles<0){
    ledcWrite(ledChannel, 0);
    Serial.println("inside extra cycle");
  }
  }
    delay(200);
  
}
