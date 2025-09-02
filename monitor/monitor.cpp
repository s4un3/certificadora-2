#include "monitor.h"
#include <Arduino.h>

Medida GrupoBarometros::medir(){
    // criar uma medida, com cada campo correspondente a cada pneu
    // lembrando que this é um ponteiro, por isso "this->"
    Medida resultado = {
        .DD = this->DD->medir(),
        .DE = this->DE->medir(),
        .TD = this->TD->medir(),
        .TE = this->TE->medir()
    };
    return resultado;
}

void GrupoBarometros::enviar(Medida m){
    // enviar a medida por serial, formatado como json
    Serial.println("{");

    Serial.print("\t\"DD\": ");
    Serial.print(m.DD);
    Serial.println(",");

    Serial.print("\t\"DE\": ");
    Serial.print(m.DE);
    Serial.println(",");

    Serial.print("\t\"TD\": ");
    Serial.print(m.TD);
    Serial.println(",");

    Serial.print("\t\"TE\": ");
    Serial.println(m.DE);

    Serial.println("}");
}

void GrupoBarometros::medir_e_enviar(){
    enviar(medir());
}

GrupoBarometros::GrupoBarometros(Barometro* DD, Barometro* DE, Barometro* TD, Barometro* TE) {
    // construtor que coloca cada barômetro no seu lugar certo
    this->DD = DD;
    this->DE = DE;
    this->TD = TD;
    this->TE = TE;
}
