# include <iostream>
# define cValor 999
# include "CCiudad.h"
# include "CCamino.h"
# include "CTablaHash.h"
using namespace std;


void menu();
void menu1();

int main(){


    menu1();

    

    system("pause");
    return 0;
}

void menu1(){

    CTablaHash tab;
    CTablaHash tab2;
    CCiudad ciudades[50];
    CCamino caminos[50][50];
    int opcion;
    string cNombre;
    int cCosto;
    float cCalificacion;
    int cDistancia;
    string cCategoria;
    int lug = 0;
    int opcion1;
    int cOrigen;
    int cDestino;
    int opcionM;
    int nCiudad;
    float cCal;

    fflush(stdin);
    for(int i = 0;i<=19;i++){
        tab.tabla[i].oDato = NULL;
    }

    
    fflush(stdin);
    for(int i=0;i<49;i++){
        for(int j=0;j<49;j++){
            caminos[i][j].oDato = NULL;
        }
    }
    



    do{
        system("cls");
        fflush(stdin);
        std::cout<<"|| Menu ||"<<std::endl;
        std::cout<<"1.-Insertar ciudad"<<std::endl;
        std::cout<<"2.-Insertar camino"<<std::endl;
        std::cout<<"3.-Mostrar datos"<<std::endl;
        std::cout<<"4.-Modificar ciudad o camino"<<std::endl;
        std::cout<<"5.-Eliminar ciudad"<<std::endl;
        std::cout<<"6.-Salir"<<std::endl;
        std::cout<<"Seleccione: ";
        cin>>opcion;

        if(opcion == 1){
            system("cls");
            int pos = 0;
            int n = 0;
            fflush(stdin);
            std::cout<<"Insertando datos\n"<<std::endl;
            std::cout<<"Digite el nombre: ";
            cin>>cNombre;
            std::cout<<"Digite el costo: ";
            cin>>cCosto;
            std::cout<<"Digite la calificacion: ";
            cin>>cCalificacion;

            CCiudad *ciudad = new CCiudad;
            ciudad->setNombre(cNombre);
            ciudad->setCosto(cCosto);
            ciudad->setCalificacion(cCalificacion);
            do{
                std::cout<<"Digite la categoria: ";
                cin>>cCategoria;
                ciudad->categoria[pos] = cCategoria;
                std::cout<<"Digite |1|Agregar categoria|2|Salir: ";
                cin>>opcion1;
                pos++;
            }while(opcion1 != 2 && pos <= 6);
            
            

            tab.insertar(ciudad);

            ciudades[lug].oDato = tab.busqueda(cNombre,cCosto);
            std::cout<<ciudades[lug].oDato->getNombre()<<std::endl;
            system("pause");
            lug++;
        }
        if(opcion == 2){
            system("cls");
            fflush(stdin);
            std::cout<<"Ciudades con las que se puede generar camino\n"<<std::endl;
            for(int i=0;i<lug;i++){
                std::cout<<"["<<i<<"]"<<ciudades[i].oDato->getNombre()<<std::endl;                
            }
            std::cout<<"\nInsertando camino\n"<<std::endl;
            std::cout<<"Digite primera ciudad: ";
            cin>>cOrigen;
            std::cout<<"Digite la segunda ciudad: ";
            cin>>cDestino;
            std::cout<<"Digite la distancia: ";
            cin>>cDistancia;
            std::cout<<"Digite el costo: ";
            cin>>cCosto;


            CCamino *camino = new CCamino;
            camino->setDistancia(cDistancia);
            camino->setCostoC(cCosto);
            
            tab2.insertarC(camino);
            
            caminos[cOrigen][cDestino].oDato = tab2.busquedaC(cDistancia,cCosto);
            caminos[cDestino][cOrigen].oDato = tab2.busquedaC(cDistancia,cCosto);
            

        }
        if(opcion == 3){
            system("cls");
            fflush(stdin);
            for(int i=0;i<lug;i++){
                if(ciudades[i].oDato != NULL){
                    std::cout<<"_________________________________________"<<std::endl;
                    std::cout<<"Mostrando ciudad"<<std::endl;
                    std::cout<<"      Nombre: "<<ciudades[i].oDato->getNombre()<<std::endl;
                    std::cout<<"       Costo: $"<<ciudades[i].oDato->getCosto()<<std::endl;
                    std::cout<<"Calificacion: "<<ciudades[i].oDato->getCalificacion()<<std::endl;
                    std::cout<<"   Categoria: "<<ciudades[i].oDato->categoria[0]<<std::endl;
                    for(int j=1;j<7;j++){
                        std::cout<<"            "<<ciudades[i].oDato->categoria[j]<<std::endl;
                    }
                    std::cout<<"Desde esta ciudad se puede ir a: "<<std::endl;
                
                    for(int k=0;k<lug;k++){
                        if(caminos[i][k].oDato != NULL){
                            //std::cout<<"\n\nAccesible desde: "<<colo[i].getNombre()<<std::endl;
                            std::cout<<"          Ciudad: "<<ciudades[k].oDato->getNombre()<<std::endl;
                            std::cout<<"           Costo: $"<<ciudades[k].oDato->getCosto()<<std::endl;
                            std::cout<<"    Calificacion: "<<ciudades[k].oDato->getCalificacion()<<std::endl;
                            std::cout<<"       Distancia: "<<caminos[i][k].oDato->getDistancia()<<"Km"<<std::endl;
                            std::cout<<"Costo transporte: $"<<caminos[i][k].oDato->getCostoC()<<std::endl;
                            std::cout<<"La ciudad ofrece: ";
                            for(int j=0;j<7;j++){
                                if(j == 0){
                                    std::cout<<""<<ciudades[k].oDato->categoria[j]<<std::endl;
                                }
                                else{
                                    std::cout<<"                  "<<ciudades[k].oDato->categoria[j]<<std::endl;    
                                }
                            }
                            std::cout<<"\n"<<std::endl;
                        }
                    }
                }
                
            }
            system("pause");
        }

        if(opcion == 4){
            system("cls");
            fflush(stdin);
            do{
                std::cout<<"Modificando ciudad\n"<<std::endl;
                std::cout<<"1.-Modificar nombre de ciudad"<<std::endl;
                std::cout<<"2.-Modificar costo de ciudad"<<std::endl;
                std::cout<<"3.-Modificar calificacion de ciudad"<<std::endl;
                std::cout<<"4.-Modificar distancia de camino"<<std::endl;
                std::cout<<"5.-Modificar costo de camino"<<std::endl;
                std::cout<<"6.-Eliminar camino"<<std::endl;
                std::cout<<"7.-Volver al menu principal"<<std::endl;

                std::cout<<"\nSeleccione: ";
                cin>>opcionM;

                if(opcionM == 1){
                    system("cls");
                    fflush(stdin);
                    for(int i=0;i<lug;i++){
                        if(ciudades[i].oDato != NULL){
                            std::cout<<"["<<i<<"]"<<ciudades[i].oDato->getNombre()<<std::endl;
                        }
                    }
                    std::cout<<"Modificando nombre"<<std::endl;
                    std::cout<<"Digite el numero de la ciudad: "<<std::endl;
                    cin>>nCiudad;
                    std::cout<<"Digite el nuevo nombre: ";
                    cin>>cNombre;

                    tab.busqueda(ciudades[nCiudad].oDato->getNombre(),ciudades[nCiudad].oDato->getCosto())->setNombre(cNombre);

                    ciudades[nCiudad].oDato->setNombre(cNombre);
                }
                if(opcionM == 2){
                    system("cls");
                    fflush(stdin);
                    for(int i=0;i<lug;i++){
                        if(ciudades[i].oDato != NULL){
                            std::cout<<"["<<i<<"]"<<ciudades[i].oDato->getNombre()<<std::endl;
                        }
                    }
                    std::cout<<"Modificando costo"<<std::endl;
                    std::cout<<"Digite el numero de la ciudad: "<<std::endl;
                    cin>>nCiudad;
                    std::cout<<"Digite el nuevo costo: ";
                    cin>>cCosto;
                    
                    tab.busqueda(ciudades[nCiudad].oDato->getNombre(),ciudades[nCiudad].oDato->getCosto())->setCosto(cCosto);

                    ciudades[nCiudad].oDato->setCosto(cCosto);

                }

                if(opcionM == 3){
                    system("cls");
                    fflush(stdin);
                    for(int i=0;i<lug;i++){
                        if(ciudades[i].oDato != NULL){
                            std::cout<<"["<<i<<"]"<<ciudades[i].oDato->getNombre()<<std::endl;
                        }
                    }
                    std::cout<<"Modificando calificacion"<<std::endl;
                    std::cout<<"Digite el numero de la ciudad: "<<std::endl;
                    cin>>nCiudad;
                    std::cout<<"Digite la nueva calificacion: ";
                    cin>>cCal;

                    tab.busqueda(ciudades[nCiudad].oDato->getNombre(),ciudades[nCiudad].oDato->getCosto())->setCalificacion(cCal);

                    ciudades[nCiudad].oDato->setCalificacion(cCal);
                }
                if(opcionM == 4){
                    system("cls");
                    fflush(stdin);
                    for(int i=0;i<lug;i++){
                        if(ciudades[i].oDato != NULL){
                            std::cout<<"["<<i<<"]"<<ciudades[i].oDato->getNombre()<<std::endl;
                        }
                    }
                    std::cout<<"Modificando distancia"<<std::endl;
                    std::cout<<"\n\nDigite el numero de la primera ciudad: ";
                    cin>>cOrigen;
                    std::cout<<"Digite el numero de la segunda ciudad: ";
                    cin>>cDestino;
                    std::cout<<"Digite la nueva distancia"<<std::endl;
                    cin>>cDistancia;

                    tab2.busquedaC(caminos[cOrigen][cDestino].oDato->getDistancia(),caminos[cOrigen][cDestino].oDato->getCostoC())->setDistancia(cDistancia);

                    caminos[cOrigen][cDestino].oDato->setDistancia(cDistancia);
                    caminos[cDestino][cOrigen].oDato->setDistancia(cDistancia);
                }

                if(opcionM == 5){
                    system("cls");
                    fflush(stdin);
                    for(int i=0;i<lug;i++){
                        if(ciudades[i].oDato != NULL){
                            std::cout<<"["<<i<<"]"<<ciudades[i].oDato->getNombre()<<std::endl;
                        }
                    }
                    std::cout<<"Modificando costo"<<std::endl;
                    std::cout<<"\n\nDigite el numero de la primera ciudad: ";
                    cin>>cOrigen;
                    std::cout<<"Digite el numero de la segunda ciudad: ";
                    cin>>cDestino;
                    std::cout<<"Digite el nuevo costo: "<<std::endl;
                    cin>>cCosto;

                    tab2.busquedaC(caminos[cOrigen][cDestino].oDato->getDistancia(),caminos[cOrigen][cDestino].oDato->getCostoC())->setCostoC(cCosto);

                    caminos[cOrigen][cDestino].oDato->setCostoC(cCosto);
                    caminos[cDestino][cOrigen].oDato->setCostoC(cCosto);

                }

                if(opcionM == 6){
                    system("cls");
                    fflush(stdin);
                    for(int i=0;i<lug;i++){
                        if(ciudades[i].oDato != NULL){
                            std::cout<<"["<<i<<"]"<<ciudades[i].oDato->getNombre()<<std::endl;
                        }
                    }
                    std::cout<<"Eliminado camino"<<std::endl;
                    std::cout<<"\n\nDigite el numero de la primera ciudad: ";
                    cin>>cOrigen;
                    std::cout<<"Digite el numero de la segunda ciudad: ";
                    cin>>cDestino;

                    tab2.eliminarC(caminos[cOrigen][cDestino].oDato->getDistancia(),caminos[cOrigen][cDestino].oDato->getCostoC());

                    caminos[cOrigen][cDestino].oDato = NULL;
                    caminos[cDestino][cOrigen].oDato = NULL;

                    std::cout<<"camino eliminado correctamente"<<std::endl;
                    system("pause");
                }

            }while(opcionM != 7);
        }
            
        if(opcion == 5){
            system("cls");
            fflush(stdin);
            for(int i=0;i<lug;i++){
                 if(ciudades[i].oDato != NULL){
                    std::cout<<"["<<i<<"]"<<ciudades[i].oDato->getNombre()<<std::endl;
                }
            }

            std::cout<<"Digite el numero de ciudad a eliminar"<<std::endl;
            cin>>nCiudad;
            tab.eliminar(ciudades[nCiudad].oDato->getNombre(),ciudades[nCiudad].oDato->getCosto());
            delete ciudades[nCiudad].oDato;
            ciudades[nCiudad].oDato = NULL; 

            for(int x = 0;x<lug;x++){
                caminos[nCiudad][x].oDato = NULL;
                caminos[x][nCiudad].oDato = NULL;
            }
            std::cout<<"Ciudad eliminada correctamente"<<std::endl;
            system("pause");
        }

        if(opcion == 6){
            system("cls");
            std::cout<<"Cerrando el programa\n\n"<<std::endl;
        }


    }while(opcion != 6);


}


void menu(){

    int opcion,opcion1;
    string cNombre;
    float cCosto,nDistancia,nCosto;
    float cCal;
    int cCiu = 20;
    int nCol;
    float cTraslado;
    float mCol;
    int cOrigen;
    int cDestino;
    int nCiudad;
    string cate;
    int opcionC,opcionM;
    CCamino mAdyacenciaC[50][50];
    CCiudad ciudad[50];

    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            mAdyacenciaC[i][j].setDistancia(cValor);
        }
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

    mAdyacenciaC[0][1].setDistancia(7);
    mAdyacenciaC[0][1].setCostoC(80);
    mAdyacenciaC[0][3].setDistancia(23);
    mAdyacenciaC[0][3].setCostoC(245);
    mAdyacenciaC[0][2].setDistancia(6);
    mAdyacenciaC[0][2].setCostoC(115);
    mAdyacenciaC[0][8].setDistancia(28);
    mAdyacenciaC[0][8].setCostoC(280);
    

    mAdyacenciaC[0][1].setAprox(6.71);
    mAdyacenciaC[0][2].setAprox(4.75);
    mAdyacenciaC[0][3].setAprox(22.70);
    mAdyacenciaC[0][4].setAprox(23.54);
    mAdyacenciaC[0][5].setAprox(37.38);
    mAdyacenciaC[0][6].setAprox(43.57);
    mAdyacenciaC[0][7].setAprox(70.37);
    mAdyacenciaC[0][8].setAprox(29.83);
    mAdyacenciaC[0][9].setAprox(58.96);
    mAdyacenciaC[0][10].setAprox(93.26);
    mAdyacenciaC[0][11].setAprox(63.54);
    mAdyacenciaC[0][12].setAprox(106.74);
    mAdyacenciaC[0][13].setAprox(71.30);
    mAdyacenciaC[0][14].setAprox(105.45);
    mAdyacenciaC[0][15].setAprox(36.81);
    mAdyacenciaC[0][16].setAprox(88.61);
    mAdyacenciaC[0][17].setAprox(123.86);
    mAdyacenciaC[0][18].setAprox(145.40);
    mAdyacenciaC[0][19].setAprox(195.44);
   

    ciudad[0].oDato = ciudad1;

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
    
    mAdyacenciaC[1][0].setDistancia(7);
    mAdyacenciaC[1][0].setCostoC(80);
    mAdyacenciaC[1][15].setDistancia(31);
    mAdyacenciaC[1][15].setCostoC(400);
   
    ciudad[1].oDato = ciudad2;


    CCiudad *ciudad3 = new CCiudad;
    ciudad3->setNombre("San Pedro tlaquepaque");
    ciudad3->setCosto(1748);
    ciudad3->setCalificacion(83);
    ciudad3->categoria[0] = "Artesania";
    ciudad3->categoria[1] = "Cultural";
    ciudad3->categoria[2] = "Historia";
    ciudad3->categoria[3] = "Religion";
    ciudad3->categoria[4] = "Deporte";
    
    mAdyacenciaC[2][0].setDistancia(6.8);
    mAdyacenciaC[2][0].setCostoC(115);
    mAdyacenciaC[2][8].setDistancia(25);
    mAdyacenciaC[2][8].setCostoC(260);
    mAdyacenciaC[2][5].setDistancia(32);
    mAdyacenciaC[2][5].setCostoC(450);
    mAdyacenciaC[2][4].setDistancia(20);
    mAdyacenciaC[2][4].setCostoC(230);

    ciudad[2].oDato = ciudad3;

    

    CCiudad *ciudad4 = new CCiudad;
    ciudad4->setNombre("Tlajomulco de zuniga");
    ciudad4->setCosto(1791);
    ciudad4->setCalificacion(80);
    ciudad4->categoria[0] = "Centros comerciales";
    ciudad4->categoria[1] = "Artesania";
    ciudad4->categoria[2] = "Gastronomia";
    ciudad4->categoria[3] = "Cultural";
    ciudad4->categoria[4] = "Musica";

    mAdyacenciaC[3][0].setDistancia(23);
    mAdyacenciaC[3][0].setCostoC(245);
    mAdyacenciaC[3][5].setDistancia(32);
    mAdyacenciaC[3][5].setCostoC(460);
    mAdyacenciaC[3][12].setDistancia(102);
    mAdyacenciaC[3][12].setCostoC(1300);
    mAdyacenciaC[3][18].setDistancia(106);
    mAdyacenciaC[3][18].setCostoC(1320);
    mAdyacenciaC[3][19].setDistancia(261);
    mAdyacenciaC[3][19].setCostoC(2500);
    mAdyacenciaC[3][13].setDistancia(70);
    mAdyacenciaC[3][13].setCostoC(900);
    mAdyacenciaC[3][15].setDistancia(35);
    mAdyacenciaC[3][15].setCostoC(480);

    ciudad[3].oDato = ciudad4;




    CCiudad *ciudad5 = new CCiudad;
    ciudad5->setNombre("El salto");
    ciudad5->setCosto(1558);
    ciudad5->setCalificacion(65);
    ciudad5->categoria[0] = "Musica";
    ciudad5->categoria[1] = "Cultural";
    ciudad5->categoria[2] = "Gastronomia";
    ciudad5->categoria[3] = "Religion";

    mAdyacenciaC[4][2].setDistancia(20);
    mAdyacenciaC[4][2].setCostoC(230);
    mAdyacenciaC[4][5].setDistancia(28);
    mAdyacenciaC[4][5].setCostoC(280);
    mAdyacenciaC[4][7].setDistancia(49);
    mAdyacenciaC[4][7].setCostoC(680);

    ciudad[4].oDato = ciudad5;



    CCiudad *ciudad6 = new CCiudad;
    ciudad6->setNombre("Ixtlahuacan de los membrillos");
    ciudad6->setCosto(2002);
    ciudad6->setCalificacion(75);
    ciudad6->categoria[0] = "Parque acuatico";
    
    mAdyacenciaC[5][2].setDistancia(32);
    mAdyacenciaC[5][2].setCostoC(450);
    mAdyacenciaC[5][4].setDistancia(27);
    mAdyacenciaC[5][4].setCostoC(280);
    mAdyacenciaC[5][7].setDistancia(49);
    mAdyacenciaC[5][7].setCostoC(680);
    mAdyacenciaC[5][6].setDistancia(4);
    mAdyacenciaC[5][6].setCostoC(40);
    mAdyacenciaC[5][3].setDistancia(32);
    mAdyacenciaC[5][3].setCostoC(460);

    ciudad[5].oDato = ciudad6;



    CCiudad *ciudad7 = new CCiudad;
    ciudad7->setNombre("Chapala");
    ciudad7->setCosto(2103);
    ciudad7->setCalificacion(84);
    ciudad7->categoria[0] = "Lago";
    ciudad7->categoria[1] = "Religion";
    ciudad7->categoria[2] = "Cultural";

    mAdyacenciaC[6][5].setDistancia(4);
    mAdyacenciaC[6][5].setCostoC(40);
    mAdyacenciaC[6][7].setDistancia(50);
    mAdyacenciaC[6][7].setCostoC(690);

    ciudad[6].oDato = ciudad7;



    CCiudad *ciudad8 = new CCiudad;
    ciudad8->setNombre("Ocotlan");
    ciudad8->setCosto(1250);
    ciudad8->setCalificacion(75);
    ciudad8->categoria[0] = "Religion";
    ciudad8->categoria[1] = "Historia";
    ciudad8->categoria[2] = "Cultural";
    ciudad8->categoria[3] = "Gastronomia";

    mAdyacenciaC[7][6].setDistancia(50);
    mAdyacenciaC[7][6].setCostoC(690);
    mAdyacenciaC[7][5].setDistancia(28);
    mAdyacenciaC[7][5].setCostoC(280);
    mAdyacenciaC[7][4].setDistancia(56);
    mAdyacenciaC[7][4].setCostoC(710);
    mAdyacenciaC[7][10].setDistancia(30);
    mAdyacenciaC[7][10].setCostoC(300);

    ciudad[7].oDato = ciudad8;



    CCiudad *ciudad9 = new CCiudad;
    ciudad9->setNombre("Zapotlanejo");
    ciudad9->setCosto(1235);
    ciudad9->setCalificacion(75);
    ciudad9->categoria[0] = "Cultural";
    ciudad9->categoria[1] = "Gastronomia";
    ciudad9->categoria[2] = "Historia";
    ciudad9->categoria[3] = "Deporte";
    ciudad9->categoria[4] = "Religion";

    mAdyacenciaC[8][0].setDistancia(28);
    mAdyacenciaC[8][0].setCostoC(280);
    mAdyacenciaC[8][11].setDistancia(40);
    mAdyacenciaC[8][11].setCostoC(635);
    mAdyacenciaC[8][9].setDistancia(29);
    mAdyacenciaC[8][9].setCostoC(295);
    mAdyacenciaC[8][2].setDistancia(25);
    mAdyacenciaC[8][2].setCostoC(260);

    ciudad[8].oDato = ciudad9;



    CCiudad *ciudad10 = new CCiudad;
    ciudad10->setNombre("Tototlan");
    ciudad10->setCosto(1068);
    ciudad10->setCalificacion(70);
    ciudad10->categoria[0] = "Religion";
    ciudad10->categoria[1] = "Arquitectura";
    ciudad10->categoria[2] = "Biologia";

    mAdyacenciaC[9][8].setDistancia(29);
    mAdyacenciaC[9][8].setCostoC(295);
    mAdyacenciaC[9][16].setDistancia(28);
    mAdyacenciaC[9][16].setCostoC(285);
    mAdyacenciaC[9][14].setDistancia(64);
    mAdyacenciaC[9][14].setCostoC(730);
    mAdyacenciaC[9][10].setDistancia(42);
    mAdyacenciaC[9][10].setCostoC(650);

    ciudad[9].oDato = ciudad10;



    CCiudad *ciudad11 = new CCiudad;
    ciudad11->setNombre("La barca");
    ciudad11->setCosto(1242);
    ciudad11->setCalificacion(75);
    ciudad11->categoria[0] = "Historia";
    ciudad11->categoria[1] = "Biologia";
    ciudad11->categoria[2] = "Deporte";

    mAdyacenciaC[10][9].setDistancia(42);
    mAdyacenciaC[10][9].setCostoC(650);
    mAdyacenciaC[10][7].setDistancia(30);
    mAdyacenciaC[10][7].setCostoC(300);

    ciudad[10].oDato = ciudad11;



    CCiudad *ciudad12 = new CCiudad;
    ciudad12->setNombre("Tepatitlan de Morelos");
    ciudad12->setCosto(1160);
    ciudad12->setCalificacion(78);
    ciudad12->categoria[0] = "Historia";
    ciudad12->categoria[1] = "Deporte";
    ciudad12->categoria[2] = "Arquitectura";
    ciudad12->categoria[3] = "Religion";

    mAdyacenciaC[11][8].setDistancia(40);
    mAdyacenciaC[11][8].setCostoC(635);
    mAdyacenciaC[11][17].setDistancia(58);
    mAdyacenciaC[11][17].setCostoC(720);
    mAdyacenciaC[11][14].setDistancia(54);
    mAdyacenciaC[11][14].setCostoC(690);
    
    ciudad[11].oDato = ciudad12;


    CCiudad *ciudad13 = new CCiudad;
    ciudad13->setNombre("Ciudad Guzman");
    ciudad13->setCosto(1619);
    ciudad13->setCalificacion(75);
    ciudad13->categoria[0] = "Lago";
    ciudad13->categoria[1] = "Cultural";
    ciudad13->categoria[2] = "Historia";
    ciudad13->categoria[3] = "Arquitectura";
    ciudad13->categoria[4] = "Ecologia";

    mAdyacenciaC[12][18].setDistancia(106);
    mAdyacenciaC[12][18].setCostoC(1320);
    mAdyacenciaC[12][3].setDistancia(102);
    mAdyacenciaC[12][3].setCostoC(1300);

    ciudad[12].oDato = ciudad13;

    CCiudad *ciudad14 = new CCiudad;
    ciudad14->setNombre("Ameca");
    ciudad14->setCosto(1344);
    ciudad14->setCalificacion(70);
    ciudad14->categoria[0] = "Biologia";
    ciudad14->categoria[1] = "Ecologia";

    mAdyacenciaC[13][15].setDistancia(40);
    mAdyacenciaC[13][15].setCostoC(530);
    mAdyacenciaC[13][3].setDistancia(70);
    mAdyacenciaC[13][3].setCostoC(900);
    mAdyacenciaC[13][19].setDistancia(175);
    mAdyacenciaC[13][19].setCostoC(1900);

    ciudad[13].oDato = ciudad14;



    CCiudad *ciudad15 = new CCiudad;
    ciudad15->setNombre("Arandas");
    ciudad15->setCosto(1300);
    ciudad15->setCalificacion(78);
    ciudad15->categoria[0] = "Deporte";
    ciudad15->categoria[1] = "Cultural";
    ciudad15->categoria[2] = "Religion";
    ciudad15->categoria[3] = "Arquitectura";

    mAdyacenciaC[14][11].setDistancia(54);
    mAdyacenciaC[14][11].setCostoC(690);
    mAdyacenciaC[14][9].setDistancia(64);
    mAdyacenciaC[14][9].setCostoC(730);
    mAdyacenciaC[14][16].setDistancia(35);
    mAdyacenciaC[14][16].setCostoC(340);

    ciudad[14].oDato = ciudad15;


    

    CCiudad *ciudad16 = new CCiudad;
    ciudad16->setNombre("Tala");
    ciudad16->setCosto(2370);
    ciudad16->setCalificacion(80);
    ciudad16->categoria[0] = "Deporte";
    ciudad16->categoria[1] = "Religion";
    ciudad16->categoria[2] = "Historia";
    ciudad16->categoria[3] = "Biologia";
    ciudad16->categoria[4] = "Ecologia";
    ciudad16->categoria[5] = "Arquitectura";

    mAdyacenciaC[15][1].setDistancia(71);
    mAdyacenciaC[15][1].setCostoC(400);
    mAdyacenciaC[15][3].setDistancia(35);
    mAdyacenciaC[15][3].setCostoC(480);
    mAdyacenciaC[15][13].setDistancia(40);
    mAdyacenciaC[15][13].setCostoC(530);

    ciudad[15].oDato = ciudad16;


    CCiudad *ciudad17 = new CCiudad;
    ciudad17->setNombre("Atotonilco el alto");
    ciudad17->setCosto(1350);
    ciudad17->setCalificacion(80);
    ciudad17->categoria[0] = "Arquitectura";
    ciudad17->categoria[1] = "Religion";

    mAdyacenciaC[16][14].setDistancia(35);
    mAdyacenciaC[16][14].setCostoC(340);
    mAdyacenciaC[16][9].setDistancia(28);
    mAdyacenciaC[16][9].setCostoC(285);

    ciudad[16].oDato = ciudad17;



    CCiudad *ciudad18 = new CCiudad;
    ciudad18->setNombre("San Juan de los lagos");
    ciudad18->setCosto(1059);
    ciudad18->setCalificacion(80);
    ciudad18->categoria[0] = "Religion";
    ciudad18->categoria[1] = "Deporte";

    mAdyacenciaC[17][11].setDistancia(58);
    mAdyacenciaC[17][11].setCostoC(720);

    ciudad[17].oDato = ciudad18;


    CCiudad *ciudad19 = new CCiudad;
    ciudad19->setNombre("Autlan de Navarro");
    ciudad19->setCosto(1200);
    ciudad19->setCalificacion(83);
    ciudad19->categoria[0] = "Historia";
    ciudad19->categoria[1] = "Arquitectura";
    ciudad19->categoria[2] = "Religion";
    ciudad19->categoria[3] = "Parque acuatico";
    ciudad19->categoria[4] = "Artesania";
    ciudad19->categoria[5] = "Biologia";
    ciudad19->categoria[6] = "Ecologia";

    mAdyacenciaC[18][19].setDistancia(207);
    mAdyacenciaC[18][19].setCostoC(2100);
    mAdyacenciaC[18][3].setDistancia(102);
    mAdyacenciaC[18][3].setCostoC(1300);
    mAdyacenciaC[18][12].setDistancia(106);
    mAdyacenciaC[18][12].setCostoC(1320);

    ciudad[18].oDato = ciudad19;


    CCiudad *ciudad20 = new CCiudad;
    ciudad20->setNombre("Puerto vallarta");
    ciudad20->setCosto(1500);
    ciudad20->setCalificacion(85);
    ciudad20->categoria[0] = "Playa";
    ciudad20->categoria[1] = "Centros comerciales";
    ciudad20->categoria[2] = "Escultura";
    ciudad20->categoria[3] = "Cultural";
    ciudad20->categoria[4] = "Historia";

    mAdyacenciaC[19][18].setDistancia(207);
    mAdyacenciaC[19][18].setCostoC(2100);
    mAdyacenciaC[19][3].setDistancia(261);
    mAdyacenciaC[19][3].setCostoC(2500);
    mAdyacenciaC[19][13].setDistancia(175);
    mAdyacenciaC[19][13].setCostoC(1900);

    ciudad[19].oDato = ciudad20;

    do{
        system("cls");
        int cat = 0;
        std::cout<<"||Menu||"<<std::endl;
        std::cout<<"1.-Insertar nueva ciudad"<<std::endl;
        std::cout<<"2.-Mostrar datos"<<std::endl;
        std::cout<<"3.-Insertar camino"<<std::endl;
        std::cout<<"4.-Modificar ciudad o camino"<<std::endl;
        std::cout<<"5.-Eliminar ciudad"<<std::endl;
        std::cout<<"6.-Buscar trayectoria: "<<std::endl;
        std::cout<<"7.-Salir"<<std::endl;
        
        std::cout<<"\nSeleccione: "<<std::endl;
        cin>>opcion;
        fflush(stdin);

        if(opcion == 1){
            system("cls");
            fflush(stdin);
            int n = 0;
            int vNull;
            std::cout<<"Insertando nodo\n"<<std::endl;
            std::cout<<"Digite el nombre de la ciudad: ";
            cin>>cNombre;
            std::cout<<"Digite el costo: ";
            cin>>cCosto;
            std::cout<<"Digite la calificacion: ";
            cin>>cCal;
            

            CCiudad *ciudadd = new CCiudad;
            ciudadd->setNombre(cNombre);
            ciudadd->setCosto(cCosto);
            ciudadd->setCalificacion(cCal);

            do{
                std::cout<<"Digite la categoria que ofrece: ";
                cin>>cate;

                ciudadd->categoria[cat] = cate;

                std::cout<<"Selecciones |1|Agregar categoria |2|Continuar: ";
                cin>>opcionC;
                cat++;
            }while(opcionC != 2);
            
            while(ciudad[n].oDato != NULL && n < cCiu){
                n++;
            }
            
            if(ciudad[n].oDato == NULL){
                ciudad[n].oDato = ciudadd;
                do{
                    system("cls");
                    fflush(stdin);
                    std::cout<<"\n\nInserte adyacencia: "<<std::endl;
                    std::cout<<"\nMostrando ciudades"<<std::endl;
                    for(int i=0;i<cCiu;i++){
                        if(ciudad[i].oDato != NULL){
                            std::cout<<"["<<i<<"]"<<ciudad[i].oDato->getNombre()<<std::endl;
                        }
                    }
                    std::cout<<"\n\nDigite el numero de la ciudad con la que se hara camino: ";
                    cin>>nCol;
                    std::cout<<"Digite la distancia entre estos en kM: ";
                    cin>>mCol;
                    std::cout<<"Digite el costo: ";
                    cin>>cCosto;
                    mAdyacenciaC[n][nCol].setDistancia(mCol);
                    mAdyacenciaC[n][nCol].setCostoC(cCosto);
                    mAdyacenciaC[nCol][n].setDistancia(mCol);
                    mAdyacenciaC[nCol][n].setCostoC(cCosto);
                    

                    fflush(stdin);
                    std::cout<<"Datos insertados correctamente"<<std::endl;
                    std::cout<<ciudad[n].oDato->getNombre()<<std::endl;
                    std::cout<<mAdyacenciaC[n][nCol].getDistancia()<<std::endl;

                    std::cout<<"Digite [1]Agregar adyacencia [2]Volver al menu: ";
                    cin>>opcion1;
                }while(opcion1 != 2);
            }
               
            
            else{
                ciudad[cCiu].oDato = ciudadd;

                do{
                    system("cls");
                    fflush(stdin);
                    std::cout<<"\n\nInserte adyacencia: "<<std::endl;
                    std::cout<<"\nMostrando ciudades"<<std::endl;
                    for(int i=0;i<cCiu;i++){
                        if(ciudad[i].oDato != NULL){
                            std::cout<<"["<<i<<"]"<<ciudad[i].oDato->getNombre()<<std::endl;
                        }
                    }
                    std::cout<<"\n\nDigite el numero de la ciudad con la que se hara adyacencia: ";
                    cin>>nCol;
                    std::cout<<"Digite la distancia entre estos en kM: ";
                    cin>>mCol;
                    std::cout<<"Digite el costo: ";
                    cin>>cCosto;

                    mAdyacenciaC[cCiu][nCol].setDistancia(mCol);
                    mAdyacenciaC[cCiu][nCol].setCostoC(cCosto);
                    mAdyacenciaC[nCol][cCiu].setDistancia(mCol);
                    mAdyacenciaC[nCol][cCiu].setCostoC(cCosto);

                    fflush(stdin);
                    std::cout<<"Datos insertados correctamente"<<std::endl;
                    std::cout<<ciudad[cCiu].oDato->getNombre()<<std::endl;
                    std::cout<<mAdyacenciaC[cCiu][nCol].getDistancia()<<std::endl;

                    std::cout<<"Digite [1]Agregar adyacencia [2]Volver al menu: ";
                    cin>>opcion1;
                }while(opcion1 != 2);
                cCiu++;
            }
        }

        if(opcion == 2){
            system("cls");
            fflush(stdin);
            std::cout<<"Mostrando datos\n"<<std::endl;
            for(int i=0;i<cCiu;i++){
                if(ciudad[i].oDato != NULL){
                    std::cout<<"______________________________________________"<<std::endl;
                    std::cout<<"Mostrando ciudad"<<std::endl;
                    std::cout<<"          Ciudad: "<<ciudad[i].oDato->getNombre()<<std::endl;
                    std::cout<<"           Costo: $"<<ciudad[i].oDato->getCosto()<<std::endl;
                    std::cout<<"    Calificacion: "<<ciudad[i].oDato->getCalificacion()<<std::endl;
                    std::cout<<"La ciudad ofrece: ";
                    for(int k=0;k<7;k++){
                        if(k == 0){
                            std::cout<<""<<ciudad[i].oDato->categoria[k]<<std::endl;
                        }
                        else{
                            std::cout<<"                  "<<ciudad[i].oDato->categoria[k]<<std::endl;    
                        }
                    }
                    std::cout<<"\n\nDesde esta ciudad se puede ir a: "<<std::endl;
                    for(int j=0;j<cCiu;j++){
                        if(mAdyacenciaC[i][j].getDistancia() != cValor){
                            //std::cout<<"\n\nAccesible desde: "<<colo[i].getNombre()<<std::endl;
                            std::cout<<"          Ciudad: "<<ciudad[j].oDato->getNombre()<<std::endl;
                            std::cout<<"           Costo: $"<<ciudad[j].oDato->getCosto()<<std::endl;
                            std::cout<<"    Calificacion: "<<ciudad[j].oDato->getCalificacion()<<std::endl;
                            std::cout<<"       Distancia: "<<mAdyacenciaC[i][j].getDistancia()<<"Km"<<std::endl;
                            std::cout<<"Costo transporte: $"<<mAdyacenciaC[i][j].getCostoC()<<std::endl;
                            std::cout<<"La ciudad ofrece: ";
                            for(int k=0;k<7;k++){
                                if(k == 0){
                                    std::cout<<""<<ciudad[j].oDato->categoria[k]<<std::endl;
                                }
                                else{
                                    std::cout<<"                  "<<ciudad[j].oDato->categoria[k]<<std::endl;    
                                }
                            }
                            std::cout<<"\n"<<std::endl;
                        }
                    }
                }
            }
            system("pause");
        }
        if(opcion == 3){
            system("cls");
            fflush(stdin);
            std::cout<<"Insertando camino\n\n"<<std::endl;
            for(int i=0;i<cCiu;i++){
                if(ciudad[i].oDato != NULL){
                    std::cout<<"["<<i<<"]"<<ciudad[i].oDato->getNombre()<<std::endl;
                }
            }
            std::cout<<"\n\nDigite el numero de la ciudad de origen: ";
            cin>>cOrigen;
            std::cout<<"Digite el numero de la ciudad de destino: ";
            cin>>cDestino;
            std::cout<<"Digite la distancia entre las ciudades: ";
            cin>>mCol;
            std::cout<<"Digite el costo de traslado: ";
            cin>>cTraslado;

            mAdyacenciaC[cOrigen][cDestino].setDistancia(mCol);
            mAdyacenciaC[cOrigen][cDestino].setCostoC(cTraslado);
            mAdyacenciaC[cDestino][cOrigen].setDistancia(mCol);
            mAdyacenciaC[cDestino][cOrigen].setCostoC(cTraslado);

            std::cout<<"Datos insertados correctamente"<<std::endl;
            std::cout<<mAdyacenciaC[cOrigen][cDestino].getDistancia()<<std::endl;
            std::cout<<mAdyacenciaC[cOrigen][cDestino].getCostoC()<<std::endl;

            system("pause");
        }
        if(opcion == 4){
            system("cls");
            fflush(stdin);
            do{

                std::cout<<"Modificando ciudad\n"<<std::endl;
                std::cout<<"1.-Modificar nombre"<<std::endl;
                std::cout<<"2.-Modificar costo"<<std::endl;
                std::cout<<"3.-Modificar calificacion"<<std::endl;
                std::cout<<"4.-Modificar distancia"<<std::endl;
                std::cout<<"5.-Modificar costo"<<std::endl;
                std::cout<<"6.-Eliminar camino"<<std::endl;
                std::cout<<"7.-Volver al menu principal"<<std::endl;

                std::cout<<"\nSeleccione: ";
                cin>>opcionM;

                if(opcionM == 1){
                    system("cls");
                    fflush(stdin);
                    for(int i=0;i<cCiu;i++){
                        if(ciudad[i].oDato != NULL){
                            std::cout<<"["<<i<<"]"<<ciudad[i].oDato->getNombre()<<std::endl;
                        }
                    }
                    std::cout<<"Modificando nombre"<<std::endl;
                    std::cout<<"Digite el numero de la ciudad: "<<std::endl;
                    cin>>nCiudad;
                    std::cout<<"Digite el nuevo nombre: ";
                    cin>>cNombre;

                    ciudad[nCiudad].oDato->setNombre(cNombre);
                }
                if(opcionM == 2){
                    system("cls");
                    fflush(stdin);
                    for(int i=0;i<cCiu;i++){
                        if(ciudad[i].oDato != NULL){
                            std::cout<<"["<<i<<"]"<<ciudad[i].oDato->getNombre()<<std::endl;
                        }
                    }
                    std::cout<<"Modificando costo"<<std::endl;
                    std::cout<<"Digite el numero de la ciudad: "<<std::endl;
                    cin>>nCiudad;
                    std::cout<<"Digite el nuevo costo: ";
                    cin>>cCosto;

                    ciudad[nCiudad].oDato->setCosto(cCosto);

                }

                if(opcionM == 3){
                    system("cls");
                    fflush(stdin);
                    for(int i=0;i<cCiu;i++){
                        if(ciudad[i].oDato != NULL){
                            std::cout<<"["<<i<<"]"<<ciudad[i].oDato->getNombre()<<std::endl;
                        }
                    }
                    std::cout<<"Modificando calificacion"<<std::endl;
                    std::cout<<"Digite el numero de la ciudad: "<<std::endl;
                    cin>>nCiudad;
                    std::cout<<"Digite la nueva calificacion: ";
                    cin>>cCal;

                    ciudad[nCiudad].oDato->setCalificacion(cCal);
                }
                if(opcionM == 4){
                    system("cls");
                    fflush(stdin);
                    for(int i=0;i<cCiu;i++){
                        if(ciudad[i].oDato != NULL){
                            std::cout<<"["<<i<<"]"<<ciudad[i].oDato->getNombre()<<std::endl;
                        }
                    }
                    std::cout<<"Modificando distancia"<<std::endl;
                    std::cout<<"\n\nDigite el numero de la primera ciudad: ";
                    cin>>cOrigen;
                    std::cout<<"Digite el numero de la segunda ciudad: ";
                    cin>>cDestino;
                    std::cout<<"Digite la nueva distancia"<<std::endl;
                    cin>>nDistancia;

                    mAdyacenciaC[cOrigen][cDestino].setDistancia(nDistancia);
                    mAdyacenciaC[cDestino][cOrigen].setDistancia(nDistancia);
                }

                if(opcionM == 5){
                    system("cls");
                    fflush(stdin);
                    for(int i=0;i<cCiu;i++){
                        if(ciudad[i].oDato != NULL){
                            std::cout<<"["<<i<<"]"<<ciudad[i].oDato->getNombre()<<std::endl;
                        }
                    }
                    std::cout<<"Modificando costo"<<std::endl;
                    std::cout<<"\n\nDigite el numero de la primera ciudad: ";
                    cin>>cOrigen;
                    std::cout<<"Digite el numero de la segunda ciudad: ";
                    cin>>cDestino;
                    std::cout<<"Digite la nueva distancia"<<std::endl;
                    cin>>nCosto;

                    mAdyacenciaC[cOrigen][cDestino].setCostoC(nCosto);
                    mAdyacenciaC[cDestino][cOrigen].setCostoC(nCosto);

                }

                if(opcionM == 6){
                    system("cls");
                    fflush(stdin);
                    for(int i=0;i<cCiu;i++){
                        if(ciudad[i].oDato != NULL){
                            std::cout<<"["<<i<<"]"<<ciudad[i].oDato->getNombre()<<std::endl;
                        }
                    }
                    std::cout<<"Eliminado camino"<<std::endl;
                    std::cout<<"\n\nDigite el numero de la primera ciudad: ";
                    cin>>cOrigen;
                    std::cout<<"Digite el numero de la segunda ciudad: ";
                    cin>>cDestino;

                    mAdyacenciaC[cOrigen][cDestino].setDistancia(cValor);
                    mAdyacenciaC[cOrigen][cDestino].setCostoC(0);
                    mAdyacenciaC[cDestino][cOrigen].setDistancia(cValor);
                    mAdyacenciaC[cDestino][cOrigen].setCostoC(0);

                    std::cout<<"camino eliminado correctamente"<<std::endl;
                    system("pause");
                }

            }while(opcionM != 7);
        }

        if(opcion == 5){
            system("cls");
            fflush(stdin);
            for(int i=0;i<cCiu;i++){
                 if(ciudad[i].oDato != NULL){
                    std::cout<<"["<<i<<"]"<<ciudad[i].oDato->getNombre()<<std::endl;
                }
            }

            std::cout<<"Digite el numero de ciudad a eliminar"<<std::endl;
            cin>>nCiudad;
            delete ciudad[nCiudad].oDato;
            ciudad[nCiudad].oDato = NULL; 

            for(int x = 0;x<cCiu;x++){
                mAdyacenciaC[nCiudad][x].setDistancia(cValor);
                mAdyacenciaC[nCiudad][x].setCostoC(0);
                mAdyacenciaC[x][nCiudad].setDistancia(cValor);
                mAdyacenciaC[x][nCiudad].setCostoC(0);
            }
            std::cout<<"Ciudad eliminada correctamente"<<std::endl;
            system("pause");
        }
        if(opcion == 7){
            system("cls");
            fflush(stdin);
            std::cout<<"Cerrando el programa\n\n\n"<<std::endl;
        }
    }while(opcion != 7);
}
