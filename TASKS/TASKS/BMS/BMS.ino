/*
Assuming battery B1 to be connected initially and the voltages  as mentioned. 

The pots have been adjusted to give outputs between 0-5v

*/


#define BATTERY1 1   //battery 1 at analog 1 pin
#define BATTERY2 2   //battery 1 at analog 2 pin
#define RELAY    7   //relay at digital pin 7
#define B_HIGH   18  //voltage of battery at full charge
#define B_LOW    16  //voltage of battery at low charge




void setup()
{

pinMode(RELAY, OUTPUT);

}



void loop()
{

int BA1 = analogRead(BATTERY1);
int BA2 = analogRead(BATTERY2);

int cutoff = map(B_LOW, 0, B_HIGH, 0, 1023);

if(BA1 <= cutoff) digitalWrite(RELAY, HIGH);

if(BA2 <= cutoff) digitalWrite(RELAY, LOW);


}