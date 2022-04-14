#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

#define leftMotorPIN_FORWARD = 0;
#define rightMotorPIN_FORWARD = 0;
#define leftMotorPIN_BACKWARD = 0;
#define rightMotorPIN_BACKWARD = 0;

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

    pinMode(13, OUTPUT);
}

void loop()
{
    uint8_t buf[3];
    uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen))
  {
	  int i;

	  driver.printBuffer("Got:", buf, buflen);

    String data = (char*)buf;
    Serial.println(data);
    String command = data;

    switch (command)
    {
      case: "RF": // right motor - forward
     
        break;

      case: "RB": // right motor - backward
     
        break;

      case: "LF": // left motor - forward
     
        break;

      case: "LB": // left motor - backward
     
        break;

      default: break;
    }
  }
}
