int trig = 10;             // Ultrasonic sensor trig pin variable
int fan =8;
int echo = 9;             // Ultrasonic sensor echo pin variable
int led = 7;
int buzzer= 6;
int i=0;                          
                                           // We defined the LCD's pin variables
#include <LiquidCrystal.h>                // We are launching our LCD library.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   // We set the LCD's pin connections
int counter = 0;
int currentState1 = 0;
int previousState1 = 0;
int currentState2 = 0;
int previousState2 = 0;
int inside = 0;
int outside = 0;

void setup() 
{
   lcd.begin(16, 2);              // We adjust the aspect ratio of our LCD screen
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(trig,OUTPUT);           // We set the "trig" pin to OUTPUT
  pinMode(echo,INPUT);            // We set the "echo" pin to INPUT.
  
  pinMode(led,7);
  pinMode(fan,8);
  pinMode(buzzer,OUTPUT);
  lcd.setCursor(4,0);
  lcd.print("Welcome");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait.");
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("Please wait..");
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("Please wait...");
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("Please wait....");
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("Please wait.....");
  delay(200);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait.");
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("Please wait..");
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("Please wait...");
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("Please wait....");
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("Please wait.....");
  delay(200);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please wait.");
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("Please wait..");
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("Please wait...");
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("Please wait....");
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("Please wait.....");
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("Please wait.....");
  delay(200);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Visitor Counter");
    lcd.setCursor(1,1);
  
  lcd.print("By Gokhan");
  delay(2500);
  lcd.clear();
}

void loop()
{
lcd.setCursor(0, 0);
lcd.print("IN: ");
  
lcd.setCursor(8, 0);
lcd.print("OUT: ");
  
lcd.setCursor(0, 1);
lcd.print("Total Inside: ");
  
long duration, distance;
  
digitalWrite(trig, LOW);      // We start the measurement sequence with the ultrasonic sensor.
Serial.println("IN"); 
delayMicroseconds(200); 
  
digitalWrite(trig,HIGH);
Serial.println("OUT");
delayMicroseconds(100); 
  
digitalWrite(trig, LOW);
   duration = pulseIn(echo, HIGH);
distance = (duration/2) / 29.1;          // We calculate the distance with the measured time.

  if (distance <= 9)
{
    delay(5000);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    delay(1000);
    
currentState1 = 1;
}
else {
currentState1 = 0;
}
delay(1000);

  if(currentState1 != previousState1){

    if(currentState1 == 1){
counter = counter + 1;}
lcd.setCursor(14, 1);
lcd.print(counter);
inside = inside +1;}
lcd.setCursor(4, 0);
lcd.print(inside);

  if (distance > 9 && distance <= 18)
  {
    delay(5000);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    
currentState2 = 1;
}

  else 
  {
currentState2 = 0;
}
delay(1000);

  if(currentState2 != previousState2){

    if(currentState2 == 1){
counter = counter - 1;}
lcd.setCursor(14, 1);
lcd.print(counter);               // We print the counter value on the LCD.
outside = outside +1;}
lcd.setCursor(13, 0);
lcd.print(outside);
lcd.setCursor(14, 1);
lcd.print(counter);

  if (counter > 9 || counter < 0){
lcd.setCursor(14, 1);     // We start writing from the 14th row 1st column of the LCD
lcd.print(counter);       
delay(1000);
lcd.clear();            // Old posts on the LCD will be cleared.
 }
}