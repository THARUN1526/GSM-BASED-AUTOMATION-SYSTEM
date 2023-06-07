In programming part of this project, first of all in programming we includes library for liquid crystal display and then we defines data and control pins for LCD and home appliances.

#include<LiquidCrystal.h>
LiquidCrystal lcd(6,7,8,9,10,11);

#define Fan 3
#define Light 4
#define TV 5

int temp=0,i=0;
int led=13;
After this serial communication is initialized at 9600 bps and gives direction to used pin.

void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
   pinMode(Fan, OUTPUT);
    pinMode(Light, OUTPUT);
     pinMode(TV, OUTPUT);
For receiving data serially we have used two functions one is Serial.available which checks whether any serial data is coming and other one is Serial.read which reads the data that comes serially.

 while (Serial.available()) 
      {
      char inChar=Serial.read();
After receiving data serially we have stored it in a string and then waiting for Enter.

void serialEvent() 
 {
  while(Serial.available()) 
  {
    if(Serial.find("#A."))
    {
      digitalWrite(led, HIGH);
      delay(1000);
      digitalWrite(led, LOW);
      while (Serial.available()) 
      {
      char inChar=Serial.read();
      str[i++]=inChar;
      if(inChar=='*')
      {
        temp=1;
        return;
      } 
When Enter comes program start to compare received string with already defined string and if string matched then a relative operation is performed by using appropriate command that are given in code.

void check()
{
   if(!(strncmp(str,"tv on",5)))
    {
      digitalWrite(TV, HIGH);
      lcd.setCursor(13,1); 
      lcd.print("ON    ");
      delay(200);
    }  
   
   else if(!(strncmp(str,"tv off",6)))
    {
      digitalWrite(TV, LOW);
      lcd.setCursor(13,1); 
      lcd.print("OFF    ");
      delay(200);
    }
Code
#include<LiquidCrystal.h>

LiquidCrystal lcd(6,7,8,9,10,11);


#define Fan 3

#define Light 4

#define TV 5


int temp=0,i=0;

int led=13;


char str[15];

void setup()

{

  lcd.begin(16,2);

  Serial.begin(9600);

  pinMode(led, OUTPUT);

   pinMode(Fan, OUTPUT);

    pinMode(Light, OUTPUT);

     pinMode(TV, OUTPUT);

  

  lcd.setCursor(0,0);

  lcd.print("GSM Control Home");

  lcd.setCursor(0,1);

  lcd.print("   Automaton    ");

  delay(2000);

  lcd.clear();

  lcd.print("Circuit Digest");

  delay(1000);

  lcd.setCursor(0,1);


 lcd.print("System Ready");

  Serial.println("AT+CNMI=2,2,0,0,0");

  delay(500);

  Serial.println("AT+CMGF=1");

  delay(1000);

  lcd.clear();

  lcd.setCursor(0,0);

  lcd.print("Fan   Light  TV ");

  lcd.setCursor(0,1);

  lcd.print("OFF    OFF   OFF "); 

}


void loop()

{

  lcd.setCursor(0,0);

  lcd.print("Fan   Light  TV");

  if(temp==1)

  {

    check();

    temp=0;

    i=0;

    delay(1000);

  }

}


 void serialEvent() 

 {

  while(Serial.available()) 

  {

    if(Serial.find("#A."))

    {

      digitalWrite(led, HIGH);

      delay(1000);

      digitalWrite(led, LOW);

      while (Serial.available()) 

      {

      char inChar=Serial.read();

      str[i++]=inChar;

      if(inChar=='*')

      {

        temp=1;

        return;

      } 

      } 

    }

   }

 }


void check()

{

   if(!(strncmp(str,"tv on",5)))

    {

      digitalWrite(TV, HIGH);

      lcd.setCursor(13,1); 

      lcd.print("ON    ");

      delay(200);

    }  

   

   else if(!(strncmp(str,"tv off",6)))

    {

      digitalWrite(TV, LOW);

      lcd.setCursor(13,1); 

      lcd.print("OFF    ");

      delay(200);

    }

  

    else if(!(strncmp(str,"fan on",5)))

    {

      digitalWrite(Fan, HIGH);

      lcd.setCursor(0,1); 

      lcd.print("ON   ");

      delay(200);

    }

 

    else if(!(strncmp(str,"fan off",7)))

    {

      digitalWrite(Fan, LOW);

      lcd.setCursor(0,1); 

      lcd.print("OFF    ");

      delay(200);

    }

 

    else if(!(strncmp(str,"light on",8)))

    {

      digitalWrite(Light, HIGH);

      lcd.setCursor(7,1); 

      lcd.print("ON    ");

      delay(200);

    }

 

    else if(!(strncmp(str,"light off",9)))

    {

      digitalWrite(Light, LOW);

      lcd.setCursor(7,1); 

      lcd.print("OFF    ");

      delay(200);

    } 

    

    else if(!(strncmp(str,"all on",6)))

    {

      digitalWrite(Light, HIGH);

      digitalWrite(Fan, HIGH);

      digitalWrite(TV, HIGH);

      lcd.setCursor(0,1); 

      lcd.print("ON     ON    ON  ");

      delay(200);

    }

 

    else if(!(strncmp(str,"all off",7)))

    {

      digitalWrite(Light, LOW);

      digitalWrite(Fan, LOW);

      digitalWrite(TV, LOW);

      lcd.setCursor(0,1); 

      lcd.print("OFF   OFF    OFF  ");

      delay(200);

    }     

}

