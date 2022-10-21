# include "CArbol.h"

CArbol::CArbol(){
    pRaiz = NULL;
}

void CArbol::insertarA(CCiudad *nD){
    if(pRaiz == NULL){
        pRaiz = new CNodo;
        pRaiz->fDato = nD;
    }
    else{
        pRaiz->insertar(nD);
    }
}

void CArbol::preOrdenA(){
    if(pRaiz == NULL){
        return;
    }
    else{
        std::cout<<"\n\nPreOrden"<<std::endl;
        pRaiz->preOrden(pRaiz);
    }
    std::cout<<"\n\n";
}


void CArbol::postOrdenA(){
    if(pRaiz == NULL){
        return;
    }
    else{
        std::cout<<"\n\nPostOrden"<<std::endl;
        pRaiz->postOrden(pRaiz);
        
    }
    std::cout<<"\n\n";
}

void CArbol::inOrdenA(){
    if(pRaiz == NULL){
        return;
    }
    else{
        std::cout<<"\n\nInOrden"<<std::endl;
        pRaiz->inOrden(pRaiz);
    }
    std::cout<<"\n\n";
}


CNodo *CArbol::buscarMalPadre(string nombre,int nD){
    CNodo *pActual;
    pActual = pRaiz;

    while(pActual){
        if(pActual->fDato->getCosto() > nD){
            if(pActual->pDer == NULL){
                std::cout<<"No existe ese valor"<<std::endl;
                return NULL;
            }
            else if(pActual->pDer->fDato->getNombre() != nombre){
                pActual = pActual->pDer;
            }
            else if(pActual->pDer->fDato->getNombre() == nombre){
                return pActual;
            }
        }
        else{
            if(pActual->pIzq == NULL){
                std::cout<<"No existe ese valor"<<std::endl;
                return NULL;
            }
            else if(pActual->pIzq->fDato->getNombre() != nombre){
                pActual = pActual->pIzq;
            }
            else if(pActual->pIzq->fDato->getNombre() == nombre){
                return pActual;
            }

        }
    }

}




CCiudad *CArbol::buscarDato(string nombre,int nD){
    CNodo *pActual;
    pActual = pRaiz;

    while(pActual){
        if(pActual->fDato->getCosto() > nD){
            if(pActual->pDer == NULL){
                std::cout<<"No existe ese dato"<<std::endl;
                system("pause");
                return NULL;
            }
            else if(pActual->pDer->fDato->getNombre() != nombre){
                pActual = pActual->pDer;
            }
            else if(pActual->pDer->fDato->getNombre() == nombre){
                return pActual->pDer->fDato;
            }
        }
        else{
            if(pActual->pIzq == NULL){
                std::cout<<"No existe ese dato"<<std::endl;
                system("pause");
                return NULL;
            }
            else if(pActual->pIzq->fDato->getNombre() != nombre){
                pActual = pActual->pIzq;
            }
            else if(pActual->pIzq->fDato->getNombre() == nombre){
                return pActual->pIzq->fDato;
            }

        }
    }
    std::cout<<"No existe ese dato"<<std::endl;
    system("pause");

}




void CArbol::eliminacion(string nombre,int valor){

    if(valor == pRaiz->fDato->getCosto() && nombre == pRaiz->fDato->getNombre()){
        int opcion;
        opcion = pRaiz->cuantosHijosTienes();
        switch(opcion){
            case 0:
                delete pRaiz;
                pRaiz = NULL;
                break;
            case 1:
                CNodo *hijo;
                hijo = pRaiz->dameUnicoHijo();
                delete pRaiz;
                pRaiz = hijo;
                break;
            case 2:
                CNodo *nI;
                CNodo *nD;
                nI = pRaiz->pIzq;
                nD = pRaiz->pDer;
                delete pRaiz;
                pRaiz = nI;
                
                CNodo *extrema;
                extrema = nD;
                while(nI->pDer != NULL){
                    nI = nI->pDer;
                }
                nI->pDer = nD;
                break;
        }
    }

    else if(valor != pRaiz->fDato->getCosto() && nombre != pRaiz->fDato->getNombre()){
        CNodo *malPadre;
        malPadre = buscarMalPadre(nombre,valor);

        if(malPadre->toTheLeft(valor)){
            int opcion;
            opcion = malPadre->pIzq->cuantosHijosTienes();

            switch(opcion){
                case 0:
                    delete malPadre->pIzq;
                    malPadre->pIzq = NULL;
                    break;
                case 1:
                    CNodo *hijo;
                    hijo = malPadre->pIzq->dameUnicoHijo();
                    delete malPadre->pIzq;
                    malPadre->pIzq = hijo;
                    break;
                case 2:
                    CNodo *nI;
                    CNodo *nD;
                    nI = malPadre->pIzq->pIzq;
                    nD = malPadre->pIzq->pDer;
                    delete malPadre->pIzq;
                    malPadre->pIzq = nI;
                    
                    CNodo *extrema;
                    extrema = nI;
                    while(nI->pDer != NULL){
                        nI = nI->pDer;
                    }
                    nI->pDer = nD;

                    break;
            }       

        }
        else{
            int opcion;
            opcion = malPadre->pDer->cuantosHijosTienes();

            switch(opcion){
                case 0:
                    delete malPadre->pDer;
                    malPadre->pDer = NULL;
                    break;
                case 1:
                    CNodo *hijo;
                    hijo = malPadre->pDer->dameUnicoHijo();
                    delete malPadre->pDer;
                    malPadre->pDer = hijo;
                    break;
                case 2:
                    CNodo *nI;
                    CNodo *nD;
                    nI = malPadre->pDer->pDer;
                    nD = malPadre->pDer->pIzq;
                    delete malPadre->pDer;
                    malPadre->pDer = nD;
                    
                    CNodo *extrema;
                    extrema = nD->extremaDer();
                    extrema->pDer = nI;
                    break;
            }
        }

    }


}

/*
void CArbol::Orden(CNodo *pR,fstream&out){
   
    if(pR == NULL){
        return;

    }
    else{
        Orden(pR->pIzq,out);
        pR->fDato->salvar(out);
        Orden(pR->pDer,out);
    }


}
*/

/*
void CArbol::salvar(fstream& out){
    out<<getCLSID()<<endl;
    
    if(pRaiz == NULL){
        return;
    }
    else{  
        Orden(pRaiz,out);
    }
    std::cout<<"\n\n";



}

int CArbol::getCLSID(){
    return CLSID_CArbol;
}
*/




void CArbol::insertarAC(CCamino *nD){
    if(pRaiz == NULL){
        pRaiz = new CNodo;
        pRaiz->oCamino = nD;
    }
    else{
        pRaiz->insertarC(nD);
    }
}


void CArbol::inOrdenAC(){
    if(pRaiz == NULL){
        return;
    }
    else{
        std::cout<<"\n\nInOrden"<<std::endl;
        pRaiz->inOrdenC(pRaiz);
    }
    std::cout<<"\n\n";
}


CNodo *CArbol::buscarMalPadreC(int distancia,int costo){
    CNodo *pActual;
    pActual = pRaiz;

    while(pActual){
        if(pActual->oCamino->getDistancia() > distancia){
            if(pActual->pDer == NULL){
                std::cout<<"No existe ese valor"<<std::endl;
                return NULL;
            }
            else if(pActual->pDer->oCamino->getDistancia() != distancia){
                pActual = pActual->pDer;
            }
            else if(pActual->pDer->oCamino->getDistancia() == distancia){
                return pActual;
            }
        }
        else{
            if(pActual->pIzq == NULL){
                std::cout<<"No existe ese valor"<<std::endl;
                return NULL;
            }
            else if(pActual->pIzq->oCamino->getDistancia() != distancia){
                pActual = pActual->pIzq;
            }
            else if(pActual->pIzq->oCamino->getDistancia() == distancia){
                return pActual;
            }

        }
    }

}


CCamino *CArbol::buscarDatoC(int distancia,int costo){
    CNodo *pActual;
    pActual = pRaiz;

    while(pActual){
        if(pActual->oCamino->getDistancia() > distancia){
            if(pActual->pDer == NULL){
                std::cout<<"No existe ese dato"<<std::endl;
                system("pause");
                return NULL;
            }
            else if(pActual->pDer->oCamino->getDistancia() != distancia){
                pActual = pActual->pDer;
            }
            else if(pActual->pDer->oCamino->getDistancia() == distancia){
                return pActual->pDer->oCamino;
            }
        }
        else{
            if(pActual->pIzq == NULL){
                std::cout<<"No existe ese dato"<<std::endl;
                system("pause");
                return NULL;
            }
            else if(pActual->pIzq->oCamino->getDistancia() != distancia){
                pActual = pActual->pIzq;
            }
            else if(pActual->pIzq->oCamino->getDistancia() == distancia){
                return pActual->pIzq->oCamino;
            }

        }
    }
    std::cout<<"No existe ese dato"<<std::endl;
    system("pause");

}



void CArbol::eliminacionC(int distancia,int costo){

    if(costo == pRaiz->oCamino->getCostoC() && distancia == pRaiz->oCamino->getDistancia()){
        int opcion;
        opcion = pRaiz->cuantosHijosTienes();
        switch(opcion){
            case 0:
                delete pRaiz;
                pRaiz = NULL;
                break;
            case 1:
                CNodo *hijo;
                hijo = pRaiz->dameUnicoHijo();
                delete pRaiz;
                pRaiz = hijo;
                break;
            case 2:
                CNodo *nI;
                CNodo *nD;
                nI = pRaiz->pIzq;
                nD = pRaiz->pDer;
                delete pRaiz;
                pRaiz = nI;
                
                CNodo *extrema;
                extrema = nD;
                while(nI->pDer != NULL){
                    nI = nI->pDer;
                }
                nI->pDer = nD;
                break;
        }
    }

    else if(costo != pRaiz->oCamino->getCostoC() && distancia != pRaiz->oCamino->getDistancia()){
        CNodo *malPadre;
        malPadre = buscarMalPadreC(distancia,costo);

        if(malPadre->toTheLeft(distancia)){
            int opcion;
            opcion = malPadre->pIzq->cuantosHijosTienes();

            switch(opcion){
                case 0:
                    delete malPadre->pIzq;
                    malPadre->pIzq = NULL;
                    break;
                case 1:
                    CNodo *hijo;
                    hijo = malPadre->pIzq->dameUnicoHijo();
                    delete malPadre->pIzq;
                    malPadre->pIzq = hijo;
                    break;
                case 2:
                    CNodo *nI;
                    CNodo *nD;
                    nI = malPadre->pIzq->pIzq;
                    nD = malPadre->pIzq->pDer;
                    delete malPadre->pIzq;
                    malPadre->pIzq = nI;
                    
                    CNodo *extrema;
                    extrema = nI;
                    while(nI->pDer != NULL){
                        nI = nI->pDer;
                    }
                    nI->pDer = nD;

                    break;
            }       

        }
        else{
            int opcion;
            opcion = malPadre->pDer->cuantosHijosTienes();

            switch(opcion){
                case 0:
                    delete malPadre->pDer;
                    malPadre->pDer = NULL;
                    break;
                case 1:
                    CNodo *hijo;
                    hijo = malPadre->pDer->dameUnicoHijo();
                    delete malPadre->pDer;
                    malPadre->pDer = hijo;
                    break;
                case 2:
                    CNodo *nI;
                    CNodo *nD;
                    nI = malPadre->pDer->pDer;
                    nD = malPadre->pDer->pIzq;
                    delete malPadre->pDer;
                    malPadre->pDer = nD;
                    
                    CNodo *extrema;
                    extrema = nD->extremaDer();
                    extrema->pDer = nI;
                    break;
            }
        }

    }


}