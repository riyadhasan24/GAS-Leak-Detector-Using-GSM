#include <SoftwareSerial.h>
SoftwareSerial MY_Serial(8, 9);

int Buzzer = 13;
int GAS_Sensor = A0;
int GAS_Sensor_Value;
String Message_Body = "GAS Leaking...! Do Something...!";

void setup() 
{
 MY_Serial.begin(9600);
 pinMode(Buzzer, INPUT); 
}

void loop() 
{   
  GAS_Sensor_Value = analogRead(GAS_Sensor);
  Serial.println(GAS_Sensor_Value);
  if (GAS_Sensor_Value >= 400)
    {
      digitalWrite(Buzzer, HIGH);
      Send_Message();
      delay(5000);
      digitalWrite(Buzzer, LOW);
    }
}

void Send_Message()
{
  MY_Serial.println("AT+CMGF=1");
  delay(1000);
  MY_Serial.println("AT+CMGS=\"+8801730288553\"\r"); // Change the number as you need
  delay(1000);
  MY_Serial.println(Message_Body);//the content of the message
  delay(200);
  MY_Serial.println((char)26);
  delay(1000);
}
