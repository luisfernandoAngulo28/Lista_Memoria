#include <iostream>
#include "CSMemoria.h"
#include "ULista_Sim.h"
int main(){
	CSMemoria* MiMemoria;

	ListaS* L;
	MiMemoria = new CSMemoria();
	/*cout << "\nLa memoria ------------------------- "<<endl;
	MiMemoria->mostrar();
	cout << "\n Fin Memoria------------------------------ "<<endl;  */
	L = new ListaS(MiMemoria);
   /*cout << "\n Inicio La Lista ------------------------- "<<endl;

	cout << "\n Lista"<<L->to_str()<<endl;
	cout << "\n Fin La Lista ------------------------- "<<endl;  */
	int z = MiMemoria->new_espacio("feramdo.angulo.heredia");
	int x=MiMemoria->obtenerDato(0,"->fernando");
	/*cout << "\nLa memoria ------------------------- "<<endl;
	MiMemoria->mostrar();
	cout << "\nLa z es: "<<z<<endl;
	cout << "\nLa x es: "<<x<<endl;
	cout << "\n Fin Memoria------------------------------ "<<endl;
	*/
	MiMemoria->poner_dato(z,"->fernando",MiMemoria->obtenerDato(z,"->fernando")+2);
	cout << "\nLa memoria ------------------------- "<<endl;
	MiMemoria->mostrar();
	cout << "\n Fin Memoria------------------------------ "<<endl;
	L->inserta_primero(100);
	cout << "\n Lista1"<<L->to_str()<<endl;

	L->inserta_ultimo(200);
	 //cout << "\n Lista2"<<L->to_str()<<endl;
	L->inserta(L->fin(),150);
	//cout << "\n Lista3"<<L->to_str()<<endl;
	MiMemoria->mostrar();

	system("pause");
	return 0;
}

