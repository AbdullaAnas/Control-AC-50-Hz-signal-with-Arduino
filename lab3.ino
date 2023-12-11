/*
thyristor firing angle microcontroller base 
frequency = 50 hz , Time = 20 ms
half cycle time =10 ms 
firing angle time =1 ms
range of alpha 2-8 ms 
*/

//select analog input pin to change the range of alpaha
#define firingAngaleLevel A1
//select analog pin for zero crossing detection circuit
//note: zero crossing detedction circuit change from low to High at zero crossing
//input pin from zero crossing should be an interrupt pin 2/3
#define zeroCrossingInput 2
//select firning thyristor pin
#define firingAngleOut 13
//analog input variable
int firingAngaleValue ;
//cahnge range into microseconds to control the wave firing angle
int alpha ;
void setup() 
{
  pinMode(zeroCrossingInput,INPUT);
  pinMode(firingAngaleLevel,INPUT);
  pinMode(firingAngleOut,OUTPUT);
  //interrupt every rising edge
  attachInterrupt(digitalPinToInterrupt(zeroCrossingInput),Firing,RISING);
}

void loop() {  
firingAngaleValue = analogRead(firingAngaleLevel);
 //change range into microseconds
alpha=map(firingAngaleValue,0,1023,2000,7000);
}
void Firing ()
{
  delayMicroseconds(alpha);
  digitalWrite(firingAngleOut,HIGH);
  delayMicroseconds(1000);
  digitalWrite(firingAngleOut,LOW);  
} 
