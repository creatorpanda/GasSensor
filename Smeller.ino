/*
      Arduino Gas Detector Project (Smeller)

              *UPGRADED VERSION*
  
             Github: creatorpanda
                Creation of 2018
 */


     // -------------------------------- Danger Led Variables -------------------------------- \\

int danger_led =  12;
int danger_led_status = LOW;
long long last_action_danger_led = 0;
int danger_led_on_duration = 200;
int danger_led_off_duration = 50;


     // -------------------------------- Indicator Led Variables -------------------------------- \\

int indicator_led =  13;
int indicator_led_status = LOW;
long long last_action_indicator_led = 0;
int indicator_led_on_duration = 500;
int indicator_led_off_duration = 5000;


     // -------------------------------- Buzzer Variables -------------------------------- \\

int buzzer = 11;
int buzzer_status= LOW;
long long last_action_buzzer = 0;
int buzzer_on_duration = 150;
int buzzer_off_duration = 150;
int buzzer_beep_frequency=150;


     // -------------------------------- Gas Sensor Variables -------------------------------- \\

int gas_sensor=A0;
int gas_value;
int dangerous_value=30;


     // -------------------------------- Timer Variable -------------------------------- \\

long long current_milliseconds;


 // --------------  SETUP -------------- \\
 
void setup(){

  pinMode(danger_led, OUTPUT);
  pinMode(indicator_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(gas_sensor,INPUT);
  Serial.begin(9600);

}


 // --------------  LOOP -------------- \\
 
void loop(){
  
  current_milliseconds = millis();
  gas_value=analogRead(gas_sensor);
  Serial.println(gas_value);


        // -------------------------------- Case where Air is (OK OR NOT OK) & DANGER light is ON (TURNS it OFF. we want the light go off in both cases) -------------------------------- \\
     
  if((danger_led_status == HIGH) && (current_milliseconds - last_action_danger_led >= danger_led_on_duration) &&( (gas_value<dangerous_value)||(gas_value>dangerous_value) ) ){
    
    danger_led_status=LOW;
    last_action_danger_led = current_milliseconds;
    digitalWrite(danger_led, danger_led_status);

  }


        // -------------------------------- Case where Air is NOT OK & DANGER light is OFF (TURNS it ON) -------------------------------- \\
    
  else if ((danger_led_status == LOW) && (current_milliseconds - last_action_danger_led >= danger_led_off_duration) &&(gas_value>dangerous_value)){
    
    danger_led_status=HIGH;
    last_action_danger_led = current_milliseconds;
    digitalWrite(danger_led, danger_led_status);

  }


        // -------------------------------- Case where Air is (OK OR NOT OK) & INDICATOR light is ON (TURNS it OFF. we want the light go off in both cases) -------------------------------- \\
    
  if((indicator_led_status == HIGH) && (current_milliseconds - last_action_indicator_led >= indicator_led_on_duration) &&( (gas_value<dangerous_value)||(gas_value>dangerous_value) ) ){
    
    indicator_led_status = LOW;
    last_action_indicator_led = current_milliseconds;
    digitalWrite(indicator_led, indicator_led_status);

  }


        // -------------------------------- Case where Air is OK & INDICATOR light is OFF (TURNS it ON) -------------------------------- \\

  else if ((indicator_led_status == LOW) && (current_milliseconds - last_action_indicator_led >= indicator_led_off_duration) &&(gas_value<dangerous_value) ){
    
    indicator_led_status = HIGH;
    last_action_indicator_led = current_milliseconds;
    digitalWrite(indicator_led, indicator_led_status);

  }


        // -------------------------------- Case where Air is NOT OK & BUZZER is OFF (EMITS SOUND) -------------------------------- \\

  if((buzzer_status == HIGH) && (current_milliseconds - last_action_buzzer >= buzzer_on_duration)  &&(gas_value>dangerous_value) ){
    
    buzzer_status = LOW;
    last_action_buzzer = current_milliseconds;
    tone(buzzer, buzzer_beep_frequency);

  }


        // -------------------------------- Case where Air is NOT OK & BUZZER is ON (STOPS EMITTING) -------------------------------- \\

  else if ((buzzer_status == LOW) && (current_milliseconds - last_action_buzzer >= buzzer_off_duration)){
    
    buzzer_status = HIGH;
    last_action_buzzer = current_milliseconds;
    noTone(buzzer);

  } 

 
}
