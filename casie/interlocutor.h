#ifndef INTERLOCUTOR_H
#define INTERLOCUTOR_H

#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>

#include "sensor_LDR.h"
#include "higrometro.h"
#include "valvula.h"

class INTERLOCUTOR
{
public:
    INTERLOCUTOR(const char* nome, const char* chave);
    
    int get_modo();

    void vigia(LDR_object sensorLDR, Higro_object sensor_umidade, Valvula solenoide);
    void ler_json(string json);
    string json_maker(LDR_object sensorLDR, Higro_object sensor_umidade, Valvula solenoide);

    bool inicializador_web();
    void set_velocidades(int v_serial, int v_web);
    void website(LDR_object sensorLDR, Higro_object sensor_umidade, Valvula solenoide);

private:
    HTTPClient _http;
    int _modo;

    char* REDE;
    char* SENHA;

    int velocidade_serial = 1000;
    int velocidade_web    = 1000;
    
    unsigned long tempo_serial = 0;
    unsigned long tempo_http   = 0;
};

#endif