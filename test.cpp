void setup()
{
  
  
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop()
{
  //Delay Vars
  int fiveSec=5000;
  int threeSec=3000;
  int oneSec=1000;
  
  //Traffic Light 1
  int red1=13;
  int yellow1=12;
  int green1=11;
  
 
  
  digitalWrite(green1, HIGH);
  delay(oneSec); // Wait for 1000 millisecond(s)
  digitalWrite(green1, LOW);
  delay(100); // Wait for 1000 millisecond(s)
  
  digitalWrite(yellow1, HIGH);
  delay(oneSec); // Wait for 1000 millisecond(s)
  digitalWrite(yellow1, LOW);
  delay(100); // Wait for 1000 millisecond(s)
  
  digitalWrite(red1, HIGH);
  delay(oneSec); // Wait for 1000 millisecond(s)
  digitalWrite(red1, LOW);
  delay(100); // Wait for 1000 millisecond(s)
  
  
  
   
  //Traffic Light2
  int red2=7;
  int yellow2=6;
  int green2=5;
  
  digitalWrite(green2, HIGH);
  delay(oneSec); // Wait for 1000 millisecond(s)
  digitalWrite(green2, LOW);
  delay(100); // Wait for 1000 millisecond(s)
  
  digitalWrite(yellow2, HIGH);
  delay(oneSec); // Wait for 1000 millisecond(s)
  digitalWrite(yellow2, LOW);
  delay(100); // Wait for 1000 millisecond(s)
  
  digitalWrite(red2, HIGH);
  delay(oneSec); // Wait for 1000 millisecond(s)
  digitalWrite(red2, LOW);
  delay(100); // Wait for 1000 millisecond(s)
  
}
