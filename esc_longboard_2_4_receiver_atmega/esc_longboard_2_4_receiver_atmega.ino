#include <Servo.h>//Using servo library to control ESC

Servo esc; //Creating a servo object
byte LED_POWER_PIN1 = 8; //Pin where led is powered
byte LED_POWER_PIN2 = 7; //Pin where led is powered
byte LED_POWER_PIN3 = 6; //Pin where led is powered
byte LED_POWER_PIN4 = 5; //Pin where led is powered

byte PWM_RECEIVER_FORWARD_PIN = 9; //Pin where 2,4 Ghz receiver forward signal is attached
byte PWM_RECEIVER_BACKWARD_PIN = 10; //Pin where 2,4 Ghz receiver backward signal is attached

byte ESC_PIN = 2; //Pin where ESC is Attached

double pwm_receiver_forward_value; //Forward Speed Value from 2,4 receiver
double pwm_receiver_backward_value; //Backward Speed Value from 2,4 receiver
double scaled_pwm_receiver_value; //Raw value scaled to be compatible with ESC

void setup()
{
pinMode(PWM_RECEIVER_FORWARD_PIN, INPUT); //Configure PWM input (receiver forward speed)
//pinMode(PWM_RECEIVER_BACKWARD_PIN, INPUT); //Configure PWM input (receiver backward speed)
pinMode(LED_POWER_PIN1, OUTPUT); //Configure led power pin
pinMode(LED_POWER_PIN2, OUTPUT); //Configure led power pin
pinMode(LED_POWER_PIN3, OUTPUT); //Configure led power pin
pinMode(LED_POWER_PIN4, OUTPUT); //Configure led power pin

esc.attach(ESC_PIN); //ESC signal pin

esc.writeMicroseconds(1500); //initialize the esc to 1500 (0 speed)
digitalWrite(LED_POWER_PIN1, HIGH);
digitalWrite(LED_POWER_PIN2, HIGH);
digitalWrite(LED_POWER_PIN3, HIGH);
digitalWrite(LED_POWER_PIN4, HIGH);

Serial.begin(9600);

while (! Serial);
  Serial.print("Program ready");
}

void loop()

{
pwm_receiver_forward_value = pulseIn(PWM_RECEIVER_FORWARD_PIN,HIGH); //Read PWM value from receiver

Serial.print("Receiver forward Value: " );
Serial.println(pwm_receiver_forward_value);

scaled_pwm_receiver_value = map(pwm_receiver_forward_value, 0, 3200,1500,2200); //Scale raw pwm value to ESC values 

Serial.print("Receiver Value mapped: " );
Serial.println(scaled_pwm_receiver_value);
esc.writeMicroseconds(scaled_pwm_receiver_value);  //write scaled value to ESC
}
