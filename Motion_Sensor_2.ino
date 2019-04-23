//Port: COM6

#include <Wire.h>

const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 4;
const int echoPin2 = 5;
int toggle = 0; //Determines which distance sensor to activate

void setup()
{
  Wire.begin();
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int count = 0;
  int distance;
  long duration;
  while (toggle == 0) //Light 1 is active
  {
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(10);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    duration = pulseIn(echoPin1, HIGH);
    distance = duration*0.034/2;
    if (distance < 10 || distance > 1000)
    {
      count++;
    }
    else
    {
      count = 0;
    }
    if (count >= 70)
    {
      toggle = 1;
    }
    Serial.println(distance); //debug, but the program breaks if these print statements aren't here
    delay(20);
  }
  
  Wire.beginTransmission(2);  //Toggle the toggle variable
  Wire.write(toggle);
  Wire.endTransmission();
  Serial.print("Toggle" + toggle);
  count = 0;

  while (toggle == 1) //Light 2 is active
  {
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(10);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    duration = pulseIn(echoPin2, HIGH);
    distance = duration*0.034/2;
    if (distance < 10 || distance > 1000)
    {
      count++;
    }
    else
    {
      count = 0;
    }
    if (count >= 70)
    {
      toggle = 0;
    }
    Serial.println(distance); //debug
    delay(20);
  }
  Wire.beginTransmission(2);  //Toggle the toggle variable
  Wire.write(toggle);
  Wire.endTransmission();
  Serial.print("Toggle" + toggle);
  
}
