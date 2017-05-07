#include <iostream>
#include <fstream>
#include <string.h>



using namespace std;

struct nodo{
  int numero; 
  int repeticiones;
  nodo *sig;  
};

void crear_lista(nodo *&lista, unsigned int &i, int n){
  nodo * aux1; //aux
  nodo * aux2;  //ele
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

int divide(unsigned int **datos, int inicio, int fin) {//divide el vector usando quicksort
  int izquierda, derecha, pivote, auxNumero, auxRepeticiones;
  pivote=datos[inicio][1];
  izquierda=inicio;
  derecha=fin;

  while(izquierda < derecha){
    while(datos[derecha][1] > pivote){
      derecha--;
    }
    while( (izquierda < derecha) && (datos[izquierda][1]) <= pivote){
      izquierda++;
    } 
    if(izquierda<derecha){
      auxNumero=datos[izquierda][0];
      auxRepeticiones=datos[izquierda][1];
      datos[izquierda][0] = datos[derecha][0];
      datos[izquierda][1] = datos[derecha][1];
      datos[derecha][0]=auxNumero;
      datos[derecha][1]=auxRepeticiones;
    }
  }

  auxNumero=datos[derecha][0];
  auxRepeticiones=datos[derecha][1];

  datos[derecha][0]=datos[inicio][0];
  datos[derecha][1]=datos[inicio][1];

  datos[inicio][0]=auxNumero;
  datos[inicio][1]=auxRepeticiones;

  return derecha;


}
void quicksort(unsigned int **datos, int inicio, int fin){
  int pivote;
  if(inicio<fin){
    pivote = divide(datos, inicio,fin);
    //ordenar menores
    quicksort(datos,inicio,pivote-1);
    //ordenar mayores
    quicksort(datos,pivote+1,fin);
  }
}

void frecuencia_mayor(unsigned int largo, unsigned int **datos){
  int i;
  for(i=largo;i>=0;i--){
    cout<<datos[i][0]<<" "<<datos[i][1];
    if(datos[i-1][1]<datos[i][1]){
      break;
    }
  }
}

void frecuencia(unsigned int largo, unsigned int **datos){
 int i;
 for(i=largo;i>=0;i--){
    if(datos[i][1]==1){
      break;
    }
    cout<<hex<<datos[i][0]<<" "<<datos[i][1]<<endl;
  }

}

int main(void){
      
    nodo * lista = NULL;
    nodo * auxl;

    unsigned int ** datos;
    unsigned int i, n, j,k,l;
    char opc, aux[5];
    cout<<"\n\n";
    cout<<"Opción 1: Archivo_1.tex"<<endl;
    cout<<"Opción 2: Archivo_2.tex"<<endl;
    cout<<"Opción 3: Archivo_3.tex"<<endl;
    cout<<"\n\n";

    cout<<"\n Elija el archivo con el que desea trabajar: ";
    cin>>opc;
    if(opc=='1'){
      ifstream Entrada("archivo_1.tex"); //ver archivo entrada
      ofstream Salida("Salida.txt");
      ifstream AuxIn;
       
        //Primer serie de 4 números

        Entrada>>aux[0];
        Entrada>>aux[1];
        Entrada>>aux[2];
        Entrada>>aux[3];
        aux[4]='\n';

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
  
        //Se crea el arreglo datos para copiar lo de lista (Con el mismo tamaño de esta)
        datos=new unsigned int*[i];
        for(j=0;j<i;j++){
          datos[j]=new unsigned int[2];
        }

        j=0;

        //Se copia la lista a un arreglo para luego eliminar la lista.
        while(lista){
          auxl=lista;
          lista=lista->sig;
          datos[j][0]=auxl->numero;
          datos[j][1]=auxl->repeticiones;
          delete auxl;
          j++;
        }

        k=i;

        quicksort(datos,0,k-1);

        cout<<"\n Los números que más se repiten son: ";
        frecuencia_mayor(k-1, datos);
        cout<<endl;
      

    }
    if(opc=='2'){
      ifstream Entrada ("archivo_2.tex"); 
      ofstream Salida ("Salida2.txt");
      ifstream AuxIn;
       
        //Primer serie de 4 números

        Entrada>>aux[0];
        Entrada>>aux[1];
        Entrada>>aux[2];
        Entrada>>aux[3];
        aux[4];'\n';

        Salida<<aux<<endl;

        aux[0]=aux[1];
        aux[1]=aux[2];
        aux[2]=aux[3];

        // Ahora para el resto

        while(Entrada>>aux[3]){ //Cuando el archivo esté desde la tercera posición en adelante
          Salida<<aux<<endl;
          aux[0]=aux[1];
          aux[1]=aux[2];
          aux[2]=aux[3];
        }
        Entrada.close();
        Salida.close();

        i=0;
        AuxIn.open("Salida2.txt");
        while(AuxIn>>hex>>n){
          crear_lista(lista, i, n);
        }
        AuxIn.close();

       
        datos=new unsigned int*[i];
        for(j=0;j<i;j++){
          datos[j]=new unsigned int[2];
        }

        j=0;

        //Se copia la lista a un arreglo para luego eliminar la lista.
        while(lista){
          auxl=lista;
          lista=lista->sig;
          datos[j][0]=auxl->numero;
          datos[j][1]=auxl->repeticiones;
          j++;
          delete auxl;
          
        }
        
        quicksort(datos,0,i-1);

        cout<<"\n Los números que más se repiten son: "<<endl<<endl;
        frecuencia(i-1, datos);
        cout<<endl;

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
