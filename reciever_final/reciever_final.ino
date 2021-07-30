#include <nRF24L01.h>

#include<SPI.h>
#include <RF24.h>
//#include <RF24-STM_config.h>
RF24 radio(PB0,PA4); // CE, CSN
   // const byte address[5] = {1,'e','l','l','o'};
    void setup() {
      Serial.begin(115200);
    radio.begin();  
    pinMode(PB5,OUTPUT);
    pinMode(PB6,OUTPUT);
    pinMode(PB7,OUTPUT);
    pinMode(PB8,OUTPUT);
    radio.openReadingPipe(0,0xB3B4B5B602); 
    //Setting the address at which we will receive the data
    radio.setPALevel(RF24_PA_MIN);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
    radio.startListening();
    //This sets the module as receiver
    
    }
     void loop()
    {
      
     Serial.println("Working");
    if (radio.available())              //Looking for the data.
   {char text[]="";
   //Serial.println("reading");
   radio.read(&text, sizeof(text));
    
    Serial.println(text);

    Serial.println(text[0]);
    
 
    if(text[0]=='f'){Serial.println("forward");
    digitalWrite(PB6,HIGH);
    digitalWrite(PB7,HIGH);
    delay(800);
    digitalWrite(PB6,LOW);
    digitalWrite(PB7,LOW);}
    else if(text[0]=='b'){Serial.println("backward");
    digitalWrite(PB5,HIGH);
    digitalWrite(PB8,HIGH);delay(800);digitalWrite(PB5,LOW);
    digitalWrite(PB8,LOW);}
    else if(text[0]=='l'){Serial.println("left");digitalWrite(PB5,HIGH);delay(800);digitalWrite(PB5,LOW);digitalWrite(PB6,LOW);}
    else if(text[0]=='r'){Serial.println("right");digitalWrite(PB7,HIGH);delay(800);digitalWrite(PB8,LOW);digitalWrite(PB7,LOW);}
    else{}
    }
    
    
    
    
    
    delay(100);
    }
   
