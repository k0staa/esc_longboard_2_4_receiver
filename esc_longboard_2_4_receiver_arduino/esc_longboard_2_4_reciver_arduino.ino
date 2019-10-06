#include <Servo.h>//Using servo library to control ESC

Servo esc; //Creating a servo object

byte PWM_RECEIVER_FORWARD_PIN = 2; //Pin where 2,4 Ghz receiver forward signal is attached
byte PWM_RECEIVER_BACKWARD_PIN = 5; //Pin where 2,4 Ghz receiver forward signal is attached

byte ESC_PIN = 9; //Pin where ESC is Attached

double pwm_receiver_forward_value; //Forward Speed Value from 2,4 receiver
double pwm_receiver_backward_value; //Backward Speed Value from 2,4 receiver
double scaled_pwm_receiver_value; //Raw value scaled to be compatible with ESC

void setup()
{
pinMode(PWM_RECEIVER_FORWARD_PIN, INPUT); //Configure PWM input (receiver forward speed)
//pinMode(PWM_RECEIVER_BACKWARD_PIN, INPUT); //Configure PWM input (receiver backward speed)

esc.attach(ESC_PIN); //ESC signal pin

esc.writeMicroseconds(1500); //initialize the esc signal to 1500 (0 speed)

Serial.begin(9600);

while (! Serial);
  Serial.print("Program ready");
}

void loop()

{
pwm_receiver_forward_value = pulseIn(PWM_RECEIVER_FORWARD_PIN,HIGH); //Read PWM value from receiver

Serial.print("Receiver forward Value: " );
Serial.println(pwm_receiver_forward_value);
scaled_pwm_receiver_value = map(pwm_receiver_forward_value, 0, 3200,1500,2200); //Scale raw pwm value 

esc.writeMicroseconds(scaled_pwm_receiver_value);  //write scaled value to ESC

Serial.print("Receiver Value mapped forward: " );
Serial.println(scaled_pwm_receiver_value);
}
