# ifndef CARBOL_H
# define CARBOL_H
# include "CNodo.h"
//# include "CSerializable.h"

//# define CLSID_CArbol 1000;

//class CArbol: public CSerializable{
class CArbol{
    private:    
        CNodo *pRaiz;
    public:
        CArbol();
        ~CArbol(){}
        void insertarA(CCiudad *);
        void inOrdenA();
        void preOrdenA();
        void postOrdenA();
        CNodo *buscarMalPadre(string,int);
        CCiudad *buscarDato(string,int);
        void eliminacion(string,int);

        void insertarAC(CCamino *);
        void inOrdenAC();
        CNodo *buscarMalPadreC(int,int);
        CCamino *buscarDatoC(int,int);
        void eliminacionC(int,int);

        /*
        void Orden(CNodo *,fstream& out);
        virtual void salvar(fstream& out);
        virtual void cargar(fstream& in){}
        virtual int getCLSID();
        */
        
        friend class CTablaHash;
};

# endif