#include "interlocutor.h"

const String WEBSITE        = "http://casie.herokuapp.com/upload";

const String LUMINOSIDADE   = "\"LUMINOSIDADE\":";
const String UMIDADE_SOLO   = "\"UMIDADE_SOLO\":";
const String MODO           = "\"MODO\":";
const String STATUS_VALVULA = "\"STATUS_VALVULA\":";

Interlocutor::Interlocutor(const char* nome, const char* chave)
{
    REDE  = nome;
    SENHA = chave;
}

int Interlocutor::get_modo()
{
    return _modo;
}

void Interlocutor::vigia(LDR_object sensorLDR, Higro_object sensor_umidade, Valvula solenoide)
{
    if(Serial.avaliable() > 0)
    {
        String vigia_temp = Serial.readString();
        ler_json(vigia_temp);
    }
}

void Interlocutor::ler_json(String json)
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

String Interlocutor::json_maker(LDR_object sensorLDR, Higro_object sensor_umidade, dht DHT, Valvula solenoide)
{
    int luminosidade   = sensor_LDR.valor_LDR();
    float umidade_solo = sensor_umidade.valor_umidade_solo();
    String estado_valv = solenoide.get_estado();

    return  "{" + LUMINOSIDADE + String(luminosidade) + "," +
                UMIDADE_SOLO + String(umidade_solo) + "," +
                MODO + String(get_modo()) + "," +
                STATUS_VALVULA + estado_valv +
            "}";
}

bool Interlocutor::inicializador_web()
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

void Interlocutor::set_velocidades(int v_serial, int v_web)
{
    velocidade_serial = v_serial;
    velocidade_web = v_web;
}

void Interlocutor::website(LDR_object sensorLDR, Higro_object sensor_umidade, Valvula solenoide)
{
    _http.begin(WEBSITE);
    _http.addHeader("Content-Type", "application/json");
    _http.POST(json_maker(sensorLDR, sensor_umidade, solenoide));
    _http.end();
}
