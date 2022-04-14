
#include <RH_ASK.h>
#include <SPI.h>
#include <AFMotor.h>

RH_ASK driver;



void setup()
{
    Serial.begin(115200);	
    Serial.println();
    Serial.println("Starting Driver");
    if (!driver.init())
    {
         Serial.println("init failed");

    }else{
      Serial.println("init success!");
    }
      
}

void loop()
{
    uint8_t buf[100];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen))
    {
	    int i;

	    driver.printBuffer("Got:", buf, buflen);

      // received data form the transmitter
      String data = (char*)buf;
      Serial.println(data);

      if (data == "motor1")
      {
        
      }

    }
}
