#ifndef INTERLOCUTOR_H
#define INTERLOCUTOR_H

#include <ETH.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiSTA.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

#include <HTTPClient.h>

#include "Arduino.h"

#include "sensor_LDR.h"
#include "higrometro.h"
#include "valv.h"

class Interlocutor
{
public:
    Interlocutor(const char* nome, const char* chave);
    
    int get_modo();

    void vigia(LDR_object sensorLDR, Higro_object sensor_umidade, Valvula solenoide);
    void ler_json(String json);
    String json_maker(LDR_object sensorLDR, Higro_object sensor_umidade, Valvula solenoide);

    bool inicializador_web();
    void set_velocidades(int v_serial, int v_web);
    void website(LDR_object sensorLDR, Higro_object sensor_umidade, Valvula solenoide);

private:
    HTTPClient _http;
    int _modo;

    const char* REDE;
    const char* SENHA;

    int velocidade_serial = 1000;
    int velocidade_web    = 1000;
    
    unsigned long tempo_serial = 0;
    unsigned long tempo_http   = 0;
};

#endif
