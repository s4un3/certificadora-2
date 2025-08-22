#include "monitor.h"

class BarTeste : public Barometro {
    double medir() override {
        return 0.0;
    }
};

BarTeste DD;
BarTeste DE;
BarTeste TD;
BarTeste TE;
GrupoBarometros barometros = {.DD = &DD, .DE = &DE, .TD = &TD, .TE = &TE};

void setup(){
    Serial.begin(9600);
}

void loop(){
    medir_e_enviar();
    delay(100);
}
