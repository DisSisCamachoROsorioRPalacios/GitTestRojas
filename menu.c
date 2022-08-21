#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
#include<math.h>

double **creaTabla(int f,int c){ //funcion crea la tabla
	double **t=NULL;
	t=(double**)malloc(f*sizeof(double*));
	for(int i=0;i<f;i++){
		t[i]=(double*)malloc(c*sizeof(double));
	}
	return t; //return &t[0][0];
}

double leerTemperatura(double *day){ //funcion para ingresar numeros aleatorios en el arreglo por minuto/dia
	srand(time(NULL));

	for(int j=0;j<1440;j++)
	{
		day[j]= 10 + rand()/(double) RAND_MAX *(28-(10)); //el rango de numeros aleatorios entre 10-28
	}	
}

void mostrarTemperaturaDay(double *day){ //Funcion muestra las temperaturas por dia
	int i;
	for(i=0;i<1440;i++)
	{	
		printf(" %.2f ",day[i]);
	}	
}

double averageDate(double *day,int c){ //funcion para promedio por dia
	//promedio por día 
	double suma=0;
	for(int i=0;i<c;i++){
		suma=suma+day[i];
	}
	return suma/c;
}

double averageMonth(double **p, int f,int c){ //funcion para promedio por mes o los dias que va ingresado
	//calcular promedio mes
	double suma=0;
	for(int i=0;i<f;i++){
		suma=suma+averageDate(p[i],c);
	}
	return suma/f;
}
int main(){
	
	double **tmps=creaTabla(28,1440); //arreglo bidimencional que guarda los datos de 28 dias renglones y 1440 minutos columnas
	int op,dia;
	srand(time(NULL));
	int cont=0;
	do{ //Inicia el ciclo del menú
		printf("\n=======Menú======\n");
		printf("Seleccione una opcion\n 1.-Leer temperatura del dia\n2.- Mostrar temperatura\n3.-Mostrar promedio del dia\n4.- Mostrar promedio del mes\n5.- Salir  ");
		printf("\nSeleccione una opcion: ");
		scanf("%d",&op);
		switch(op) { //menu de opciones 
			case 1:
				//printf()
				if(cont<28){

					leerTemperatura(tmps[cont]); //invoca a la funcion leer la temperatura para ingresar los numeros al arreglo
					cont++; //este contador sirve para que guarde los dato por dia hasta 28
			}
				else{
					cont=0; //si el contador es mayor a 28 rgresa a la primera posicion(dia 1)
					leerTemperatura(tmps[cont]); //vuele a invocar la funcion para llenar los datos
					cont++; 
				}
				break;
			case 2:
				printf("que dia quiere ver el promedio");
				scanf("%d",&dia);
				dia=dia-1; // parra indicar el dia que introduce el usuario y coincida con la posicion 
				mostrarTemperaturaDay(tmps[dia]); //invoca la funcion para mostrar el arreglo con los datos llenados
				break;
			case 3:
				printf("que dia quiere ver el promedio");
				scanf("%d",&dia);
				dia=dia-1;
				printf("Average Day %d: %.2f",dia+1,averageDate(tmps[dia],1440)); // imprime y llama la funcion de promedio del dia indicado
				break;
			case 4:
				if(cont<=28){ // condicion para poder imprimir si el condicion es menor o igual a 28 dias ingresados
					printf("Average Month %.2f",averageMonth(tmps, cont, 1440));// imprime y llama la funcion del promedio del mes 
				}
				if(cont>28){ //condicion por si excede a los dias 28 imprima "se lleno"
					printf("se lleno");
					cont=0; //si el contador llega a 0 regresa a la primera posicion 
				}
				break;
			case 5:
				exit(0); //para salir del menu
		}
	}while(op!=5); //si la opcion es diferente a 5 se termina el programa
	return 0;
}
