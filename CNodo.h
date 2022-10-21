# ifndef CNODO_H
# define CNODO_H
# include <iostream>
# include "CCiudad.h"
# include "CCamino.h"

using namespace std;

class CNodo{
    private:
        CCiudad *fDato;
        CCamino *oCamino;
        CNodo *pIzq;
        CNodo *pDer;
    private:    
        CNodo();
        ~CNodo(){}
        void insertar(CCiudad *);
        bool toTheLeft(int);
        void inOrden(CNodo *);
        void preOrden(CNodo *);
        void postOrden(CNodo *);
        int cuantosHijosTienes();
        CNodo *dameUnicoHijo();
        CNodo *extremaDer();
        void insertarC(CCamino *);
        bool toTheLeftC(int);
        void inOrdenC(CNodo *);


    friend class CArbol;


};

# endif