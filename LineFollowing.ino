int out1 = 5;
int out2 = 4;
int out3 = 6;
int out4 = 7;
byte stt;
int nguong;
float speedbase=0.5;

void motor( int a, int b, int c, int d)
{
  // 1: đi thẳng
  // 2: đi lùi
  // 3: dừng
  switch (d)
  {
   case 1: analogWrite(a,(int)(c*2.55*speedbase));
           digitalWrite(b,LOW);
           break;
   case 2: analogWrite(a,(int)(c*2.55*speedbase));
           digitalWrite(b,HIGH);
           break;
   case 3: analogWrite(a,0);
           digitalWrite(b,LOW);
           break;
  } 
}

void check()
{
  nguong = (analogRead(A0)+analogRead(A4))/2;
  stt=0b00000000;
  if(analogRead(A0)>nguong)
  stt|=1<<0;
  if(analogRead(A1)>nguong)
  stt|=1<<1;
  if(analogRead(A2)>nguong)
  stt|=1<<2;
  if(analogRead(A3)>nguong)
  stt|=1<<3;
  if(analogRead(A4)>nguong)
  stt|=1<<4;
  
}

void test()
{
  if( (bool)(stt&0b00010000) ==1)
    {
      Serial.print("aDen");
    }
  else
    {
      Serial.print("aTrang ");
    }

if( (bool)(stt&0b00001000) ==1)
    {
      Serial.print("bDen ");
    }
  else
    {
      Serial.print("bTrang ");
    }
  
  if( (bool)(stt&0b00000100) ==1)
    {
      Serial.print("cDen ");
    }
  else
    {
      Serial.print("cTrang ");
    }

    if( (bool)(stt&0b00000010) ==1)
    {
      Serial.print("dDen ");
    }
  else
    {
      Serial.print("dTrang ");
    }

    if( (bool)(stt&0b00000001) ==1)
    {
      Serial.println("eDen ");
    }
  else
    {
      Serial.println("eTrang ");
    }

}

void setup() {
  Serial.begin(9600);
  pinMode(A4,INPUT);
  pinMode(A3,INPUT);
  pinMode(A2,INPUT);
  pinMode(A1,INPUT);
  pinMode(A0,INPUT);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  check();
  switch(stt)
  {
    case 0b00010000:
     {
      Serial.println("Trai");
      motor(out1, out2, 10, 2);
      motor(out3, out4, 75, 1);
      break;
    }
    case 0b00011000:
     {
      Serial.println("Trai");
      motor(out1, out2, 25, 1);
      motor(out3, out4, 75, 1);
      break;
    }
    case 0b00011100:
     {
       Serial.println("Trai");
      motor(out1, out2, 25, 1);
      motor(out3, out4, 50, 1);
      break;
    }
    case 0b00011110:
    {
       Serial.println("Trai");
      motor(out1, out2, 50, 1);
      motor(out3, out4, 100, 1);
      break;
    }
    
    case 0b00001111:
     {
    Serial.println("Phai");
      motor(out1, out2, 100, 1);
      motor(out3, out4, 50, 1);
      break;
    }
    case 0b00000111:
     {
    Serial.println("Phai");
      motor(out1, out2, 50, 1);
      motor(out3, out4, 25, 1);
      break;
    }
    case 0b00000011:
     {
    Serial.println("Phai");
      motor(out1, out2, 75, 1);
      motor(out3, out4, 25, 1);
      break;
    }
    case 0b00000001:
    {
     Serial.println("Phai");
      motor(out1, out2, 75, 1);
      motor(out3, out4, 10, 2);
      break;
    }
    
    default:
    {
      Serial.println("Giua");
      motor(out1, out2, 100, 1);
      motor(out3, out4, 100, 1);
      break;
    }
  }
  //test();
  delay(50);
}
