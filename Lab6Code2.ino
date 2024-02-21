
//the right motor will be controlled by the motor A pins on the motor driver
const int AIN1 = 13;           //control pin 1 on the motor driver for the right motor
const int AIN2 = 12;            //control pin 2 on the motor driver for the right motor
const int PWMA = 11;            //speed control pin on the motor driver for the right motor

//the left motor will be controlled by the motor B pins on the motor driver
const int PWMB = 10;           //speed control pin on the motor driver for the left motor
const int BIN2 = 9;           //control pin 2 on the motor driver for the left motor
const int BIN1 = 8;           //control pin 1 on the motor driver for the left motor

const int driveTime = 20;      //this is the number of milliseconds that it takes the robot to drive 1 inch
                               //it is set so that if you tell the robot to drive forward 25 units, the robot drives about 25 inches

const int turnTime = 8;        //this is the number of milliseconds that it takes to turn the robot 1 degree
                               //it is set so that if you tell the robot to turn right 90 units, the robot turns about 90 degrees

                               //Note: these numbers will vary a little bit based on how you mount your motors, the friction of the
                               //surface that your driving on, and fluctuations in the power to the motors.
                               //You can change the driveTime and turnTime to make them more accurate

const int trigPin = 6;
const int echoPin = 7;

float duration, distance; 

String botDirection;           //the direction that the robot will drive in (this change which direction the two motors spin in)
//String distance;               //the distance to travel in each direction
String speed;                  //the speed that the robot will travel

/********************************************************************************/
void setup()
{
//  pinMode(switchPin, INPUT_PULLUP);   //set this as a pullup to sense whether the switch is flipped

  //set the motor control pins as outputs
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  Serial.begin(9600);           //begin serial communication with the computer

  //prompt the user to enter a command
  Serial.println("Enter a direction followed by a distance and a speed.");
  Serial.println("f = forward, b = backward, r = turn right, l = turn left");
  Serial.println("1 = low, 2 = medium, 3 = high");
  Serial.println("Example command: f 1");

  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
}

/********************************************************************************/
void loop()
{
  if (true)
  {                                                     //if the switch is in the ON position
    if (Serial.available() > 0)                         //if the user has sent a command to the RedBoard
    {
      botDirection = Serial.readStringUntil(' ');       //read the characters in the command until you reach the first space
      //distance = Serial.readStringUntil(' ');           //read the characters in the command until you reach the second space
      speed = Serial.readStringUntil(' ');              //read the characters in the command until you reach the third space
      //print the command that was just received in the serial monitor
      Serial.print(botDirection);
      Serial.print(" ");
      //Serial.println(distance.toInt());
      //Serial.print(" ");
      Serial.println(speed);


      int mSpeed = 0;
      if (speed == "1") {
        mSpeed = 100; // Set low speed
      } else if (speed == "2") {
        mSpeed = 150; // Set medium speed
      } else if (speed == "3") {
        mSpeed = 200; // Set high speed
      }

      


      if (botDirection == "f")                         //if the entered direction is forward
      {
        rightMotor(mSpeed);                                //drive the right wheel forward
        leftMotor(mSpeed);                                 //drive the left wheel forward
        //delay(driveTime * distance.toInt());            //drive the motors long enough travel the entered distance
        //rightMotor(0);                                  //turn the right motor off
        //leftMotor(0);                                   //turn the left motor off
      }
      else if (botDirection == "b")                    //if the entered direction is backward
      {
        rightMotor(-mSpeed);                               //drive the right wheel forward
        leftMotor(-mSpeed);                                //drive the left wheel forward
        //delay(driveTime * distance.toInt());            //drive the motors long enough travel the entered distance
        //rightMotor(0);                                  //turn the right motor off
        //leftMotor(0);                                   //turn the left motor off
      }
      else if (botDirection == "r")                     //if the entered direction is right
      {
        rightMotor(mSpeed);                               //drive the right wheel forward
        leftMotor(-mSpeed);                                 //drive the left wheel forward
        //delay(turnTime * distance.toInt());             //drive the motors long enough turn the entered distance
        //rightMotor(0);                                  //turn the right motor off
        //leftMotor(0);                                   //turn the left motor off
      }
      else if (botDirection == "l")                   //if the entered direction is left
      {
        rightMotor(-mSpeed);                                //drive the right wheel forward
        leftMotor(mSpeed);                                //drive the left wheel forward
        //delay(turnTime * distance.toInt());             //drive the motors long enough turn the entered distance
        //rightMotor(0);                                  //turn the right motor off
        //leftMotor(0);                                   //turn the left motor off
      }
    }
  }
  else
  {
    rightMotor(0);                                  //turn the right motor off
    leftMotor(0);                                   //turn the left motor off
  }
}
/********************************************************************************/



void rightMotor(int motorSpeed)                       //function for driving the right motor
{
  if (motorSpeed > 0)                                 //if the motor should drive forward (positive speed)
  {
    digitalWrite(AIN1, HIGH);                         //set pin 1 to high
    digitalWrite(AIN2, LOW);                          //set pin 2 to low
  }
  else if (motorSpeed < 0)                            //if the motor should drive backward (negative speed)
  {
    digitalWrite(AIN1, LOW);                          //set pin 1 to low
    digitalWrite(AIN2, HIGH);                         //set pin 2 to high
  }
  else                                                //if the motor should stop
  {
    digitalWrite(AIN1, LOW);                          //set pin 1 to low
    digitalWrite(AIN2, LOW);                          //set pin 2 to low
  }
  analogWrite(PWMA, abs(motorSpeed));                 //now that the motor direction is set, drive it at the entered speed
}

/********************************************************************************/
void leftMotor(int motorSpeed)                        //function for driving the left motor
{
  if (motorSpeed > 0)                                 //if the motor should drive forward (positive speed)
  {
    digitalWrite(BIN1, HIGH);                         //set pin 1 to high
    digitalWrite(BIN2, LOW);                          //set pin 2 to low
  }
  else if (motorSpeed < 0)                            //if the motor should drive backward (negative speed)
  {
    digitalWrite(BIN1, LOW);                          //set pin 1 to low
    digitalWrite(BIN2, HIGH);                         //set pin 2 to high
  }
  else                                                //if the motor should stop
  {
    digitalWrite(BIN1, LOW);                          //set pin 1 to low
    digitalWrite(BIN2, LOW);                          //set pin 2 to low
  }
  analogWrite(PWMB, abs(motorSpeed));                 //now that the motor direction is set, drive it at the entered speed

                           //turn the left motor off
  }




