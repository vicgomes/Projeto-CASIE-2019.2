#include <interlocutor.h>
#include <higrometro.h>
#include <sensor_LDR.h>
#include <valvula.h>

const char* WIFI  = "ESP32";
const char* CHAVE = "senhacriativa";

uint32_t temporizador = 0;

INTERLOCUTOR interlocutor(WIFI, CHAVE);
Higrometro_object sensor_umidade(34);
LDR_object sensorLDR(32);
Valvula solenoide(12);                   // relé para a válvula

#define LUM_MIN 15
#define UMIDADE_SOLO_MIN 400
#define UMIDADE_SOLO_MAX 679

void setup()
{
  Serial.begin(9600);

  interlocutor.inicializador_web();
  interlocutor.set_velocidades(500,500);
}

void loop()
{
  sensorLDR.ler();
  sensor_umidade.ler();
  
  switch(interlocutor.get_modo())
  {
    case 1:
      automatico();
      break;
    case 2:
      manual();
      break;
  }  
}

//////////////////////////////////////////////////////////////
//Funções

void automatico()
{
  
  if(sensorLDR.valor_LDR() < 15)
  {
    solenoide.desativar();    
  }
  
  else if(sensorLDR.valor_LDR() > 15)
  {
    
    if(sensor_umidade.umidade_solo() < UMIDADE_SOLO_MIN)
    {
      solenoide.desativar();
    }
    
    else if(sensor_umidade.umidade_solo() > UMIDADE_SOLO_MAX)
    {
      solenoide.desativar();
    }
    
    else if(sensor_umidade.umidade_solo() > UMIDADE_SOLO_MIN and
            sensor_umidade.umidade_solo() < UMIDADE_SOLO_MAX)
    {
      solenoide.ativar();
    }
    
  }
}



void manual()
{
  
}