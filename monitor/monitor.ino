#include "monitor.h"

// implementação de um braômetro com base na abstrata Barometro
class BarTeste : public Barometro {
    double medir() override {
        return 0.0;
    }
};

// instanciar os barômetros e colocar em variáveis para não sair de escopo
BarTeste DD;
BarTeste DE;
BarTeste TD;
BarTeste TE;
// inicializar a variável "barometros" obrigatória
GrupoBarometros barometros(&DD, &DE, &TD, &TE);

void setup(){
    Serial.begin(9600);
}

void loop(){
    barometros.medir_e_enviar();
    delay(100);
}
