/*  Writing the code for CCW rotation according to the 
 *  given commutation table
 */

//set the speed

#define SPEED 200 //From 0-255

//setting the hall sensor pins

#define HALL1 0
#define HALL2 1
#define HALL3 2

//setting the enable pin to control speed

#define EN 9

//setting the transistor pins

#define Q1L 3
#define Q1H 4
#define Q2L 5
#define Q2H 6
#define Q3L 7
#define Q3H 8


void setup() 
{
  pinMode(HALL1, INPUT);
  pinMode(HALL2, INPUT);
  pinMode(HALL3, INPUT);

  pinMode(Q1L, OUTPUT);
  pinMode(Q1H, OUTPUT);
  pinMode(Q2L, OUTPUT);
  pinMode(Q2H, OUTPUT);
  pinMode(Q3L, OUTPUT);
  pinMode(Q3H, OUTPUT);

  pinMode(EN, OUTPUT);
  
}

void loop() 
{
  digitalWrite(Q1L, LOW);  //Initialising all pins as low
  digitalWrite(Q1H, LOW);
  digitalWrite(Q2L, LOW);
  digitalWrite(Q2H, LOW);
  digitalWrite(Q3L, LOW);
  digitalWrite(Q3H, LOW);
  
  bool h1 = digitalRead(HALL1);
  bool h2 = digitalRead(HALL2);
  bool h3 = digitalRead(HALL3);

  if( h3 && !h1)
  {
     digitalWrite(Q3L, HIGH); 
  }

  if( h2 && !h1)
  {
     digitalWrite(Q1H, HIGH); 
  }

  if( h2 && !h3)
  {
     digitalWrite(Q2L, HIGH); 
  }

  if( h1 && !h3)
  {
     digitalWrite(Q3H, HIGH); 
  }

  if( h1 && !h2)
  {
     digitalWrite(Q1L, HIGH); 
  }
  
  if( h3 && !h2)
  {
     digitalWrite(Q2H, HIGH); 
  }


  analogWrite(EN, SPEED);

  }
