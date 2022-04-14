#include <RH_ASK.h>
#include <SPI.h>;

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
    int leftXJoystick = analogRead(0);
    const char *msg = "qwe";
    Serial.println(leftXJoystick);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(200);
}
