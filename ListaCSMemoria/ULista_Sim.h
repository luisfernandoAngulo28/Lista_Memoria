//---------------------------------------------------------------------------

#ifndef ULista_SimH
#define ULista_SimH
//---------------------------------------------------------------------------
#include<string>
#include<iostream>
#include "CSMemoria.h"
using namespace std;

const string datosNL = "elemento.sig";
const string elemNL = "->elemento";
const string sigNL = "->sig";

/*
----------------------
|datosNL|elemNL|sigNL|
-----------------------


*/
class ListaS {
private:
	int ptr_elementos;//nos dice donde estamos
	int longit;    // nos dice la cantidad
	CSMemoria* mem; //Memoria

public:
	ListaS();
	ListaS(CSMemoria* m);
	int fin();
	int primero();
	int siguiente(int d);
	int anterior(int d);
	bool vacia();
	int recupera(int d);
	int longitud();
	void inserta(int d, int e);
	void inserta_primero(int e);
	void inserta_ultimo(int e);
	void suprime(int d);
	void modifica(int d, int e);
	string to_str();
	int localiza(int e);
	void elimina_dato(int e);
	void anula();
};
#endif
