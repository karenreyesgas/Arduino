#include <NewPing.h>
int motorIz2 = 9;//motor izquierdo2
int motorIz = 8;//motor izquierdo
int motorDe = 7; //motor derecho
int motorDe2 = 3; //motor derecho2
#define TRIGGER_PIN  4  //trigger del ultrasonico 
#define ECHO_PIN     5 //echo del ultrasonico
#define MAX_DISTANCE 70
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
long Distancia;
volatile int val1;
volatile int val2;

void setup() {
  Serial.begin(9600);
  pinMode(motorIz, OUTPUT);//Motor izquierdo
  pinMode(motorIz2, OUTPUT);//Motor izquierdo2
  pinMode(motorDe, OUTPUT);//Motor derecho0
  pinMode(motorDe2, OUTPUT);//Motor derecho2
  delay(4000);
 
  }

void loop() {
  val1 = analogRead(A1); 
  Serial.println(val1);
  val2 = analogRead(A2); 
  Serial.println(val2); 
  int uS=sonar.ping_cm();;  
  Serial.print("Distancia: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println(" cm");

  /*for(int i=0; i==20; i++){
    suma=suma+sonar.ping_cm();
    Serial.println(suma);
  }
  testeo=suma/20;
  Serial.println(testeo);*/
  if(uS!=0 && val1<80)
  {
  Ataque();  
  }
  if(uS==0 && val1<80 && val2<80) {
  Busqueda();
  }
  if(val1>=80 && uS!=0){
    Atras();
  }
  if(val1>=80 && uS==0){
    Atras();
  }
  if(val2>=80 && uS!=0){
    Escape();
  }
  if(val2>=80 && uS==0){
    Escape();
  }
  delay(1);
  
}
void Ataque(){
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(3, LOW);
}
void Busqueda()
{
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(3, LOW);
}
void Atras()
{
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(3, HIGH);
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(3, LOW);
  delay(1000);
}
void Escape()
{ 
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(3, LOW);
  delay(500);
}

