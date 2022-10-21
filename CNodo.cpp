# include "CNodo.h"


CNodo::CNodo(){
    pIzq = NULL;
    pDer = NULL;
}

void CNodo::insertar(CCiudad *nD){
    if(toTheLeft(nD->oDato->getCosto())){
        if(pIzq == NULL){
            pIzq = new CNodo;
            pIzq->fDato = nD;
        }
        else{
            pIzq->insertar(nD);
        }
    }
    else{
        if(pDer == NULL){
            pDer = new CNodo;
            pDer->fDato = nD;
        }
        else{
            pDer->insertar(nD);
        }
    }
}


bool CNodo::toTheLeft(int nD){
    if(nD > fDato->getCosto()){
        return true;
    }
    else{
        return false;
    }
}


void CNodo::preOrden(CNodo *pRaiz){
    if(pRaiz == NULL){
        return;
    }
    else{
        std::cout<<pRaiz->fDato->getCosto()<<",";
        pRaiz->preOrden(pRaiz->pIzq);
        pRaiz->preOrden(pRaiz->pDer);
    }

}


void CNodo::postOrden(CNodo *pRaiz){
   
    if(pRaiz == NULL){
        return;
    }
    else{
        pRaiz->postOrden(pRaiz->pIzq);
        pRaiz->postOrden(pRaiz->pDer);
        std::cout<<pRaiz->fDato->getCosto()<<",";
    }


}




void CNodo::inOrden(CNodo *pRaiz){
    
    if(pRaiz == NULL){
        return;

    }
    else{
        fflush(stdin);
        inOrden(pRaiz->pIzq);
        std::cout<<"      Nombre: "<<pRaiz->fDato->getNombre()<<std::endl;
        std::cout<<"       Costo: "<<pRaiz->fDato->getCosto()<<std::endl;
        std::cout<<"Calificacion: "<<pRaiz->fDato->getCalificacion()<<std::endl;
        std::cout<<"   Categoria: "<<pRaiz->fDato->categoria[0]<<std::endl;
        for(int i=1;i<=6;i++){
            std::cout<<"   Categoria: "<<pRaiz->fDato->categoria[i]<<std::endl;
        }
        inOrden(pRaiz->pDer);
    }

} 


int CNodo::cuantosHijosTienes(){
    int k=0;

    if(pIzq != NULL){
        k++;
    }
    if(pDer != NULL){
        k++;
    }
    return k;

}


CNodo *CNodo::dameUnicoHijo(){

    if(pIzq != NULL && pDer == NULL){
        return pIzq;

    }
    else if(pIzq == NULL && pDer != NULL){
        return pDer;
    }
    else{
        return NULL;
    }

}


CNodo *CNodo::extremaDer(){
    CNodo *pActual;
    pActual = pDer;
    while(pActual->pDer != NULL){
        pActual = pActual->pDer;
    }
    return pActual;
}






void CNodo::insertarC(CCamino *nD){
    if(toTheLeft(nD->oDato->getCostoC())){
        if(pIzq == NULL){
            pIzq = new CNodo;
            pIzq->oCamino = nD;
        }
        else{
            pIzq->insertarC(nD);
        }
    }
    else{
        if(pDer == NULL){
            pDer = new CNodo;
            pDer->oCamino = nD;
        }
        else{
            pDer->insertarC(nD);
        }
    }
}


bool CNodo::toTheLeftC(int nD){
    if(nD > oCamino->getCostoC()){
        return true;
    }
    else{
        return false;
    }
}


void CNodo::inOrdenC(CNodo *pRaiz){
    
    if(pRaiz == NULL){
        return;

    }
    else{
        fflush(stdin);
        inOrden(pRaiz->pIzq);
        std::cout<<"   Distancia: "<<pRaiz->oCamino->getDistancia()<<std::endl;
        std::cout<<"       Costo: "<<pRaiz->oCamino->getCostoC()<<std::endl;
        inOrden(pRaiz->pDer);
    }

} 

