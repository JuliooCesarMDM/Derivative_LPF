#include "DERIVATIVELPF.h"

/******************************INFO***********************************************************/
//AUTOR:JULIO CESAR MATIAS
//DESENVOLVIDO OFICIALMENTE PARA A CONTROLADORA DE VOO JCFLIGHT
//DESCRIÇÃO:FILTRO PASSA BAIXA PARA APLICAÇÃO NO TERMO DERIVATIVO DO SISTEMA CONTROLADOR PID
//DATA:JANEIRO DE 2019
/*********************************************************************************************/


void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print(analogRead(0));
  Serial.print(" ");
  Serial.print(DiscreteLPF_To_Derivative_PID(analogRead(0))); //AQUI É O TERMO DERIVATIVO(D) DO CONTROLADOR PID,O ANALOGREAD É APENAS PARA EXEMPLO
  Serial.println();
}
