//Button and port number
int pin = 2;

//Led colors and ports
int White = 5;
int Yellow = 7; 
int Red = 8;
int Blue = 10;

//serial counter
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
  Serial.println("count");
  counter++;
  Serial.println(counter);
                   
}
//all lights off
void turnOff(){
  digitalWrite(Blue, LOW); 
  digitalWrite(Red, LOW); 
  digitalWrite(Yellow, LOW);   
  digitalWrite(White, LOW);  
}
//begin counting
void loop()
{
  if(counter == 0) {
    turnOff();
  }
  if(counter == 1) {
   digitalWrite(Blue, HIGH); 
   digitalWrite(Red, LOW);
   digitalWrite(Yellow, LOW); 
   digitalWrite(White, LOW);
}
if(counter == 2) {
   digitalWrite(Blue, LOW); 
   digitalWrite(Red, HIGH); 
   digitalWrite(Yellow, LOW); 
   digitalWrite(White, LOW);
}
if(counter == 3){
   digitalWrite(Blue, HIGH); 
   digitalWrite(Red, HIGH); 
   digitalWrite(Yellow, LOW); 
   digitalWrite(White, LOW);
}
if(counter == 4){
   digitalWrite(Blue, LOW); 
   digitalWrite(Red, LOW); 
   digitalWrite(Yellow, HIGH); 
   digitalWrite(White, LOW);
}
if(counter == 5) {
   digitalWrite(Blue, HIGH); 
   digitalWrite(Red, LOW); 
   digitalWrite(Yellow, HIGH); 
   digitalWrite(White, LOW);
}
if(counter == 6) {
   digitalWrite(Blue, LOW); 
   digitalWrite(Red, HIGH); 
   digitalWrite(Yellow, HIGH); 
   digitalWrite(White, LOW);
}
if(counter == 7){
   digitalWrite(Blue, HIGH); 
   digitalWrite(Red, HIGH); 
   digitalWrite(Yellow, HIGH); 
   digitalWrite(White, LOW);
}
if(counter == 8) {
   digitalWrite(Blue, LOW); 
   digitalWrite(Red, LOW); 
   digitalWrite(Yellow, LOW); 
   digitalWrite(White, HIGH);
}
if(counter == 9) {
   digitalWrite(Blue, HIGH); 
   digitalWrite(Red, LOW); 
   digitalWrite(Yellow, LOW); 
   digitalWrite(White, HIGH);
}
if(counter == 10) {
   digitalWrite(Blue, LOW); 
   digitalWrite(Red, HIGH); 
   digitalWrite(Yellow, LOW); 
   digitalWrite(White, HIGH);
}
if(counter == 11) {
   digitalWrite(Blue, HIGH); 
   digitalWrite(Red, HIGH); 
   digitalWrite(Yellow, LOW); 
   digitalWrite(White, HIGH);
}
if(counter == 12) {
   digitalWrite(Blue, LOW); 
   digitalWrite(Red, LOW); 
   digitalWrite(Yellow, HIGH); 
   digitalWrite(White, HIGH);
}
if(counter == 13){
   digitalWrite(Blue, HIGH); 
   digitalWrite(Red, LOW); 
   digitalWrite(Yellow, HIGH); 
   digitalWrite(White, HIGH);
}
if(counter == 14) {
   digitalWrite(Blue, LOW); 
   digitalWrite(Red, HIGH); 
   digitalWrite(Yellow, HIGH); 
   digitalWrite(White, HIGH);
}
if(counter == 15){
   digitalWrite(Blue, HIGH); 
   digitalWrite(Red, HIGH); 
   digitalWrite(Yellow, HIGH); 
   digitalWrite(White, HIGH);
}
if(counter == 16) {
turnOff();    
}

//reset counter to continue without uploading the code
if(counter >16) {
  counter=0; 
}
 
 
}
 
 
