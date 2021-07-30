//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
  pinMode(11,INPUT_ANALOG);
  pinMode(12,INPUT_ANALOG);
  
}
void loop()
{
int x=analogRead(11);
int y=analogRead(12);
  radio.write(&x, sizeof(x));
  radio.write(&y, sizeof(y));
  
  delay(1000);
}
