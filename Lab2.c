#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int i, x;
    char opc;
	FILE *archivo=NULL;
    printf("\n Elija el archivo con el que desea trabajar: ");
    scanf("%c", &opc);
    if(opc=='1'){
    	archivo = fopen ("archivo_1.tex", "r"); //la r es solo para leer.
        if(archivo != NULL){
            
            while (!feof(archivo)){
                x=fgetc(archivo);
                printf("%c", x);
            }
        }
    }
    if(opc=='2'){
        archivo = fopen ("archivo_2.tex", "r"); //la r es solo para leer.
        if(archivo != NULL){
            
            while (!feof(archivo)){
                x=fgetc(archivo);
                printf("%c", x); //el x es de hexadígitos
            }
        }
    }
    if(opc=='3'){
        archivo = fopen ("archivo_3.tex", "r"); //la r es solo para leer.
        if(archivo != NULL){
            
            while (!feof(archivo)){
                x=fgetc(archivo);
                printf("%c", x);
            }
        }
    }
    fclose (archivo);
    printf("\n \n");
}