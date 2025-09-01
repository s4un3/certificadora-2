// D = dianteiro, T = traseiro
// D = direita, E = esquerda

// struct dos dados de uma medida
// cada double é um pneu
typedef struct {
    double DD;
    double DE;
    double TD;
    double TE;
} Medida;

// classe que corresponde a um barômetro com um método abstrato (virtual) de medir
class Barometro {
    public:
        // por convenção, medir deve retornar a pressão em bar (14.5 psi)
        virtual double medir() = 0;
};

// os quatro barômetros
// métodos de medir, enviar e medir e enviar
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
