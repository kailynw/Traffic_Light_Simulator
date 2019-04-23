//To the reader: I apologize for the nightmare of a program you are about to read
//Port: COM5
#include <Wire.h> //Library includes functions to send bytes between 2 Arduinos

const int r1 = 2;
const int y1 = 3;
const int g1 = 4;
const int r2 = 5;
const int y2 = 6;
const int g2 = 7;
const int trigPin1 = 8;
const int echoPin1 = 9;
const int echoPin2 = 10;
const int buzz = 11;
const int blueLightS = 12;
const int redLightS = 13;
const int fiveSec = 5000;
const int threeSec = 3000;
const int oneSec = 1000;
int toggle = 0;

// defines variables
long duration;
int distance;

void setup()
{
  pinMode(r1, OUTPUT);
  pinMode(y1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(y2, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(buzz,OUTPUT);
  pinMode(redLightS, OUTPUT);
  pinMode(blueLightS, OUTPUT);
  Wire.begin(2);
  Wire.onReceive(change);
  
  Serial.begin(9600); // Starts the serial communication
}

void change(int bytes)
{
  toggle = Wire.read();
  Serial.print("change");
}
void loop()
{
  int i = 0; //timing variable for main loop
  int j; //timing variable for sub-loop
  int b1 = 1000, b2 = 1000; //buffer variables to hold temporary distance values
  
  //****************************************************************************************
  while (toggle == 0) //Loop for Distance Sensor 1
  {
    j = 0;
    digitalWrite(r1, HIGH);
    digitalWrite(y1, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(g2, HIGH);
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(10); // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);  // Reads the echoPin, returns the sound wave travel time in microseconds
    digitalWrite(trigPin1, LOW);
    duration = pulseIn(echoPin1, HIGH);
    distance = duration*0.034/2; //Calculates the distance
    if (distance < 10 && b1 < 10 && b2 < 10) //checks whether all three distance variables are less than 10 in which case STOP! YOU HAVE VIOLATED THE LAW!
    {
      while (j < 80)
      {
        int k = 0;
        if (j % 3 == 0 || j % 4 == 0)
        {
           while (k < 30) //You know, some days I REALLY hate this major
           {
            digitalWrite(redLightS, HIGH);
            digitalWrite(blueLightS, HIGH);
            delay(2);
            k++;
          }
        }
        else if (j % 2 == 0 && j != 0)
        {
          while (k < 30)
          {
            digitalWrite(blueLightS, LOW);
            digitalWrite(redLightS, HIGH);
            delay(2);
            k++;
          }
        }
        else if (j % 2 == 1 && j != 0)
        {
            while (k < 30)
            {
              digitalWrite(redLightS, LOW);
              digitalWrite(blueLightS, HIGH);
              delay(2);
              k++;
           }
        }
        else
        {
            while (k < 30)
            {
              digitalWrite(redLightS, HIGH);
              digitalWrite(blueLightS, HIGH);
              delay(2);
              k++;
           }
        }
        if (j % 20 == 0)  //Causes the buzzer to alternate between 2 tones
        {
              noTone(buzz);
              tone(buzz, 454, 500);
         }
         else if (j % 10 == 0)
         {
            noTone(buzz);
            tone (buzz, 380, 350);
         }
         j++;
      }
   }
   digitalWrite(redLightS, LOW);
   digitalWrite(blueLightS, LOW);
   b2 = b1;
   b1 = distance;
   Serial.println(distance);
   if (toggle == 1)
   {
     tLight(toggle);
   }
  }

  b1 = 1000;
  b2 = 1000;
  distance = 0;
  
  //*****************************************************************************************************************************************************************************************************************************************
  
  while (toggle == 1) //Loop 2
  {
    j = 0;
    digitalWrite(r2, HIGH);
    digitalWrite(y2, LOW);
    digitalWrite(g2, LOW);
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(10);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    duration = pulseIn(echoPin2, HIGH);
    distance = duration*0.034/2; // Calculating the distance
    if (distance < 10 && b1 < 10 && b2 < 10)  //checks whether all three distance variables are less than 10 in which case STOP! YOU HAVE VIOLATED THE LAW!
    {
      while (j < 80)
      {
        int k = 0;
        if (j % 3 == 0 || j % 4 == 0)
        {
           while (k < 30) //You know, some days I REALLY hate this major
                          //Also, if everything breaks, change this 30 to 15. I don't know why, it just works
           {
            digitalWrite(redLightS, HIGH);
            digitalWrite(blueLightS, HIGH);
            delay(2);
            k++;
          }
        }
        else if (j % 2 == 0 && j != 0)
        {
          while (k < 30)
          {
            digitalWrite(blueLightS, LOW);
            digitalWrite(redLightS, HIGH);
            delay(2);
            k++;
          }
        }
        else if (j % 2 == 1 && j != 0)
        {
            while (k < 30)
            {
              digitalWrite(redLightS, LOW);
              digitalWrite(blueLightS, HIGH);
              delay(2);
              k++;
            }
        }
        else
        {
            while (k < 30)
            {
              digitalWrite(redLightS, HIGH);
              digitalWrite(blueLightS, HIGH);
              delay(2);
              k++;
            }
        }
        if (j % 20 == 0)
        {
              noTone(buzz);
              tone(buzz, 454, 500);
            }
         else if (j % 10 == 0)
         {
            noTone(buzz);
            tone (buzz, 380, 350);
         }
         j++;
      }
   }
   digitalWrite(redLightS, LOW);
   digitalWrite(blueLightS, LOW);
   b2 = b1;
   b1 = distance;
   Serial.println(distance);
   if (toggle == 0)
   {
     tLight(toggle);
   }
  }
}
void tLight(int toggle) //method containing code to control the traffic lights
{
   if(toggle == 1)
   {
       digitalWrite(r1, HIGH);
       digitalWrite(y1, LOW);
       digitalWrite(g1, LOW);
       digitalWrite(r2, LOW);
       digitalWrite(y2, HIGH);
       digitalWrite(g2, LOW);
   }
   else if(toggle == 0)
   {
       digitalWrite(r1, LOW);
       digitalWrite(y1, HIGH);
       digitalWrite(g1, LOW);
       digitalWrite(r2, HIGH);
       digitalWrite(y2, LOW);
       digitalWrite(g2, LOW);
   }
   delay(1000);
   if(toggle == 0)
   {
      digitalWrite(r1, HIGH);
      digitalWrite(y1, LOW);
      digitalWrite(g1, LOW);
      digitalWrite(r2, LOW);
      digitalWrite(y2, LOW);
      digitalWrite(g2, HIGH);
   }
   else if(toggle == 1)
   {
      digitalWrite(r1, LOW);
      digitalWrite(y1, LOW);
      digitalWrite(g1, HIGH);
      digitalWrite(r2, HIGH);
      digitalWrite(y2, LOW);
      digitalWrite(g2, LOW);
   }
}
