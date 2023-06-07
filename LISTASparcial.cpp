#include<iostream>
#include <conio.h>
#include <string.h>
#include <Windows.h> //para que se escriba "número" y no "n||mero".
#define max 15
using namespace std;

struct nodo{
    int numcarnet;
    char nom[max];
    int prom;
    char sexo[max];
    struct nodo *sgte;
};
typedef struct nodo *tlista;

void insFINAL(tlista &lista, int numcarnet, char nom[max], int prom, char sexo[max]);
void imprimir(tlista lista);
void prompares(tlista lista);
void ordenarprom(tlista &lista);
void primero(tlista lista);
void ultimo(tlista lista);

void insFINAL(tlista &lista, int numcarnet, char nom[max], int prom, char sexo[max]){
    tlista t, q = new(struct nodo);
    q->numcarnet = numcarnet;
    q->prom = prom;
    strcpy(q->nom, nom);
    strcpy(q->sexo, sexo);
    q->sgte = NULL;
    if (lista == NULL)
        lista = q;
    else{
        t = lista;
        while(t->sgte != NULL)
            t = t->sgte;
        t->sgte = q;
    }
}
void imprimir(tlista lista){
    tlista aux = lista;
    while(aux != NULL){
        cout <<aux->numcarnet<<"\t"<<aux->nom<<"\t"<<aux->prom<<"\t"<<aux->sexo<<endl;
        aux = aux->sgte;
    }
}
void prompares(tlista lista){
	tlista aux = lista;
	while(aux != NULL){
		if(aux->prom > 10){
			if(aux->prom%2 == 0){
				cout <<aux->numcarnet<<"\t"<<aux->nom<<"\t"<<aux->prom<<"\t"<<aux->sexo<<endl;
			}
		}
		aux = aux->sgte;
	}
}
void ordenarprom(tlista &lista){
    tlista aux1, aux2, t = NULL;
    int tcarnet, tprom;
    char tnom[max], tsexo[max];
    while(t != lista->sgte){
        aux1 = lista; 
        aux2 = aux1->sgte; 
        while(aux2 != t){
            if(aux1->prom > aux2->prom){
            	tcarnet = aux1->numcarnet;
            	aux1->numcarnet = aux2->numcarnet;
            	aux2->numcarnet = tcarnet;
            	
                strcpy(tnom, aux1->nom);
                strcpy(aux1->nom, aux2->nom);
                strcpy(aux2->nom, tnom);
                
                tprom = aux1->prom;
                aux1->prom = aux2->prom;
                aux2->prom = tprom;
                
                strcpy(tsexo, aux1->sexo);
                strcpy(aux1->sexo, aux2->sexo);
                strcpy(aux2->sexo, tsexo);
            }
            aux1 = aux1->sgte;
            aux2 = aux1->sgte;
        }
        t = aux1;
    }
}
void primero(tlista lista){
	tlista aux = lista;
	cout <<"\nNUM\tNOMBRE\tPROM\tSEXO\t\n";
	cout <<aux->numcarnet<<"\t"<<aux->nom<<"\t"<<aux->prom<<"\t"<<aux->sexo<<endl;	
}
void ultimo(tlista lista){
	tlista aux = lista, ultim;
	while(aux != NULL){
		ultim = aux;
		aux = aux->sgte;
	}
	cout <<"\nNUM\tNOMBRE\tPROM\tSEXO\t\n";
	cout <<ultim->numcarnet<<"\t"<<ultim->nom<<"\t"<<ultim->prom<<"\t"<<ultim->sexo<<endl;	
}


int main(){
	SetConsoleOutputCP(CP_UTF8); //para que se escriba "número" y no "n||mero". 
	tlista lista = NULL;
	int numcarnet, prom, n, opc;
	char nom[max], sexo[max];
	do{
		system("cls");
		cout <<"\n1. Ingresar datos.";
		cout <<"\n2. Mostrar datos.";
		cout <<"\n3. Mostrar promedios pares y mayores a 10.";
		cout <<"\n4. Ordenar lista de acuerdo al promedio.";
		cout <<"\n5. Mostrar el primer y el último elemento de la lista.";
		cout <<"\n6. Salir.";
		cout <<"\nElija su opción: "; cin >>opc;
		switch(opc){
            case 1:
                cout <<"\nIngrese el número de personas: "; cin >>n;
                for (int i=0; i<n; i++){
                    cout <<"\nNúmero de carnet ["<<i+1<<"]: "; cin >>numcarnet;
                    cout <<"Nombre ["<<i+1<<"]: "; cin >>nom;
                    cout <<"Promedio ["<<i+1<<"]: "; cin >>prom;
                    cout <<"Sexo ["<<i+1<<"]: "; cin >>sexo;
                    insFINAL(lista, numcarnet, nom, prom, sexo);
                }
                break;
            case 2:
            	cout <<"\nLas personas en la lista son: \n";
            	cout <<"\nNUM\tNOMBRE\tPROM\tSEXO\t\n";
            	imprimir(lista);
            	getch();
            	break;
            case 3:
            	cout <<"\nLos promedios pares y mayores a 10 son: \n";
            	prompares(lista);
            	getch();
            	break;
            case 4:
            	cout <<"\nOrdenando lista de acuerdo al promedio...\n";
            	ordenarprom(lista);
            	cout <<"\nLa lista ordenada de acuerdo al promedio es: \n";
            	cout <<"\nNUM\tNOMBRE\tPROM\tSEXO\t\n";
            	imprimir(lista);
            	getch();
            	break;
            case 5:
            	cout <<"\nEl primer elemento de la lista es: \n";
            	primero(lista);
            	cout <<"\nEl último elemento de la lista es: \n";
            	ultimo(lista);
            	getch();
            	break;
		}
	}while(opc != 6);
	getch();
	return 0;
}





