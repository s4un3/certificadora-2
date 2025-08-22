namespace monitorDePressao {
  typedef class {
    public:
      // medir deve retornar a pressão em bar (14.5 psi)
      virtual double medir();
  } Barometro;

  typedef struct {
    double DD;
    double DE;
    double TD;
    double TE;
  } Medida;

  // T = traseiro, D = dianteiro
  // D = direita, E = esquerda
  Barometro bar_DD;
  Barometro bar_DE;
  Barometro bar_TD;
  Barometro bar_TE;

  Medida medir(){
    Medida resultado = {
      .DD = bar_DD.medir(),
      .DE = bar_DE.medir(),
      .TD = bar_TD.medir(),
      .TE = bar_TE.medir()
    };
    return resultado;
  }

  void enviar(Medida m){
    static bool iniciou_serial = false;
    if (!iniciou_serial){
      Serial.begin(9600);
      iniciou_serial = true;
    }

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

    Serial.print("\t\"DE\": ");
    Serial.println(m.DE);

    Serial.println("}");
  }

  void medir_e_enviar(){
    enviar(medir());
  }
}
