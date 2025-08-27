// D = dianteiro, T = traseiro
// D = direita, E = esquerda

typedef struct {
    double DD;
    double DE;
    double TD;
    double TE;
} Medida;

class Barometro {
    public:
        // por convenção, medir deve retornar a pressão em bar (14.5 psi)
        virtual double medir() = 0;
};

class GrupoBarometros {
    public:
        Barometro* DD;
        Barometro* DE;
        Barometro* TD;
        Barometro* TE;
        Medida medir();
        void enviar(Medida m);
        void medir_e_enviar();
        GrupoBarometros(Barometro* DD, Barometro* DE, Barometro* TD, Barometro* TE);
};
