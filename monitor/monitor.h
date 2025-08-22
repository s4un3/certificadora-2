// T = traseiro, D = dianteiro
// D = direita, E = esquerda

typedef struct {
    double DD;
    double DE;
    double TD;
    double TE;
} Medida;

class Barometro {
    public:
        // medir deve retornar a pressão em bar (14.5 psi)
        virtual double medir() = 0;
};

typedef struct {
    Barometro* DD;
    Barometro* DE;
    Barometro* TD;
    Barometro* TE;
} GrupoBarometros;

Medida medir();

void enviar(Medida m);

void medir_e_enviar();
