int leftin= A0;
int rightin= A1;
int motorINA= 8;
int motorL1= 9;
int motorL2= 10;
int motorR1= 11;
int motorR2= 12;
int motorINB= 7;
int leftvalor= 0;
int rightvalor= 0;

void setup ()
{ 
  pinMode (motorINA, OUTPUT);
  pinMode (motorL1,OUTPUT);
  pinMode (motorL2, OUTPUT);
  pinMode (motorR1, OUTPUT);
  pinMode (motorR2, OUTPUT);
  pinMode (motorINB, OUTPUT);
}
void loop ()

{ leftvalor=analogRead(leftin);
rightvalor=analogRead (rightin);

if (leftvalor<300&& 
rightvalor<300)
{ digitalWrite(motorL1,HIGH);
digitalWrite (motorINA,HIGH);
digitalWrite(motorR1,HIGH);
digitalWrite(motorINB,HIGH);
}
else {
  if(leftvalor>300&&
  rightvalor<300)
  { digitalWrite(motorL1,LOW);
  digitalWrite(motorINA,LOW);
  digitalWrite(motorR1,HIGH);
  digitalWrite(motorINB,HIGH);
  }
  else{
    if (leftvalor<300 &&
    rightvalor>300)
    {digitalWrite(motorL1,HIGH);
    digitalWrite(motorINA,HIGH);
    digitalWrite(motorR1,LOW);
    digitalWrite(motorINB,LOW);
    }
    else{
      if (leftvalor>300&&
      rightvalor>300)
      { digitalWrite(motorL1, HIGH);
      digitalWrite(motorINA,HIGH);
      digitalWrite(motorR1, HIGH);
      digitalWrite(motorINB,HIGH);
      }
    }
  }
}
}

