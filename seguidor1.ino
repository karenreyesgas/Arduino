int senizq(A0);
int sender(A1);
int motor1(9);
int motor2(10);
int leftin;
int rightin;
void setup() {
pinMode(motor1, OUTPUT);
pinMode(motor2, OUTPUT);
pinMode(senizq, INPUT);
pinMode(sender, INPUT);
leftin= 0;
rightin = 0;
}



void loop() {
  
senizq=analogRead(leftin);
sender=analogRead (rightin);
if(senizq<219 && sender<169)
{
  digitalWrite (motor1,HIGH);
  digitalWrite (motor2,HIGH);
} 
  else{
  if(senizq<219 && sender>169)
  {
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2, LOW);}
    else{
    if(senizq>219 && sender<169){
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);}
    else{
    if(senizq>219 && sender>169)
    {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, HIGH);
    }
    }
    }
  }
}

