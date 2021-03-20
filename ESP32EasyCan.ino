//Tested on esp32-wroom
//D4-TX
//D5-RX

#include <CAN.h>

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("CAN Receiver");

  // start the CAN bus at 500 kbps
  if (!CAN.begin(500E3)) {
    Serial.println("Starting CAN failed!");
    while (1);
  }
}

void loop() {
  int data1;
  int data2;
  int data3;
  int data4;
  int data5;
  int data6;
  int data7;
  int data8;
  // try to parse packet
  int packetSize = CAN.parsePacket();

  if (packetSize) {
    // received a packet
   // Serial.print("ID: ");
    if (CAN.packetExtended()) {
    //  Serial.print("d1");
    //  Serial.print("extended ");
    }
    if (CAN.packetRtr()) 
    {
     // Serial.print("d2");
      // Remote transmission request, packet contains no data
      //Serial.print("RTR ");
    }
    //Serial.print("packet with id 0x");
    if (CAN.packetRtr()) {
 //     Serial.print("d3");
 //     Serial.print(" and requested length ");
 //     Serial.println(CAN.packetDlc());
    } else
//--------------------------------------------------------------------------    Serial.print(CAN.packetId(), HEX);//Shows ID: 2E4
    if ( 0 == 0 ){
//----------------------------------------------------------------------------      Serial.print(packetSize); //Packet Size (8)
//*********Serial.print(CAN.packetId(), HEX);
//*******Serial.print(packetSize);
data1=00;
data2=00;
data3=00;
data4=00;
data5=00;
data6=00;
data7=00;
data8=00;
Serial.print("  ");
//Serial.print((CAN.packetId()));
Serial.print(CAN.packetId(), HEX); //you can change HEX to DEC for your prefrance
Serial.print("# ");
// This part splits the code into 8 parts (it's not perfect)
      while (CAN.available()) {
        data1=CAN.read();
          data2=CAN.read();
            data3=CAN.read();
              data4=CAN.read();
                data5=CAN.read();
                  data6=CAN.read();
                    data7=CAN.read();
                      data8=CAN.read();
                      
        //****BACKUP***** Serial.print((String)CAN.read());
        //Serial.print(packetSize + (String)CAN.read());//Shows ALL OF THE DATA
      }
Serial.print(data1,HEX);//you can change HEX to DEC for your prefrance
Serial.print(data2,HEX);
Serial.print(data3,HEX);
Serial.print(data4,HEX);
Serial.print(data5,HEX);
Serial.print(data6,HEX);
Serial.print(data7,HEX);
Serial.print(data8,HEX);
Serial.print("    Size: ");
Serial.print(packetSize); //size of packet
Serial.println("");
    }
  }
}
