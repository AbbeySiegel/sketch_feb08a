//Made All the lights turn on 
//light for 3 seconds  
int pin = 2;
int led5 = 5;
int led7 = 7; 
int led8 = 8;
int led10 = 10;
int counter=0;

void setup()
{
  
  Serial.begin(9600); 
  Serial.println("start");
  pinMode(pin, INPUT_PULLUP);
  pinMode(led5, OUTPUT);
   pinMode(led7, OUTPUT);
    pinMode(led8, OUTPUT);
     pinMode(led10, OUTPUT);
  
  attachInterrupt(0, isr, FALLING);
}

volatile long last = 0;
volatile bool turnOff = false;
volatile long offAt = 0;

void isr()
{ 
  Serial.println("hi");
  counter++;
  Serial.println(counter);
    if( (millis() - last ) > 20 ) //if at least 20 ms has passed since last press, this is not a dup
    {
        last = millis(); //note the time, for ignoring duplicate presses
        turnOff = true;
        offAt = millis() + 3000; //save a variable of now + 3 seconds
        digitalWrite(led5, HIGH); //turn on



         digitalWrite(led7, HIGH); //turn on
          digitalWrite(led8, HIGH); //turn on
           digitalWrite(led10, HIGH); //turn on
    }
    
}


void loop()
{

 // digitalWrite(led, HIGH); //turn on
  if(turnOff)
  {
   if(millis() >= offAt)
    {
       digitalWrite(led5, LOW); //turn off led
        digitalWrite(led7, LOW); //turn off led
         digitalWrite(led8, LOW); //turn off led
          digitalWrite(led10, LOW); //turn off led
       //Serial.println("off");
    } 
  }
}
//press button again this should work for all of them if I have it 3 times... maybe I'm not actually sure if this will work at all








