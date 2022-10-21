# include "CTablaHash.h"


void CTablaHash::datos(){
    
  

    CTablaHash tabla1;
    CTablaHash tabla2;


    fflush(stdin);
    for(int i = 0;i<=19;i++){
        tabla1.tabla[i].oDato = NULL;
    }

    CCiudad *ciudad1 = new CCiudad;
    ciudad1->setNombre("Guadalajara");
    ciudad1->setCosto(1025);
    ciudad1->setCalificacion(88);
    ciudad1->categoria[0] = "Cultural";
    ciudad1->categoria[1] = "Biologia";
    ciudad1->categoria[2] = "Religion";
    ciudad1->categoria[3] = "Historia";
    ciudad1->categoria[4] = "Gastronomia";


    CCiudad *ciudad2 = new CCiudad;
    ciudad2->setNombre("Zapopan");
    ciudad2->setCosto(1428);
    ciudad2->setCalificacion(85);
    ciudad2->categoria[0] = "Centros comerciales";
    ciudad2->categoria[1] = "Espectaculo";
    ciudad2->categoria[2] = "Gastronomia";
    ciudad2->categoria[3] = "Deporte";
    ciudad2->categoria[4] = "Religion";
    ciudad2->categoria[5] = "Ecologia";
    ciudad2->categoria[6] = "Historia";


    CCiudad *ciudad3 = new CCiudad;
    ciudad3->setNombre("San Pedro tlaquepaque");
    ciudad3->setCosto(1748);
    ciudad3->setCalificacion(83);
    ciudad3->categoria[0] = "Artesania";
    ciudad3->categoria[1] = "Cultural";
    ciudad3->categoria[2] = "Historia";
    ciudad3->categoria[3] = "Religion";
    ciudad3->categoria[4] = "Deporte";


    CCamino *camino1 = new CCamino;
    camino1->setDistancia(80);
    camino1->setCostoC(500);

    CCamino *camino2 = new CCamino;
    camino2->setDistancia(90);
    camino2->setCostoC(400);

    tabla2.insertarC(camino1);
    tabla2.insertarC(camino2);

    tabla1.insertar(ciudad1);
    tabla1.insertar(ciudad2);
    tabla1.insertar(ciudad3);

    CCiudad *obj;

    std::cout<<tabla1.busqueda("San Pedro tlaquepaque",1748)->getNombre()<<std::endl;
    std::cout<<tabla1.busqueda("San Pedro tlaquepaque",1748)->getCosto()<<std::endl;
    std::cout<<tabla1.busqueda("San Pedro tlaquepaque",1748)->getCalificacion()<<std::endl;
    std::cout<<tabla1.busqueda("San Pedro tlaquepaque",1748)->categoria[0]<<std::endl;
 
 
    std::cout<<"Distancia: "<<tabla2.busquedaC(80,500)->getDistancia()<<std::endl;
    std::cout<<"Costo: "<<tabla2.busquedaC(80,500)->getCostoC()<<std::endl;

    tabla2.eliminarC(80,500);
    tabla1.eliminar("Zapopan",1428);
    

    tabla1.imprimir();
    tabla2.imprimirC();

}


int CTablaHash::fnHash(string nombre,int costo){
    return (nombre.length()+costo) % longitudA;
}


void CTablaHash::insertar(CCiudad *pN){
    int indice;
    indice = fnHash(pN->getNombre(),pN->getCosto());
    fflush(stdin);
    if(tabla[indice].oDato == NULL){
        tabla[indice].oDato = pN;
    }
    else{
        arreglo[indice].insertarA(pN);
    }
}


void CTablaHash::imprimir(){
    for(int i = 0;i<=19;i++){
        if(tabla[i].oDato != NULL){
            std::cout<<"\nEn la tabla indice|"<<i<<"|: ";
            std::cout<<"Nombre: "<<tabla[i].oDato->getNombre()<<std::endl;
            std::cout<<"                       Costo : "<<tabla[i].oDato->getCosto()<<std::endl;
            std::cout<<"                 Calificacion: "<<tabla[i].oDato->getCalificacion()<<std::endl;
            std::cout<<"                    Categoria: "<<tabla[i].oDato->categoria[0]<<std::endl;
            for(int j=1;j<=6;j++){
                std::cout<<"                               "<<tabla[i].oDato->categoria[j]<<std::endl;
            }
        }
        arreglo[i].inOrdenA();
        
    }
    std::cout<<"\n\n\n";
}

void CTablaHash::eliminar(string nombre,int costo){
    int indice;
    indice = fnHash(nombre,costo);

    if(tabla[indice].oDato->getNombre() == nombre && tabla[indice].oDato->getCosto() == costo ){
        delete tabla[indice].oDato;
        tabla[indice].oDato = NULL;
    }
    else{
        arreglo[indice].eliminacion(nombre,costo);
    }
    
}

CCiudad *CTablaHash::busqueda(string nombre,int costo){
    int indice;
    indice = fnHash(nombre,costo);

    if(tabla[indice].oDato->getNombre() == nombre && tabla[indice].oDato->getCosto() == costo ){
        return tabla[indice].oDato;
    }
    else{
       arreglo[indice].buscarDato(nombre,costo);
    }



}



/*
void CTablaHash::salvar(fstream& out){
    out<<getCLSID()<<endl;

    for(int i = 0;i<=16;i++){
        if(tabla[i].oDato != NULL){
            tabla[i].oDato->salvar(out);
        }
        arreglo[i].salvar(out);
    }
}

int CTablaHash::getCLSID(){
    return CLSID_CTablaHash;
}
*/



int CTablaHash::fnHashC(int distancia,int costo){
    return(distancia+costo) % longitudC;
}


void CTablaHash::insertarC(CCamino *pN){
    int indice;
    indice = fnHashC(pN->getDistancia(),pN->getCostoC());
    fflush(stdin);
    if(tablaC[indice].oDato == NULL){
        tablaC[indice].oDato = pN;
    }
    else{
        arreglo[indice].insertarAC(pN);
    }
}


void CTablaHash::imprimirC(){
    for(int i = 0;i<=49;i++){
        if(tablaC[i].oDato != NULL){
            std::cout<<"\nEn la tabla indice|"<<i<<"|: ";
            std::cout<<"Distancia: "<<tablaC[i].oDato->getDistancia()<<std::endl;
            std::cout<<"Costo: "<<tablaC[i].oDato->getCostoC()<<std::endl;
            
        }
        arregloC[i].inOrdenAC();
        
    }
    std::cout<<"\n\n\n";
}

void CTablaHash::eliminarC(int distancia,int costo){
    int indice;
    indice = fnHashC(distancia,costo);

    if(tablaC[indice].oDato->getDistancia() == distancia && tablaC[indice].oDato->getCostoC() == costo ){
        delete tabla[indice].oDato;
        tablaC[indice].oDato = NULL;
    }
    else{
        arregloC[indice].eliminacionC(distancia,costo);
    }
    
}

CCamino *CTablaHash::busquedaC(int distancia,int costo){
    int indice;
    indice = fnHashC(distancia,costo);

    if(tablaC[indice].oDato->getDistancia() == distancia ){
        return tablaC[indice].oDato;
    }
    else{
       arregloC[indice].buscarDatoC(distancia,costo);
    }



}