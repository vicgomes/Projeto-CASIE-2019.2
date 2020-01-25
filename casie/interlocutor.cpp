#include "interlocutor.h"

const string WEBSITE        = "http://casie.herokuapp.com/upload";

const string LUMINOSIDADE   = "\"LUMINOSIDADE\":";
const string UMIDADE_SOLO   = "\"UMIDADE_SOLO\":";
const string MODO           = "\"MODO\":";
const string STATUS_VALVULA = "\"STATUS_VALVULA\":";

INTERLOCUTOR::INTERLOCUTOR(char* nome, char* chave)
{
    REDE  = nome;
    SENHA = chave;
}

byte INTERLOCUTOR::get_modo()
{
    return _modo;
}

void vigia(LDR_object sensorLDR, Higro_object sensor_umidade, Valvula solenoide)
{
    if(Serial.avaliable() > 0)
    {
        string vigia_temp = Serial.readString();
        ler_json(vigia_temp);
    }

    if(millis() - tempo_serial >= velocidade_serial)
    {
        tempo_serial = millis();
        json_maker(sensorLDR, sensor_umidade, solenoide);
    }

    if(millis() - tempo_http >= velocidade_web)
    {
        tempo_web = millis();
        website(sensorLDR, sensor_umidade, solenoide);
    }
}

void INTERLOCUTOR::ler_json(string json)
{
    if(json.startsWith("{") and json.endsWith("}"))
    {
        if(json.indexOf(MODO + " 1")>0)
        {
            _modo = 1;                     // automático
        }
        else if(json.indexOf(MODO + " 2")>0)
        {
            _modo = 2;                     // manual
        }
    }
}

string INTERLOCUTOR::json_maker(LDR_object sensorLDR, Higro_object sensor_umidade, dht DHT, Valvula solenoide)
{
    int luminosidade   = sensor_LDR.valor_LDR();
    float umidade_solo = sensor_umidade.umidade_solo();
    string estado_valv = solenoide.get_estado();

    return  "{" + LUMINOSIDADE + String(luminosidade) + "," +
                UMIDADE_SOLO + String(umidade_solo) + "," +
                MODO + String(get_modo()) + "," +
                STATUS_VALVULA + estado_valv +
            "}";
}

bool INTERLOCUTOR::inicializador_web()
{
    bool nivel_logico;

    WiFi.begin(_REDE, _SENHA);
    delay(2000);

    if(WiFi.status() != WL_CONNECTED)
    {
        nivel_logico = false;
    }
    else
    {
        nivel_logico = true;
    }
    return nivel_logico;
}

void set_velocidades(int v_serial, int v_web)
{
    velocidade_serial = v_serial;
    velocidade_web = v_web;
}

void INTERLOCUTOR::website(LDR_object sensorLDR, Higro_object sensor_umidade, Valvula solenoide)
{
    _http.begin(WEBSITE);
    _http.addHeader("Content-Type", "application/json");
    _http.POST(json_maker(sensorLDR, sensor_umidade, solenoide));
    _http.end();
}