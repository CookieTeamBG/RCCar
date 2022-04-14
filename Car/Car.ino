
#include <RH_ASK.h>
#include <SPI.h> 

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
        String data = (char*)buf;
        Serial.println(data);
    }
}
