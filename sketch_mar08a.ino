#define BLYNK_TEMPLATE_ID "TMPL6Ja8_BdQ9"
#define BLYNK_TEMPLATE_NAME "Air Pollution Detection and Monitoring System"
#define BLYNK_AUTH_TOKEN "AY8fiy4VnSJOgWaCTisSNtk4OEgBaaKv"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#include <DHT.h> 

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Alif's iPhone"; 
char pass[] = "12345678";

BlynkTimer timer;

DHT dht(26,DHT11);  

void setup()
{
    pinMode (2, INPUT);//MQ-2,Flammable Gas & Smoke
    pinMode (4, INPUT);//MQ-3,Alcohol Gas
    pinMode (12,INPUT);//MQ-4,Methane Natural Gas
    pinMode (13,INPUT);//MQ-6,LPG Gas
    pinMode (14,INPUT);//MQ-7,Carbon Monoxide Gas
    pinMode (27,INPUT);//MQ-135,Ammonium sulfide and Benzene steam Gas

    pinMode (2, OUTPUT);//MQ-2,Flammable Gas & Smoke
    pinMode (4, OUTPUT);//MQ-3,Alcohol Gas
    pinMode (12,OUTPUT);//MQ-4,Methane Natural Gas
    pinMode (13,OUTPUT);//MQ-6,LPG Gas
    pinMode (14,OUTPUT);//MQ-7,Carbon Monoxide Gas
    pinMode (27,OUTPUT);//MQ-135,Ammonium sulfide and Benzene steam Gas   
    
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);
   
    dht.begin();
    delay(2000);  
}
void sendSensor () 
{
     
     //MQ-2,Flammable Gas & Smoke 
     int a = analogRead(2); 
     Serial.print("Flammable Gas & Smoke ");
     Serial.print(a);
     Serial.println(" ppm");
     delay(1500);
     
     //MQ-3,Alcohol Gas
     int b = analogRead(4);
     Serial.print("Alcohol Gas ");
     Serial.print((float)b/10000);
     Serial.println(" mg/L");
     delay(1500);
     
     //MQ-4,Methane Natural Gas
     int c = analogRead(12);
     Serial.print("Methane Natural Gas ");
     Serial.print(c);
     Serial.println(" ppm");
     delay(1500);
    
     //MQ-6,LPG Gas
     int d = analogRead(13);
     Serial.print("Liquefied petroleum Gas (LPG) ");
     Serial.print(d);
     Serial.println(" ppm");
     delay(1500);
    
     //MQ-7,Carbon Monoxide Gas
     int e = analogRead(14);
     Serial.print("Carbon Monoxide Gas ");
     Serial.print(e);
     Serial.println(" ppm");
     delay(1500);
    
     //MQ-135,Ammonium sulfide and Benzene steam Gas
     int f = analogRead(27);
     Serial.print("Ammonium sulfide and Benzene steam Gas ");
     Serial.print(f);
     Serial.println(" ppm");
     delay(1500);
    
     Serial.println();

     // DHT11,Temperature & Humidity sensor
     float t = dht.readTemperature();
     Serial.print("Temperature ");  
     Serial.print(t); 
     Serial.println("°C"); 
     float h = dht.readHumidity();
     Serial.print("Humidity ");  
     Serial.print(h);  
     Serial.println("%");
     delay(1500);    

     Blynk.virtualWrite(V0,t);
     Blynk.virtualWrite(V1,h);
     Blynk.virtualWrite(V2,a);
     Blynk.virtualWrite(V3,b);
     Blynk.virtualWrite(V4,c);
     Blynk.virtualWrite(V5,d);
     Blynk.virtualWrite(V6,e);
     Blynk.virtualWrite(V7,f);
     
}

void loop ()
{
  Blynk.run();
  timer.run();
}
