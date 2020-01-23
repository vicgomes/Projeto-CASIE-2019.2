#include "interlocutor.h"

const string WEBSITE        = "link do heroku";

const string LUMINOSIDADE   = "\"LUMINOSIDADE\":";
const string UMIDADE_SOLO   = "\"UMIDADE_SOLO\":";
const string UMIDADE_AR     = "\"UMIDADE_AR\":";
const string TEMPERATURA    = "\"TEMPERATURA\":";
const string MODO           = "\"MODO\":";
const string STATUS_VALVULA = "\"STATUS_VALVULA\":";

INTERLOCUTOR::INTERLOCUTOR(char* nome, char* chave)
{
    REDE  = nome;
    SENHA = chave;
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

byte INTERLOCUTOR::get_modo()
{
    return _modo;
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
    float umidade_ar   = DHT.humidity;
    float temperatura  = DHT.temperature;
    string estado_valv = solenoide.get_estado();

    return  "{" + LUMINOSIDADE + String(luminosidade) + "," +
                UMIDADE_SOLO + String(umidade_ar) + "," +
                UMIDADE_AR + String(umidade_ar) + "," +
                TEMPERATURA + String(temperatura) +
                MODO + String(_modo) +
                STATUS_VALVULA + estado_valv +
            "}";
}

void INTERLOCUTOR::website(LDR_object sensorLDR, Higro_object sensor_umidade, dht DHT, Valvula solenoide)
{
    _http.begin(WEBSITE);
    _http.addHeader("Content-Type", "application/json");
    _http.POST(json_maker(LDR_object sensorLDR, Higro_object sensor_umidade, dht DHT, Valvula solenoide));
    _http.end();
}