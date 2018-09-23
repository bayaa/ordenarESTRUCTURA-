#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct nodo
{
    int dato;
    struct nodo *siguiente;
}*inicio,*aux,*actual;
void eliminarNodo(int);
void insertarNodo(int);
void mostrarNodo();
void ordenar(int);
void posicion(int);

int main()
{
    inicio = NULL;
    int dato;
    int salida,cuenta=0;
    int menu;
    do
    {
        cout<<"\t\nMENU\n\t(1)INSERTARDATOS\n\t(2)MOSTRAR DATOS\n\t(3)BORRAR DATOS\n\t(4)SALIR\n";
        cin>>menu;
        switch(menu)
        {
        case 1:
            cout << "\tSALIR OPRIMA  -1" << endl;
            do
            {
                cout << "\tDATO : >>>>>>>>   ";
                cin >> dato;
                if(dato != -1)
                {
                    cuenta++;
                    insertarNodo(dato);
                }


            }
            while (dato != -1 );

            break;
        case 2:
            cout<<"\t\tNODOS\n";
            mostrarNodo();


            break;
        case 3:
            int variable,respuesta;
            do
            {
                mostrarNodo();
                cout<<"\tEliminar nodo (FIN -1)"<<endl;
                cin>>variable;
                eliminarNodo(variable);

            }
            while (variable!= -1);
            cout<<"\t\tNODOS\n";
            mostrarNodo();
            break;

        default:
            break;



        }
    }
    while (menu !=4);



    cout<<"\n\tFINAL";




    //cin.get();
    return 0;
}

void insertarNodo(int valor)
{
    actual=inicio;
    if(actual == NULL)
    {
        aux = new nodo();
        aux->dato = valor;
        aux->siguiente = NULL;
        inicio = aux;
    }
    else
    {
        while(actual->siguiente != NULL)
        {
            actual=actual->siguiente;
        }
        aux = new nodo();
        aux->dato = valor;
        aux->siguiente = NULL;
        actual->siguiente = aux;
    }

}

void mostrarNodo()
{
    actual = inicio;
    int contador=0;
    do
    {
        contador++;
        cout <<"\t\t"<< contador <<".- " << actual->dato << " " << endl;
        actual=actual->siguiente;
    }
    while(actual!= NULL);

}

void posicion(int valor)
{
    actual = inicio;
    int contador=0;
    do
    {
        contador++;
        if(contador == valor)
        {
            cout <<"\t\t"<< contador <<".- " << actual->dato << " " << endl;
        }

        actual=actual->siguiente;
    }
    while(actual!= NULL);
}
void ordenar(int cantidad)
{
    nodo *aux1;
    //aux1 = inicio;

    do
    {
        actual=inicio;
        while (actual->siguiente != NULL)
        {

            aux = actual->siguiente;

            while(aux != NULL)
            {

                if(actual->dato > actual->siguiente->dato)
                {

                    aux1->dato = actual->dato;
                    actual->dato = actual->siguiente->dato;
                    actual->siguiente->dato = aux1->dato;

                }
                aux = aux->siguiente;

            }

            actual = actual->siguiente;
        }

        cantidad--;
    }
    while(cantidad != 0);
}
void eliminarNodo(int valor)
{
    if(inicio!=NULL)
    {
        aux=NULL;
        actual=inicio;
        while((actual!=NULL) && (actual->dato!=valor))
        {
            aux=actual;
            actual=actual->siguiente;
        }
        if(actual==NULL)
        {
            cout<<"\n\nDATO NO EXISTE"<<endl;
        }
        else if(aux==NULL)
        {
            inicio=inicio->siguiente;
            delete actual;
        }
        else
        {
            aux->siguiente=actual->siguiente;
            delete actual;
        }
    }
}
