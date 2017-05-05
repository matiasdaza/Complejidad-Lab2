#include <iostream>
#include <fstream>
#include <string.h>

//void crear_lista(nodo *&lista, unsigned int &i, int n);

using namespace std;

struct nodo{
	int numero; 
	int repeticiones;
	nodo *sig;	
};

void crear_lista(nodo *&lista, unsigned int &i, int n){
	nodo * aux1; //aux
	nodo * aux2;	//ele
	bool esta;
	if(lista==NULL){
		aux2 = new nodo;
		aux2->numero=n;
		aux2->repeticiones=1;
		aux2->sig = NULL;

		lista=aux2;
		i++;
	}
	else{
		aux1=lista;
		esta=false;
		while(true){
			if(aux1-> numero == n){
				aux1 -> repeticiones++;
				esta=true;
				break;
			}else if(aux1->sig==NULL){
				break;
			}
			aux1=aux1->sig;
		}
		if(esta==false){
			aux2=new nodo;
			aux2->numero=n;
			aux2->repeticiones=1;
			aux2->sig=NULL;
			aux1->sig=aux2;
			i++;
		}
	}
}

int main(void){
    	
    nodo * lista = NULL;
    nodo * auxl;

    unsigned int ** datos;
    unsigned int i=0, n, j, k;
    char opc, aux[5];
    cout<<"\n\n";
    cout<<"Opción 1: Archivo_1.tex"<<endl;
    cout<<"Opción 2: Archivo_2.tex"<<endl;
    cout<<"Opción 3: Archivo_3.tex"<<endl;
    cout<<"\n\n";

    cout<<"\n Elija el archivo con el que desea trabajar: ";
    cin>>opc;
    if(opc=='1'){
    	ifstream Entrada ("archivo_1.tex"); 
    	ofstream Salida ("Salida.txt");
    	ifstream AuxIn;
       
       	//Primer serie de 4 números

       	Entrada>>aux[0];
       	Entrada>>aux[1];
       	Entrada>>aux[2];
       	Entrada>>aux[3];
       	aux[4];'\n';

       	Salida<<aux;
       	aux[0]=aux[1];
       	aux[1]=aux[2];
       	aux[2]=aux[3];

       	// Ahora para el resto

       	while(Entrada>>aux[3]){ //Cuando el archivo esté desde la tercera posición en adelante
       		Salida<<aux;
	       	aux[0]=aux[1];
	       	aux[1]=aux[2];
	       	aux[2]=aux[3];
       	}
       	Entrada.close();
       	Salida.close();

       	AuxIn.open("Salida.txt");
       	while(AuxIn>>n){
       		crear_lista(lista, i, n);
       	}
       	AuxIn.close();

    }
    if(opc=='2'){
        ifstream Entrada ("archivo_1.tex"); 
    	ofstream Salida ("Salida.txt");
    	ifstream AuxIn;
       
       	//Primer serie de 4 números

       	Entrada>>aux[0];
       	Entrada>>aux[1];
       	Entrada>>aux[2];
       	Entrada>>aux[3];
       	aux[4];'\n';

       	Salida<<aux;
       	aux[0]=aux[1];
       	aux[1]=aux[2];
       	aux[2]=aux[3];

       	// Ahora para el resto

       	while(Entrada>>aux[3]){ //Cuando el archivo esté desde la tercera posición en adelante
       		Salida<<aux;
	       	aux[0]=aux[1];
	       	aux[1]=aux[2];
	       	aux[2]=aux[3];
       	}
       	Entrada.close();
       	Salida.close();

       	AuxIn.open("Salida.txt");
       	while(AuxIn>>n){
       		crear_lista(lista, i, n);
       	}
       	AuxIn.close();
    }
    if(opc=='3'){
        ifstream Entrada ("archivo_1.tex"); 
    	ofstream Salida ("Salida.txt");
    	ifstream AuxIn;
       
       	//Primer serie de 4 números

       	Entrada>>aux[0];
       	Entrada>>aux[1];
       	Entrada>>aux[2];
       	Entrada>>aux[3];
       	aux[4];'\n';

       	Salida<<aux;
       	aux[0]=aux[1];
       	aux[1]=aux[2];
       	aux[2]=aux[3];

       	// Ahora para el resto

       	while(Entrada>>aux[3]){ //Cuando el archivo esté desde la tercera posición en adelante
       		Salida<<aux;
	       	aux[0]=aux[1];
	       	aux[1]=aux[2];
	       	aux[2]=aux[3];
       	}
       	Entrada.close();
       	Salida.close();

       	AuxIn.open("Salida.txt");
       	while(AuxIn>>n){
       		crear_lista(lista, i, n);
       	}
       	AuxIn.close();
    }
}

