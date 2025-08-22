#include "monitor.h"
#include <Arduino.h>

extern GrupoBarometros barometros;

Medida medir(){
    Medida resultado = {
        .DD = barometros.DD->medir(),
        .DE = barometros.DE->medir(),
        .TD = barometros.TD->medir(),
        .TE = barometros.TE->medir()
    };
    return resultado;
}

void enviar(Medida m){
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

void medir_e_enviar(){
    enviar(medir());
}
