String sIn;
int step=0;
char buff[40];
int analog1;
void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  analogReadResolution(12);
}

void loop() {
  if(Serial.available()>0){
    sIn += (char)Serial.read();
    Serial.println(sIn);
    if(sIn=="on"){
      digitalWrite(2,HIGH);
      sIn="";
      step=1;
    }
    else if(sIn=="off"){
      step=0;
      digitalWrite(2,LOW);
      sIn="";
      
    }
    
  }

  if(step==1)
  {
    analog1=map(analogRead(1),0,4095,0,100);
    // Serial.println("Step 1");
    sprintf(buff,"data,%d#",analog1);
    Serial.println(buff);
    delay(500);
  }
}
