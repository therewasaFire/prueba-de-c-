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
    int movimientos[max][max];
};
struct clientes{
    int cod;
    string nom;
    string dirc;
    int telef;
    struct datcuentas cuenta;
};

struct Movimientoretiro{
    string nombre;
    int retiro;
};
struct Movimientodeposito{
    string nombre;
    int Deposito;
};

//VARIABLES GLOBALES
int depo=0,reti=0;

void menu(){
    cout <<"\n\t.:BIENVENIDO AL BANCO:.";
    cout <<"\n\t1. Ingresar datos.";
    cout <<"\n\t2. Mostrar datos.";
    cout <<"\n\t3. Retirar dinero.";
    cout <<"\n\t4. Depositar dinero.";
    cout <<"\n\t5. Ordena los nombres alfabéticamente.";
    cout <<"\n\t6. Ver movimientos.";
    cout <<"\n\t0. Salir.";
    cout <<"\n\tElija su opción: ";
}
void menumov(){
    cout <<"\n\t.:MOVIMIENTOS BANCARIOS:.";
    cout <<"\n\t1. Depositos.";
    cout <<"\n\t2. Retiro.";
    cout <<"\n\t0. Salir.";
    cout <<"\n\tElija su opción: ";
}
void ingresar(struct clientes c[max], int x){
    int mov = 0;
    for(int i=0; i<x; i++){
        cout <<"\n\tCódigo ["<<i+1<<"]: "; cin >>c[i].cod;
        fflush(stdin);
        cout <<"\tNombre ["<<i+1<<"]: "; getline(cin, c[i].nom, '\n');
        cout <<"\tDirección ["<<i+1<<"]: "; getline(cin, c[i].dirc, '\n');
        cout <<"\tTeléfono ["<<i+1<<"]: "; cin >>c[i].telef;
		cout <<"\tNum. cuenta ["<<i+1<<"]: "; cin >>c[i].cuenta.numcuenta;
		cout <<"\tMonto de cuenta ["<<i+1<<"]: "; cin >>c[i].cuenta.saldo;
        c[i].cuenta.movimientos[i][mov] = c[i].cuenta.saldo;
    }
}
void mostrar(struct clientes c[max], int x){
    for(int i=0; i<x; i++){
        cout <<"\t  "<<c[i].cod<<"\t"<<c[i].nom<<"\t"<<c[i].dirc<<"\t"<<c[i].telef<<"\t"<<c[i].cuenta.numcuenta<<"\t"<<c[i].cuenta.saldo<<endl;
    }
}
bool retirar(struct clientes c[max],struct Movimientoretiro m[max], int x, string nom){
    int retiro;
    for(int i=0; i<x; i++){
        if(nom == c[i].nom){
            cout <<"\tCliente encontrado.\n";
            do{
                cout <<"\tIngrese monto de retiro: "; cin >>retiro;
            }while(retiro > c[i].cuenta.saldo);
            c[i].cuenta.saldo = c[i].cuenta.saldo - retiro;
            cout <<"\n\tSaldo actual: "<<c[i].cuenta.saldo<<endl;
            m[reti].nombre=nom;
            m[reti].retiro=retiro;
            reti++;
            return true;
        }
    }
    cout <<"\n\t\tCliente no encontrado.\n";
    return false;
}
bool depositar(struct clientes c[max],struct Movimientodeposito m[max], int x, string nom){
    int deposito;
    for(int i=0; i<x; i++){
        if(nom == c[i].nom){
            cout <<"\tCliente encontrado.\n";
            cout <<"\tIngrese monto de depósito: "; cin >>deposito;
            c[i].cuenta.saldo = c[i].cuenta.saldo + deposito;
            cout <<"\n\tSaldo actual: "<<c[i].cuenta.saldo<<endl;
            m[depo].nombre=nom;
            m[depo].Deposito=deposito;
            depo++;
            return true;
        }
    }
    cout <<"\n\t\tCliente no encontrado.\n";
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
    cout << "\tNombres ordenados alfabéticamente: \n";
}

void verMovimientoret(struct Movimientoretiro c[max], int x){
    for(int i=0; i<x; i++){
        cout<<"\n\tNombre : "<<c[i].nombre;
        cout<<"\n\tRetiro : "<<c[i].retiro;
        cout<<endl;
    }
}
void verMovimientodep(struct Movimientodeposito c[max],int x){
    for(int i=0; i<x; i++){
        cout<<"\n\tNombre : "<<c[i].nombre;
        cout<<"\n\teposito : "<<c[i].Deposito;
        cout<<endl;
    }
}


int main(){
    SetConsoleOutputCP(CP_UTF8); //para que se escriba "número" y no "n||mero"
    struct clientes c[max];
    struct Movimientoretiro ret[max];
    struct Movimientodeposito dep[max];
    int opc,opc6,n;
    string nom;
    do{
        system("cls");
        menu(); cin >>opc;
        system("cls");
        switch(opc){
            case 1:
                cout <<"\n\tIngrese la cantidad de clientes: "; cin >>n;
		        cout <<"\tIngrese los datos de los clientes: \n"; ingresar(c, n);
                getch(); break;
            case 2:
                mostrar(c, n);
                getch(); break;
            case 3:
                cout <<"\n\tIngrese el cliente a buscar: "; cin >>nom;
                if(retirar(c,ret,n, nom))
                    cout <<"\tSaldo retirado.\n";
                getch(); break;
            case 4:
                cout <<"\n\tIngrese el cliente a buscar: "; cin >>nom;
                if(depositar(c,dep,n, nom))
                    cout <<"\tSaldo depositado.\n";
                getch(); break;
            case 5:
                cout <<"\tOrdenando nombres alfabéticamente...\n";
                ordenarAlfabeticamente(c, n); 
                cout <<"  \tCOD\tNOMBRE\tDIRECCIÓN\tTELÉFONO\tN°CUENTA\tSALDO\n";
                mostrar(c, n);
                getch(); break;
            case 6:
                system("cls");
                do{
                    system("cls");
                    menumov(); cin >>opc6;
                    switch(opc6){
                        case 1:
                            system("cls");
                            cout<<"\tDEPOSITOS"<<endl;
                            verMovimientodep(dep,depo);
                            getch(); break;
                        case 2:
                            system("cls");
                            cout<<"\tRETIROS"<<endl;
                            verMovimientoret(ret,reti);
                            getch(); break;
                        }
                    }while(opc6!= 0);
                getch(); 
                break;
        }
    }while(opc != 0);
    getch();
    return 0;
}



/*
mostrar

    for(int i=0; i<x; i++){
        cout<<"Cliente "<<i+1<<"";
        cout <<"\n\tCodigo  :"<<c[i].cod;
        cout<<"\n\tNombre   : "<<c[i].nom;
        cout<<"\n\tDireccion: "<<c[i].dirc;
        cout<<"\n\tTelefeno : "<<c[i].telef;
        cout<<"\n\tCuenta   :"<<c[i].cuenta.numcuenta;
        cout<<"\n\tSaldo    : "<<c[i].cuenta.saldo<<endl;
    }
*/

