/* 
 *  This code is written to control a UV-C bulb to disinfect PPE, and other items 
 *  The UV-C bulb is controlled depending on the state of the Container Door 
 *  The disinfection time is a variable depending on the container size and the bulb power 
 *  To check the state of the door a Magnatic Window switch is used 
 *  
 *  #Citizen_Science
 */
 
int magSwitch = 2;
int redLED = 12;
int blueLED = 13;             // Declaring the I/O pins 
int relay = 8;
int greenLED = 7;

int disinfectionTime = 1000;  // disinfection time = Time in seconds * 100 
                              // Example, to disinfect for 2 min: disinfectionTime = 100 * 120s = 12000

void setup() {
  
  Serial.begin(9600);

  pinMode(magSwitch,INPUT_PULLUP);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);           // I/O pin modes 
  pinMode(greenLED, OUTPUT);
  pinMode(relay, OUTPUT);

}

int count = 0 ;

void loop() {

  int buttonState = digitalRead(magSwitch);
  Serial.println(buttonState);
  

  if ( buttonState == 1){
    count =0;
  }

  if (count >= disinfectionTime ){

    digitalWrite(redLED,LOW);
    digitalWrite(blueLED,LOW);      // Sterilized, Disinfection Done 
    digitalWrite(greenLED,HIGH);

    digitalWrite(relay,LOW);
    
  }

  else if ( buttonState == 1){

    digitalWrite(redLED,HIGH);
    digitalWrite(blueLED,LOW);      // Door Open
    digitalWrite(greenLED,LOW);
    
    digitalWrite(relay, LOW); 
    
  }

  else {
    
    digitalWrite(redLED,LOW);
    digitalWrite(blueLED,HIGH);     // Sterilization in process, UV ON, Disinfection in progress 
    digitalWrite(greenLED,LOW);
    
    digitalWrite(relay, HIGH);
    count++ ; 
    
  }

  delay(10);
  

}
