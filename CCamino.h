# ifndef CCAMINO_H
# define CCAMINO_H


class CCamino{
    private:
        int distancia;
        int costoC;
        float dAproximada;
    public:
        CCamino(){}
        ~CCamino(){}
        CCamino *oDato;
        void setDistancia(int);
        int getDistancia();
        void setCostoC(int);
        int getCostoC();
        void setAprox(int);
        int getAprox();
};

# endif