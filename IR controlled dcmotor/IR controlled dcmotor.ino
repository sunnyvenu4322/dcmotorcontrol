const int Input3 = 8;                 //arduino 8th pin connected to L293D pin input3
const int Input4 = 9;  
const int EN2 = 2 ;//arduino 9th pin connected to L293D pin input4
int val;
int count=0;
int sensor_pin = 10;
void setup() 
{
  pinMode(sensor_pin, INPUT);
  pinMode (Input4, OUTPUT);
  pinMode (Input3, OUTPUT);
  pinMode (EN2,OUTPUT);
  pinMode (12, OUTPUT);
  
  Serial.begin(9600);
}
//long duration, distance;
void anticlockwise()
{
  digitalWrite(Input4, HIGH); 
  digitalWrite(Input3, LOW); 
  digitalWrite(EN2, HIGH);
  
}

void clockwise()
{
  digitalWrite(Input4, LOW); 
  digitalWrite(Input3, HIGH); 
  digitalWrite(EN2, HIGH);
 
}
void stop(){
 digitalWrite(Input4, LOW); 
  digitalWrite(Input3, LOW); 
  digitalWrite(EN2, HIGH);}
void loop()
{
  val = digitalRead(sensor_pin);                                          
  if(val==0)
  { 
    Serial.println(count); 
    if(count%2==0){
    //digitalWrite(10, LOW);      
    clockwise();
    delay(1500);
  }
  else if(count%2==1)
  { 
    //digitalWrite(10, HIGH);
    anticlockwise();
    
    
  }
  count++;
  delay(1000);
  }
  else
  {
    stop();
  }
}
