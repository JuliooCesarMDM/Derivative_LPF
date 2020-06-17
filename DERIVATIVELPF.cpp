#include "DERIVATIVELPF.h"

int16_t DiscreteLPF_To_Derivative_PID(int16_t DerivativeInput) {
  //FILTRO PASSA BAIXA DISCRETO
  //FILTRA O NOISE DA ALTA FREQUENCIA,ASSIM EVITANDO O DERIVATIVO DO CONTROLADOR PID DE FICAR LOUCO
  //FREQUENCIA DE CORTE PARA O CALCULO DO DERIVATIVO >> 20HZ
  //http://en.wikipedia.org/wiki/Low-pass_filter.
  uint8_t              Frequency_CuttOff = 20;
  int16_t              Derivative_To_LPF = DerivativeInput;
  static float         Store_Previous_Derivative;
  static uint32_t      Store_Previous_Time;
  uint32_t             LPF_DeltaTime     = millis() - Store_Previous_Time;
  float                LPF_Delta_Time;
  Store_Previous_Time                    = millis();
  LPF_Delta_Time                         = (float)LPF_DeltaTime / 1000.0f;
  if (Store_Previous_Time == 0 || LPF_DeltaTime > 1000) {
    LPF_DeltaTime = 0;
    //Reset_Integral_PID(); //RESETA O INTEGRAL DO CONTROLADOR PID
  }
  float CutOffEquation      = 1 / (2 * PI * Frequency_CuttOff);
  Derivative_To_LPF          = Store_Previous_Derivative + ((LPF_Delta_Time / (CutOffEquation + LPF_Delta_Time)) *
                               (Derivative_To_LPF - Store_Previous_Derivative));
  Store_Previous_Derivative  = Derivative_To_LPF;
  return Derivative_To_LPF;
}
