int led = 13;               
int sensor = 5;           
int state = LOW;            
int valor = 0;                   

void setup() {
  pinMode(led, OUTPUT);     
  pinMode(sensor, INPUT);   
  Serial.begin(9600);
}

void loop(){
  valor = digitalRead(sensor);
  if (valor == HIGH) {           
    digitalWrite(led, HIGH);  
    delay(150);

    if (state == LOW) {
      Serial.println("Movimiento detectado!");
      state = HIGH;
    }
  } else {
      digitalWrite(led, LOW); 
      delay(150);    
      if (state == HIGH){
      Serial.println("Movimiento se detuvo!");
      state = LOW;
    }
  }
}
