#include <iostream>
#include <Windows.h>
#include <conio.h>
#define max 15
using namespace std;


void ingresar(int a[max][max], int f, int c);
void mostrar(int a[max][max], int f, int c);
void ordenBurbuja(int a[max][max], int f, int c);
void filaborrar(int a[max][max], int f, int c, int aux);
void columnaborrar(int a[max][max], int f, int c, int aux);
void menu();

int main(){
    SetConsoleOutputCP(CP_UTF8); //para que se escriba "número" y no "n||mero"
    int a[max][max], opc, f, c, aux;
    do{
        system("cls");
        menu(); cin >>opc;
        switch(opc){
            case 1:{
                cout <<"\nIngrese las filas de la matriz: "; cin >>f;
                cout <<"Ingrese las columnas de la matriz: "; cin >>c;
                ingresar(a, f, c);
                getch(); break;
            }
            case 2:{
                cout <<"\nLa matriz ordenada es: \n";
                ordenBurbuja(a, f, c); mostrar(a, f, c);
                getch(); break;
            }
            case 3:{
                cout <<"\nIngrese el número de fila a borrar: "; cin >>aux;
                filaborrar(a, f, c ,aux);
                getch(); break;
            }
            case 4:{
                cout <<"\nIngrese el número de fila a borrar: "; cin >>aux;
                columnaborrar(a, f, c ,aux);
                getch(); break;
            }
            case 5:{
                cout <<"\nLos elementos de la matriz son: \n";
                mostrar(a, f, c);
                getch(); break;
            }
        }
    }while(opc != 0);
    return 0;
}

void menu(){
    cout <<"\n1. Ingresar elementos a la matriz.";
    cout <<"\n2. Ordenar la matriz.";
    cout <<"\n3. Borrar una fila determinada.";
    cout <<"\n4. Borrar una columna determinada.";
    cout <<"\n5. Ver la matriz.";
    cout <<"\n0. Salir";
    cout <<"\nElija su opción >> ";
}

void ingresar (int a[max][max], int f, int c){
	for (int i=0; i<f; i++){
		for (int j=0; j<c; j++){
            cout <<"Ingrese elemento: [" <<(i+1)<<"]["<<(j+1)<<"]: " ; cin >>a[i][j];
        }
	}
}
void mostrar(int a[max][max], int f, int c){
	for (int i=0; i<f; i++){
		for (int j=0; j<c ;j++){
			cout <<" "<<a[i][j];
        }
	    cout<<endl;
	}
}
void ordenBurbuja(int a[max][max], int f, int c){
	int aux;
	for(int i=0;i<f;i++){
		for(int j=0;j<c;j++){
			for (int m=0 ; m<f ; m++){
				for (int n=0 ;n<c ; n++){
					if (a[i][j] < a[m][n]){
						aux = a[i][j];
						a[i][j] = a[m][n];
						a[m][n] = aux;
					}
				}
			}
		}
	}
}
void filaborrar(int a[max][max], int f, int c, int aux){
	for (int i=0; i<f; i++){
		for (int j=0; j<c; j++){
			if(i != aux){
                cout <<" "<<a[i][j];
            }
        }
	    cout<<endl;
	}
}
void columnaborrar(int a[max][max], int f, int c, int aux){
	for (int i=0; i<f; i++){
		for (int j=0; j<c; j++){
			if(j != aux){
                cout <<" "<<a[i][j];
            }
        }
	    cout<<endl;
	}
}