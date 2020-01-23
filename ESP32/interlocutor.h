#ifndef INTERLOCUTOR_H
#define INTERLOCUTOR_H

#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>

#include <dht.h>
#include "sensor_LDR.h"
#include "higrometro.h"
#include "valvula.h"

class INTERLOCUTOR
{
public:
    INTERLOCUTOR(char* nome, char* chave);
    bool inicializador_web();

    byte get_modo();

    void ler_json(string json);
    string json_maker(LDR_object sensorLDR, Higro_object sensor_umidade, dht DHT, Valvula solenoide);
    void website(LDR_object sensorLDR, Higro_object sensor_umidade, dht DHT, Valvula solenoide);

private:
    HTTPClient _http;
    byte _modo;

    char* REDE;
    char* SENHA;
};

#endif