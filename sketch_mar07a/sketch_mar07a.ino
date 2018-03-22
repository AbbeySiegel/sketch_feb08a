//light for 3 seconds  
int pin = 2;
int White = 5;
int Yellow = 7; 
int Red = 8;
int Blue = 10;
int counter = 0;

void setup()
{
  
  Serial.begin(9600); 
  Serial.println("start");
  pinMode(pin, INPUT_PULLUP);
  pinMode(White, OUTPUT);
   pinMode(Yellow, OUTPUT);
    pinMode(Red, OUTPUT);
     pinMode(Blue, OUTPUT);
  
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
        digitalWrite(White, HIGH); //turn on



        

           
    }
    
}


void loop()
{
if(counter == 1) {
  digitalWrite(Yellow, HIGH); //turn on
   digitalWrite(Red, LOW);
   digitalWrite(Blue, LOW); 
}
if(counter == 3) digitalWrite(Red, HIGH); //turn on
digitalWrite(Yellow, LOW); 
digitalWrite(Blue, LOW); 


if(counter > 3) digitalWrite(Blue, HIGH); //turn on
digitalWrite(Yellow, LOW); 
digitalWrite(Red, LOW); 
  


 // digitalWrite(led, HIGH); //turn on
//if(turnOff)
  
 //  if(millis() >= offAt)
    
      // digitalWrite(led5, LOW); //turn off led
       // digitalWrite(led7, LOW); //turn off led
        // digitalWrite(led8, LOW); //turn off led
        //  digitalWrite(led10, LOW); //turn off led
       //Serial.println("off");

  
}

