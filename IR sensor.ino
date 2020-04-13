//library for DC motor
#include<AFMotor.h>

//defining the two motors
AF_DCMotor motor2(2,MOTOR12_64KHZ);
AF_DCMotor motor3(3,MOTOR12_64KHZ);

//declaring Sensor Pins.
int LeftSensor=A4;
int RightSensor=A5;
int L_sensor_val=0;//to store value from sensors.
int R_sensor_val=0;

int threshold=500;

void setup() {
               motor2.setSpeed(100);
               motor3.setSpeed(100);
               //set the speed to 200/255
}
void loop() {
              L_sensor_val=analogRead(LeftSensor); //Reading Left sensor data
              R_sensor_val=analogRead(RightSensor); //Reading Right sensor data
     if(L_sensor_val > threshold && R_sensor_val > threshold) {
                          motor2.run(RELEASE);
                          motor3.run(RELEASE);
       }
    if (L_sensor_val < threshold && R_sensor_val < threshold) {
                          motor2.run(FORWARD);
                          motor3.run(FORWARD);
      }
    if (L_sensor_val < threshold && R_sensor_val > threshold) {
                        motor2.run(RELEASE);
                        motor3.run(FORWARD);
      }
    if (L_sensor_val > threshold && R_sensor_val < threshold) {
                       motor2.run(FORWARD);
                       motor3.run(RELEASE);
      }
 
}
