#include "monitor.h"
#include <Arduino.h>

Medida GrupoBarometros::medir(){
    Medida resultado = {
        .DD = this->DD->medir(),
        .DE = this->DE->medir(),
        .TD = this->TD->medir(),
        .TE = this->TE->medir()
    };
    return resultado;
}

void GrupoBarometros::enviar(Medida m){
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
    this->DD = DD;
    this->DE = DE;
    this->TD = TD;
    this->TE = TE;
}