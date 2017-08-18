#include <DHT22.h>
// Only used for sprintf
#include <stdio.h>
// Data wire is plugged into port 7 on the Arduino
// Connect a 4.7K resistor between VCC and the data pin (strong pullup)
#define DHT22_PIN 7
// Setup a DHT22 instance
#include <EmonLib.h>;                    // Incluimos Emon Library
 
EnergyMonitor emon1;                   // Creamos la instancia de la librería
#define CT  A1
#define CT  A0

DHT22 myDHT22(DHT22_PIN);
int rede = 110;
float a = 23.6;
char temp[5];
char humdty[5];
char curr[5];
char pot[5];

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  emon1.current(A1, 17); //medido
  emon1.current(A0, 17); //medido
  //Serial.println("DHT22 Library Demo");
}

void loop(void)
{ 
  double Irms = emon1.calcIrms(1480);
  DHT22_ERROR_t errorCode;
  errorCode = myDHT22.readData();
  
      
      
     //char *valorUm = dtostrf(myDHT22.getTemperatureC(),4,2,temp);
     //char *valorDois = dtostrf(myDHT22.getHumidity(),4,2,humdty);
     //char *valorTres = dtostrf(Irms,4,2,curr);
     //double potences = Irms*rede;
     //char *valorQuatro = dtostrf(potences,4,2,pot);
     
     
     
     //delay(1000);
     //char* myStrings[]={valorUm, valorDois, valorTres,valorQuatro};

     //String str =  String(myDHT22.getTemperatureC());
     //str += String('i');
     //str += String(myDHT22.getHumidity());
     
     
     
     
     //Serial.println(str);
     
     //delay(1000);
     
     //String strDois = String(Irms);
    // strDois += String('i');
     //strDois += String(Irms*rede);
     
     //Serial.println(strDois);

      delay(2000);
      Serial.print("T=");
      Serial.print(myDHT22.getTemperatureC());
      //delay(3000);
      //Serial.print("C ");
      Serial.print("=H=");
      Serial.print(myDHT22.getHumidity());
      //delay(3000);
      //Serial.println("%");
      //Serial.println("/");
      //Serial.print(" Consumo: ");
      Serial.print("=I=");
      Serial.print(Irms);
      //delay(3000);
      //Serial.println("/");
      //Serial.print(" Potencia: ");
      Serial.print("=P=");
      Serial.print(Irms*rede);
      Serial.print("K");
     // Serial.println("--");
      
}
