//1° práctica EDA
//me falta moviementos PIPIPI
#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#define max 15
using namespace std;

struct datcuentas{
    int numcuenta;
    int saldo;
};
struct clientes{
    int cod;
    string nom;
    string dirc;
    int telef;
    struct datcuentas cuenta;
};

void menu(){
    cout <<"\nBIENVENIDO AL BANCO";
    cout <<"\n1. Ingresar datos.";
    cout <<"\n2. Mostrar datos.";
    cout <<"\n3. Retirar dinero.";
    cout <<"\n4. Depositar dinero.";
    cout <<"\n5. Ordena los nombres alfabéticamente.";
    cout <<"\n7. Salir.";
    cout <<"\nElija su opción: ";
}
void ingresar(struct clientes c[max], int x){
    for(int i=0; i<x; i++){
        cout <<"\nIngrese el código del cliente: "; cin >>c[i].cod;
        fflush(stdin);
        cout <<"Ingrese el nombre del cliente: "; getline(cin, c[i].nom, '\n');
        cout <<"Ingrese la dirección del cliente: "; getline(cin, c[i].dirc, '\n');
        cout <<"Ingrese el teléfono del cliente ["<<i+1<<"]: "; cin >>c[i].telef;
		cout <<"Ingrese el número de cuenta del cliente ["<<i+1<<"]: "; cin >>c[i].cuenta.numcuenta;
		cout <<"Ingrese el monto de la cuenta del cliente ["<<i+1<<"]: "; cin >>c[i].cuenta.saldo;
    }
}
void mostrar(struct clientes c[max], int x){
    for(int i=0; i<x; i++){
        cout <<"  "<<c[i].cod<<"\t"<<c[i].nom<<"\t"<<c[i].dirc<<"\t"<<c[i].telef<<"\t"<<c[i].cuenta.numcuenta<<"\t"<<c[i].cuenta.saldo<<endl;
    }
}
bool retirar(struct clientes c[max], int x, string nom){
    int retiro;
    for(int i=0; i<x; i++){
        if(nom == c[i].nom){
            cout <<"Cliente encontrado.\n";
            do{
                cout <<"Ingrese monto de retiro: "; cin >>retiro;
            }while(retiro > c[i].cuenta.saldo);
            c[i].cuenta.saldo = c[i].cuenta.saldo - retiro;
            cout <<"Saldo actual: "<<c[i].cuenta.saldo<<endl;
            return true;
        }
    }
    cout <<"Cliente no encontrado.\n";
    return false;
}
bool depositar(struct clientes c[max], int x, string nom){
    int deposito;
    for(int i=0; i<x; i++){
        if(nom == c[i].nom){
            cout <<"Cliente encontrado.\n";
            cout <<"Ingrese monto de depósito: "; cin >>deposito;
            c[i].cuenta.saldo = c[i].cuenta.saldo + deposito;
            cout <<"Saldo actual: "<<c[i].cuenta.saldo<<endl;
            return true;
        }
    }
    cout <<"Cliente no encontrado.\n";
    return false;
}
void ordenarAlfabeticamente(struct clientes c[max], int x) {
    char nombrei[max], nombrej[max];
    string tnom, tdirc;
    int tcod, ttelef, tnumc, tsaldo;
    for (int i=0; i<x; i++) {
        for (int j=i; j<x; j++){
            strcpy(nombrei,c[i].nom.c_str());
            strcpy(nombrej,c[j].nom.c_str());
            if (strcmp(nombrei, nombrej) > 0) {
                tcod = c[i].cod;
                c[i].cod = c[j].cod;
                c[j].cod = tcod;

                tnom = c[i].nom;
                c[i].nom = c[j].nom;
                c[j].nom = tnom;

                tdirc = c[i].dirc;
                c[i].dirc = c[j].dirc;
                c[j].dirc = tdirc;

                ttelef = c[i].telef;
                c[i].telef = c[j].telef;
                c[j].telef = ttelef;

                tnumc = c[i].cuenta.numcuenta;
                c[i].cuenta.numcuenta = c[j].cuenta.numcuenta;
                c[j].cuenta.numcuenta = tnumc;

                tsaldo = c[i].cuenta.saldo;
                c[i].cuenta.saldo = c[j].cuenta.saldo;
                c[j].cuenta.saldo = tsaldo;
            }
        }
    }
    cout << "Nombres ordenados alfabéticamente: \n";
}

/*
void movimientos(struct clientes c[max], int x, string nom){

}
*/


int main(){
    SetConsoleOutputCP(CP_UTF8); //para que se escriba "número" y no "n||mero"
    system("cls");
    struct clientes c[max];
    int opc, n;
    string nom;
    do{
        menu();
        cin >>opc;
        switch(opc){
            case 1:
                cout <<"Ingrese la cantidad de clientes: "; cin >>n;
		        cout <<"Ingrese los datos de los clientes: \n"; ingresar(c, n);
                break;
            case 2:
                cout <<"  COD\tNOMBRE\tDIRECCIÓN\tTELÉFONO\tN°CUENTA\tSALDO\n";
                mostrar(c, n);
                break;
            case 3:
                cout <<"Ingrese el cliente a buscar: "; cin >>nom;
                if(retirar(c, n, nom))
                    cout <<"Saldo retirado.\n";
                break;
            case 4:
                cout <<"Ingrese el cliente a buscar: "; cin >>nom;
                if(depositar(c, n, nom))
                    cout <<"Saldo depositado.\n";
                break;
            case 5:
                cout <<"Ordenando nombres alfabéticamente...\n";
                ordenarAlfabeticamente(c, n); 
                cout <<"  COD\tNOMBRE\tDIRECCIÓN\tTELÉFONO\tN°CUENTA\tSALDO\n";
                mostrar(c, n);
        }
    }while(opc != 7);
    getch();
    return 0;
}


