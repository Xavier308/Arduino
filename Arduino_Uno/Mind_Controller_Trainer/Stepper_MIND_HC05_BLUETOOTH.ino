////////////////////////////////////////////////////////////////////////
// Mind Concentration Trainer
// 
// This project allows users to control a servo motor using brain activity,
// creating the illusion of telekinetic control over a metal ball.
// 
// Based on example code provided by NeuroSky, Inc. (license free)
// and modified to control a servo motor based on attention levels.
//
// Required Hardware:
// - NeuroSky's Mindwave Mobile brainwave device
// - Arduino Uno
// - HC-05 Bluetooth module
// - MG 996R Servo motor
// - Metal ball and pulley system
//
// Modified by Xavier J. Cruz
////////////////////////////////////////////////////////////////////////

#include <Servo.h> 

Servo servo; // servo object representing the MG 996R servo


#define LED 13
#define BAUDRATE 57600
#define DEBUGOUTPUT 0



#define powercontrol 10

// checksum variables
byte generatedChecksum = 0;
byte checksum = 0; 
int payloadLength = 0;
byte payloadData[64] = {
  0};
byte poorQuality = 0;
byte attention = 0;
byte meditation = 0;

// system variables
long lastReceivedPacket = 0;
boolean bigPacket = false;

//////////////////////////
// Microprocessor Setup //
//////////////////////////
void setup() {

  servo.attach(3); // servo is wired to Arduino on digital pin 3

  pinMode(LED, OUTPUT);
  Serial.begin(BAUDRATE);           // USB

}

////////////////////////////////
// Read data from Serial UART //
////////////////////////////////
byte ReadOneByte() {
  int ByteRead;

  while(!Serial.available());
  ByteRead = Serial.read();

#if DEBUGOUTPUT  
  Serial.print((char)ByteRead);   // echo the same byte out the USB serial (for debug purposes)
#endif

  return ByteRead;
}

/////////////
//MAIN LOOP//
/////////////
void loop() {


  // Look for sync bytes
  if(ReadOneByte() == 170) {
    if(ReadOneByte() == 170) {

      payloadLength = ReadOneByte();
      if(payloadLength > 169)                      //Payload length can not be greater than 169
          return;

      generatedChecksum = 0;        
      for(int i = 0; i < payloadLength; i++) {  
        payloadData[i] = ReadOneByte();            //Read payload into memory
        generatedChecksum += payloadData[i];
      }   

      checksum = ReadOneByte();                      //Read checksum byte from stream      
      generatedChecksum = 255 - generatedChecksum;   //Take one's compliment of generated checksum

        if(checksum == generatedChecksum) {    

        poorQuality = 200;
        attention = 0;
        meditation = 0;

        for(int i = 0; i < payloadLength; i++) {    // Parse the payload
          switch (payloadData[i]) {
          case 2:
            i++;            
            poorQuality = payloadData[i];
            bigPacket = true;            
            break;
          case 4:
            i++;
            attention = payloadData[i];                        
            break;
          case 5:
            i++;
            meditation = payloadData[i];
            break;
          case 0x80:
            i = i + 3;
            break;
          case 0x83:
            i = i + 25;      
            break;
          default:
            break;
          } // switch
        } // for loop

#if !DEBUGOUTPUT

        // *** Add your code here ***

        if(bigPacket) {
          if(poorQuality == 0)
            digitalWrite(LED, HIGH);
          else
            digitalWrite(LED, LOW);
          Serial.print("PoorQuality: ");
          Serial.print(poorQuality, DEC);
          Serial.print(" Attention: ");
          Serial.print(attention, DEC);
          Serial.print(" Time since last packet: ");
          Serial.print(millis() - lastReceivedPacket, DEC);
          lastReceivedPacket = millis();
          Serial.print("\n");

          switch(attention / 10) {
          case 0:
            servo.write(0); // move MG996R's shaft to angle 0°
            delay(1000); // wait for one second          
            break;
          case 1:
            servo.write(5); // move MG996R's shaft to angle 5°
            delay(1000); // wait for one second 
            break;
          case 2:
            servo.write(20); // move MG996R's shaft to angle 20°
            delay(1000); // wait for one second
            break;
          case 3:              
            servo.write(40); // move MG996R's shaft to angle 40°
            delay(1000); // wait for one second             
            break;
          case 4:
            servo.write(60); // move MG996R's shaft to angle 60°
            delay(1000); // wait for one second             
            break;
          case 5:
           servo.write(80); // move MG996R's shaft to angle 80°
           delay(1000); // wait for one second               
            break;
          case 6:              
            servo.write(100); // move MG996R's shaft to angle 100°
            delay(1000); // wait for one second               
            break;
          case 7:
            servo.write(120); // move MG996R's shaft to angle 120°
            delay(1000); // wait for one second              
            break;    
          case 8:
            servo.write(140); // move MG996R's shaft to angle 140°
            delay(1000); // wait for one second 
            break;
          case 9:
            servo.write(160); // move MG996R's shaft to angle 160°
            delay(1000); // wait for one second
            break;
          case 10:
            servo.write(180); // move MG996R's shaft to angle 180°
            delay(1000); // wait for one second
            break;           
          }                     
        }
#endif        
        bigPacket = false;        
      }
      else {
        // Checksum Error
      }  // end if else for checksum
    } // end if read 0xAA byte
  } // end if read 0xAA byte
}
