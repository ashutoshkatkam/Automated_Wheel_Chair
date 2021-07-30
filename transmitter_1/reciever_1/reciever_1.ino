#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(PB0,PA4);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
  pinMode(PA0,INPUT);
  pinMode(PA1,INPUT);
  
}
void loop()
{
int arr[3];
arr[0]=analogRead(PA0);
arr[1]=analogRead(PA1);
  radio.write(&arr, sizeof(arr));
  
  
  delay(1000);
}
