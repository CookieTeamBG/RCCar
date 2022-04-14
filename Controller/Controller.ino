#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h>;
#endif1

RH_ASK driver(2000, 4, 5, 0); 

void setup()
{
#ifdef RH_HAVE_SERIAL
    Serial.begin(115200);	  
    Serial.println();
    
    Serial.println("Starting Driver");
#endif
    if (!driver.init())
#ifdef RH_HAVE_SERIAL
         Serial.println("init failed");
#else
	;
#endif
}

void loop()
{
    const char *msg = "motor1";

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(200);
}
