int sensor=A0;
int gas_value;
int led1=8;
int led2=13;
int buzzer=7;


void setup()
{

pinMode(sensor,INPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);

}

void loop()
{

gas_value=analogRead(sensor);
Serial.println(gas_value);
if (gas_value >= 150){ 
    digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  tone(buzzer, 500);
  delay(150);
  noTone(buzzer);
  delay(150);
  }

 if (gas_value < 150){ 
  noTone(buzzer);
  digitalWrite(led1, LOW);
  
  digitalWrite(led2, HIGH);
  delay(50);
  digitalWrite(led2, LOW);
  delay(50);
  digitalWrite(led2, HIGH);
  delay(50);
  digitalWrite(led2, LOW);
  delay(1000);
  }
 
 }
  // Github: @creatorpanda
 // Creation of 2017
