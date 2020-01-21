

#include <iostream>
#include<stdio.h>
#include <string>
#include <curses.h>
using namespace std;
struct Nodo{
  Nodo *siguiente;
  int dato;
};
void buscarDato(Nodo *& , int);
void leerLista(Nodo *& ,int );
void agregarLista(Nodo *&,int);
void quitarElemento(Nodo *& ,int);
void quitarLista (Nodo *&,int );
int main(){
  Nodo *lista=NULL;
  int dato=0;
  cout<<"inserte el numero";
  cin>>dato;
  agregarLista(lista,dato);
  cout<<"inserte el numero";
  cin>>dato;
  agregarLista(lista,dato);
  cout<<"inserte el numero";
  cin>>dato;
  agregarLista(lista,dato);
  leerLista(lista,dato);
  cout<<"dijite el numero a buscar";
  cin>>dato;
  buscarDato(lista,dato);
  cout<<"dijite el numero a borrar";
  cin>>dato;
  quitarElemento(lista,dato);
  leerLista(lista,dato);
  quitarLista(lista,dato);
  leerLista(lista,dato);  
}
void quitarLista(Nodo *& _lista,int d){
  
  Nodo *aux=_lista; 
  d=aux->dato;
  _lista=aux->siguiente;
  delete aux;
}
void quitarElemento(Nodo *&_lista ,int d){
  if(_lista!=NULL){
    Nodo *atras=NULL;
    Nodo *borrar=_lista;
    while((borrar!=NULL)&&(borrar->dato!=d)){
      atras=borrar;
      borrar=borrar->siguiente;
    }
    if(atras==NULL){
      _lista=_lista->siguiente;
      delete borrar;
      cout<<"su numero "<<d <<"fue borrado de la lista";
    }
    else {
      atras->siguiente=borrar->siguiente;
      delete borrar;
      cout<<"su numero"<<d <<"fue borrado de la lista"; 
    }
  }
}
void buscarDato (Nodo*& _lista , int d){
  Nodo *actual=new Nodo();
  actual=_lista;
  bool val=false;
  int i=0;
  while((actual!=NULL)&&(actual->dato<=d)){
    if(actual->dato==d)val=true;
    actual=actual->siguiente;
    if(val==false)i++;
  }
  if(val==true)cout<<"su numero "<<d<< "si fue encontrado y esta en la posicion "<<i;
  else cout<<"su numero no fue encontrado";
}
void leerLista(Nodo *&  _lista ,int d){
  Nodo *lugar=new Nodo();
  lugar=_lista;
  cout<<"su lista es";
  while(lugar!=NULL ){
  cout<<" ->"<<lugar->dato;
  lugar=lugar->siguiente;
  }
}
void agregarLista(Nodo *&  _lista,int d){
  Nodo *nuevoNodo=new Nodo();
  nuevoNodo->dato=d;
  Nodo *aux=_lista;
  Nodo *aux1;
  
  while(aux!=NULL&&aux->dato<d){
    aux1=aux;
    aux=aux->siguiente;
  }
  if(_lista==aux){
    _lista=nuevoNodo;
  }
  else{
   aux1->siguiente=nuevoNodo;
  }
  cout<<d<<"dato insertado ajja¡¡\n";  
  nuevoNodo->siguiente=aux;	
 
}
