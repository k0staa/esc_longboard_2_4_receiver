#include <Servo.h>//Using servo library to control ESC

Servo esc; //Creating a servo class with name as esc
byte PWM_PIN = 2; //Pin where 2,4 Ghz receiver is attached
byte ESC_PIN = 9; //Pin where ESC is Attached
double pwm_value; //Value from 2,4 receiver
double scaled_pwm_value; //Raw value scaled to be compatible with ESC

void setup()
{
pinMode(PWM_PIN, INPUT); //Configure PWM input
esc.attach(ESC_PIN); //ESC signal pin

esc.writeMicroseconds(1500); //initialize the esc signal to 1500
Serial.begin(9600);

while (! Serial);
  Serial.print("Program ready");


}

void loop()

{
pwm_value = pulseIn(PWM_PIN,HIGH); //Read PWM value from receiver
Serial.print("Value: " );
Serial.println(pwm_value);
scaled_pwm_value = map(pwm_value, 0, 3100,1500,2300); //Scale raw pwm value
Serial.print("Value mapped: " );
Serial.println(scaled_pwm_value);
esc.writeMicroseconds(scaled_pwm_value);  //write scaled value to ESC
}
