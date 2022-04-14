
#include <RH_ASK.h>
#include <SPI.h>
#include <AFMotor.h>

RH_ASK driver;

//AF_DCMotor motor1(1);
//AF_DCMotor motor2(2);

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

    //motors
    //motor1.setSpeed(255);
    //motor2.setSpeed(255);
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
        digitalWrite(13, HIGH);
        deley(1000);
        digitalWrite(13, LOW);
        deley(1000);

        // motor 1
        //motor1.run(RELEASE);
        //motor1.run(FORWARD);

        // motor 2
        //motor2.run(RELEASE);
        //motor2.run(FORWARD);
      }
    }
}
