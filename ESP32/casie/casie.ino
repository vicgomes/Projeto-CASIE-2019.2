#include <dht.h>
#include "sensor_LDR.h"
#include "higrometro.h"
#include "valvula.h"
#include "interlocutor.h"

const char* WIFI  = "ESP32";
const char* CHAVE = "senhacriativa";

#define pino_DHT22 A1

uint32_t temporizador = 0;

INTERLOCUTOR interlocutor(WIFI, CHAVE);
Valvula solenoide(A3);
LDR_object sensorLDR(A0);
Higrometro_object sensor_umidade(A2);
dht DHT22;

void setup() {
  pinMode(pino_LDR, INPUT);
  pinMode(pino_DHT22, INPUT);
  pinMode(pino_higrometro, INPUT);
  Serial.begin(9600);  
}

void loop() {
  float umidade_ar = 0;
  float temperatura = 0;
  
  if(millis() - temporizador >= 5000)
  {
    DHT22.read22(pino_DHT22);

    umidade_ar = DHT22.humidity;
    temperatura = DHT22.temperature;

    /*
      códigos pra se comunicar com o QT
    */

    temporizador = millis();          // atualizando
  }
  
}
