#include <iostream>
#include "CSMemoria.h"
#include "ULista_Sim.h"
int main(){
	CSMemoria* MiMemoria;
	ListaS* L;
	///Constructores

	MiMemoria=new  CSMemoria();
	/*cout << "\nLa memoria ------------------------- "<<endl;
	MiMemoria->mostrar();
	cout << "\n Fin Memoria------------------------------ "<<endl;*/
	L=new ListaS(MiMemoria);
	//cout << "\n Lista"<<L->to_str()<<endl;
	int z=MiMemoria->new_espacio("fernando.angulo.heredia");
	MiMemoria->mostrar();
	//cout << "\nLa z es: "<<z<<endl;
	MiMemoria->poner_dato(z,"->fernando",MiMemoria->obtenerDato(z,"->fernando")+2);
	  //	MiMemoria->mostrar();
	L->inserta_primero(100);
	 cout << "\n insertar ultimo ";
	L->inserta_ultimo(200);
		 cout << "\n insertar ultimo ";
	L->inserta(L->fin(),150);
	cout << "\n Lista3"<<L->to_str()<<endl;
	MiMemoria->mostrar();

  system("pause");
  return 0;

}
