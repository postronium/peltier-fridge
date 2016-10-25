//digital
int pwm_pin = 3;

//analog
int tempSensor_pin = 0;
int targetTemp_pin = 1;

//variables
int lastTemp = 0;
int pwmPower = 50;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  
  pinMode(pwm_pin, OUTPUT);
  pinMode(tempSensor_pin, INPUT);
  pinMode(targetTemp_pin, INPUT);
  analogWrite(pwm_pin, pwmPower);
}

// the loop routine runs over and over again forever:
void loop() {
  int temp = analogRead(tempSensor_pin);
  int targetTemp = analogRead(targetTemp_pin);
  int tempEvolution = temp - lastTemp;
  int deltaTargetTemp = temp - targetTemp;

  Serial.print("actual temp : ");
  Serial.println(temp);
  
  Serial.print("temp evolution: ");
  Serial.println(tempEvolution);

  Serial.print("delta target temp : ");
  Serial.println(deltaTargetTemp);
  
  Serial.print("target temp : ");
  Serial.println(targetTemp);

  Serial.print("pwm : ");
  Serial.println(pwmPower);

  Serial.println("###############################");

  //update power
  if (deltaTargetTemp > 0) {
    pwmPower++;
  }
  if (deltaTargetTemp - 10 > 0) {
    pwmPower+=2;
  }
  if (deltaTargetTemp < 0) {
    pwmPower--;
  }
  if (deltaTargetTemp + 10 < 0) {
    pwmPower-=2;
  }
  if (pwmPower > 255) {
    pwmPower = 255;
  }
  if (pwmPower < 0) {
    pwmPower = 0;
  }
  analogWrite(pwm_pin, pwmPower);

  lastTemp = temp;
  delay(5000);
}
