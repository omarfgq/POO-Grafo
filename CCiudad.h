# ifndef CCIUDAD_H
# define CCIUDAD_H
# include <iostream>


using namespace std;

class CCiudad{
    private:
        string nombre;
        int costo;
        float calificacion;
    public:
        CCiudad(){}
        ~CCiudad(){}
        CCiudad *oDato;
        string categoria[7];
        void setNombre(string);
        string getNombre();
        void setCosto(int);
        int getCosto();
        void setCalificacion(float);
        float getCalificacion();


};


# endif