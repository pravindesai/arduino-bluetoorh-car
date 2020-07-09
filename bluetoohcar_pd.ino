/*int rled=1;//right led
int lled=2;//left led
*/
int LM1=5;// left motor M1
int LM2=4; // left motor M2a
int RM1=7; // right motor M2a
int RM2=6; // right motor M2b

void setup() 
{
Serial.begin(9600);
/*pinMode(rled, OUTPUT);
pinMode(lled, OUTPUT);
*/
pinMode(LM1, OUTPUT);
pinMode(LM2, OUTPUT);
pinMode(RM1, OUTPUT);
pinMode(RM2, OUTPUT);
pinMode(13, OUTPUT);
 }
 
void loop()
 {
digitalWrite(13, HIGH);
  
 if(Serial.available()>0)
   {     
      char data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case 'a':     //forword
        Serial.println("moving forwad");
digitalWrite(LM1, HIGH);
digitalWrite(LM2, LOW);
digitalWrite(RM1, HIGH);
digitalWrite(RM2, LOW);
break;
        case 'e': //backward
        Serial.println("moving backward");
digitalWrite(LM1, LOW);
digitalWrite(LM2, HIGH);
digitalWrite(RM1, LOW);
digitalWrite(RM2, HIGH);
break;
         case 'b': //left
        Serial.println("moving left");
digitalWrite(LM1, LOW);
digitalWrite(LM2, HIGH);
digitalWrite(RM1, HIGH);
digitalWrite(RM2, LOW); 
break;
          case 'd': //right
         Serial.println("moving right");
digitalWrite(LM1, HIGH);
digitalWrite(LM2, LOW);
digitalWrite(RM1, LOW);
digitalWrite(RM2, HIGH);
break;      
           case 'c'://off
           Serial.println("STOPPED");
digitalWrite(LM1, LOW);
digitalWrite(LM2, LOW);
digitalWrite(RM1, LOW);
digitalWrite(RM2, LOW); 
break;                           
        default : break;
      }
      Serial.println(data);
   }
   delay(50);
}
