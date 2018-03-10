int IN = 10;
//potentiometer
int analogPin = 0;

// motor
int enA = 3;
int in1 = 10;
int in2 = 8;

//PID
float setpoint = IN *10;
float newval   = 0;
float oldval   = 0;
float err;
float pterm;
float iterm;
float dterm;
float u;
//Constants
float kp = 0.4;
float ki = 0.002;
float kd = 10;



void setup()
{
  // motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600);
}


void loop()
{

  while (1)
  {
    newval = analogRead(analogPin);     // read the input pin
    Serial.println(int(newval/10));

    
    err    =  newval - setpoint;
    pterm  =  err;
    iterm  =  (iterm + err);
    dterm  =  (newval - oldval);
    u      =  kp * pterm + ki * iterm + kd * dterm;
    oldval = newval;

//    Serial.println(pterm);
//    Serial.println(iterm);
//    Serial.println(dterm);
   
    if (err < 0 )
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
    }

    if (err > 0 )
    {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);

    }

    if (abs(err)  < 10 )
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);

    }
    analogWrite(enA, abs(u));

  }


}
