# ifndef CTABLAHASH_H
# define CTABLAHASH_H
# include "CArbol.h"
# include <iostream>
# include <string.h>
//# include "CSerializable.h"

//# define CLSID_CTablaHash 1200

using namespace std;

//class CTablaHash: public CSerializable{
class CTablaHash{
    public:
        CArbol arreglo[20];
        int longitudA = 20;  
        CCiudad tabla[20];
        CArbol arregloC[50];
        int longitudC = 50;  
        CCamino tablaC[50];
        CCamino tabla_ad[50][50];
       
    public:
        CTablaHash(){}
        ~CTablaHash(){}
        int fnHash(string,int); 
        void insertar(CCiudad *); 
        CCiudad *busqueda(string,int); 
        void eliminar(string,int); 
        void imprimir(); 
        void datos();

        int fnHashC(int,int); 
        void insertarC(CCamino *); 
        CCamino *busquedaC(int,int); 
        void eliminarC(int,int); 
        void imprimirC();
        /*
        virtual void salvar(fstream& out);
        virtual void cargar(fstream& in){}
        virtual int getCLSID();
        */

};

# endif