//Pequeño proyecto: Pequeño sistema para gestión de pedidos de pizza.

#include <iostream>
#include <string.h>
#include <Windows.h> //para que se escriba "número" y no "n||mero". 
#define max 15
using namespace std;

struct pizza{
    int cant;
    char sabor[max];
    int preciopizza;
    char tamanio[max];
};
struct cliente{
    char nombre[max];
	struct pizza pedido;
    int importe;
};

/*
que pregunte cuántas pizzas en total
de acuerdo a eso hacer un bucle para que pida la cant. de acuerdo al sabor
tipo n = 5 (total)
sabor = americana
cantidad 3
sabor = peperoni
cantidad = 2
si me pide una cant 

*/
//importe = cant*precio de la pizza (definir nosotros)
/*
americana = 12
peperoni = 15
suprema = 17

normal +0
mediana +2
grande +5
*/
//se le dice el precio al momento de imprimir

void ingresar(struct cliente a[max], int x){
	for (int i=0; i<x; i++){
		cin.ignore(max,'\n');
		cout <<"\nIngrese su nombre ["<<i+1<<"]: "; cin.getline(a[i].nombre, max, '\n');
		cout <<"Sabor de la pizza ["<<i+1<<"]: "; cin.getline(a[i].pedido.sabor, max, '\n');
		if (strcmp(a[i].pedido.sabor, "americana") == 0){
			a[i].pedido.preciopizza = 12;
		}else if (strcmp(a[i].pedido.sabor, "peperoni") == 0){
			a[i].pedido.preciopizza = 15;
		}else{
			if (strcmp(a[i].pedido.sabor, "suprema") == 0){
				a[i].pedido.preciopizza = 17;
			}else{
				cout <<"Sabor equivocado.\n";
			}
		}
		cout <<"El precio del sabor elegido es ["<<i+1<<"]: S/."<<a[i].pedido.preciopizza;
		cout <<"\nCant. de pizzas del sabor elegido ["<<i+1<<"]: "; cin >>a[i].pedido.cant;
		a[i].importe = a[i].pedido.preciopizza * a[i].pedido.cant;
		cout <<"El importe total es ["<<i+1<<"]: S/."<<a[i].importe<<endl;
	}
}
void mostrar(struct cliente a[max], int x){
	for (int i=0; i<x; i++){
		cout <<"\t"<<a[i].nombre<<"\t"<<a[i].pedido.sabor<<"\t"<<a[i].pedido.cant<<"\t"<<a[i].importe<<endl;
	}
}
int main(){
	SetConsoleOutputCP(CP_UTF8); //para que se escriba "número" y no "n||mero". 
	struct cliente a[max];
	int n;
	char r;
	do{
		system("cls");
		cout <<"===== 	BIENVENIDO	=====\n";
		cout <<"Digite la cant. de clientes: "; cin >>n;
		cout <<"Ingrese los clientes: \n"; ingresar(a, n);
		cout <<"Los clientes son: \n\tNOMBRE\tSABOR\t\tCANT\tIMPORTE\n"; mostrar(a, n);
		//________
		cout <<"\n¿Desea continuar? [s/n]: " ; cin >> r;
	}while (r == 's');
	return 0;
}