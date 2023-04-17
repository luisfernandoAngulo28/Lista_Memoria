//---------------------------------------------------------------------------

#pragma hdrstop

#include "ULista_Sim.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

ListaS::ListaS() {
	ptr_elementos = NULO;
	longit = 0;
	mem = new CSMemoria();

}

ListaS::ListaS(CSMemoria* m) {
	ptr_elementos = NULO;
	longit = 0;
	mem = m;
}

int ListaS::fin() {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		int x = ptr_elementos; //-1
		int ptr_fin;
		while (x != NULO) {
			ptr_fin = x;
			x = mem->obtenerDato(x, sigNL);
		}
		return ptr_fin;
	}
}

int ListaS::primero() {
	if (!vacia())
		return ptr_elementos;
	else
		cout << "ERROR: LISTA VACIA\n";
}

int ListaS::siguiente(int d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (d == fin())
			cout << "ERROR: DIRECCION ERRONEA\n";
		else
			return mem->obtenerDato(d, sigNL);
	}
}

int ListaS::anterior(int d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (d == primero())
			cout << "ERROR: DIRECCION ERRONEA\n";
		else {
			int x = ptr_elementos;
			int ant = NULO;
			while (x != NULO) {
				if (x == d)
					return ant;
				ant = x;
				x = mem->obtenerDato(x, sigNL);
			}
			return NULO;
		}
	}
}

bool ListaS::vacia() {
	return longit == 0;
}

int ListaS::recupera(int d) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else
		return mem->obtenerDato(d, elemNL);
}

int ListaS::longitud() {
	return longit;
}

void ListaS::inserta(int d, int e) {
	int x = mem->new_espacio(datosNL);
	if (x != NULO) {
		mem->poner_dato(x, elemNL, e);
		mem->poner_dato(x, sigNL, NULO);
		if (vacia()) {
			ptr_elementos = x;
			longit = 1;
		}
		else {
			longit++;
			if (d == primero()) {
				mem->poner_dato(x, sigNL, d);
				ptr_elementos = x;
			}
			else {
				int ant = anterior(d);
				mem->poner_dato(ant, sigNL, x);
				mem->poner_dato(x, sigNL, d);
			}
		}
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaS::inserta_primero(int e) {
	mem->mostrar();  // "elemento.sig"
	int x = mem->new_espacio(datosNL);
	cout << "\nLa x es: "<<x<<endl;
	if (x != NULO) {
		cout << "\nLa y es: "<<x<<endl;
		cout << "\nLa e es: "<<e<<endl;
		cout << "\nLa elemNL es: "<<elemNL<<endl;
		cout << "\nLa ptr_elementos es: "<<ptr_elementos<<endl;
		mem->poner_dato(x, elemNL, e);
		mem->poner_dato(x, sigNL, ptr_elementos);
		ptr_elementos = x;
		longit++;
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaS::inserta_ultimo(int e) {
	int x = mem->new_espacio(datosNL);
	if (x != NULO) {
		mem->poner_dato(x, elemNL, e);
		mem->poner_dato(x, sigNL, NULO);
		if (vacia())
			ptr_elementos = x;
		else
			mem->poner_dato(fin(), sigNL, x);
		longit++;
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaS::suprime(int d) {
	if (longit == 0) {
		cout << "ERROR: LISTA VACIA\n";
		return;
	}
	if (d == ptr_elementos) {
		int x = ptr_elementos;
		ptr_elementos = mem->obtenerDato(ptr_elementos, sigNL);
		mem->delete_espacio(x);
	}
	else {
		int ant = anterior(d);
		mem->poner_dato(ant, sigNL, mem->obtenerDato(d, sigNL));
		mem->delete_espacio(d);
	}
	longit--;
}

void ListaS::modifica(int d, int e) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else
		mem->poner_dato(d, elemNL, e);
}

string ListaS::to_str() {
	string s = "[";
	int aux = ptr_elementos;
	while (aux != NULO) {
		int el = mem->obtenerDato(aux, elemNL);
		s += to_string(el);
		aux = mem->obtenerDato(aux, sigNL);
		if (aux != NULO)
			s += ",";
	}
	return s + "]";
}

int ListaS::localiza(int e) {
	int aux = ptr_elementos;
	while (aux != NULO) {
		if (mem->obtenerDato(aux, elemNL) == e)
			return aux;
		aux = mem->obtenerDato(aux, sigNL);
	}
	return NULO;
}

void ListaS::elimina_dato(int e) {
	int aux = ptr_elementos;
	while (aux != NULO) {
		if (mem->obtenerDato(aux, elemNL) == e) {
			int sup = aux;
			aux = mem->obtenerDato(aux, sigNL);
			suprime(sup);
		}
		else
			aux = mem->obtenerDato(aux, sigNL);
	}
}

void ListaS::anula() {
	while (!vacia())
		suprime(primero());
}
