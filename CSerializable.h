# ifndef CSERIALIZABLE_H
# define CSERIALIZABLE_H
# include <fstream>
# include <iostream>

using namespace std;

class CSerializable{
    private:

    public:
        virtual void salvar(fstream& out) = 0;
        virtual void cargar(fstream& in) = 0;
        virtual int getCLSID() = 0;

};

# endif