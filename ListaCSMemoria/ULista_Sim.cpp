//---------------------------------------------------------------------------

#pragma hdrstop

#include "ULista_Sim.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ListaS::ListaS(){
  ptr_elementos=NULO;
  longit=0;
  mem=new  CSMemoria();

}
/*L->[]
   ptr_elementos=-1
   longit=0;
   Memoria
   [----]

*/

ListaS::ListaS(CSMemoria* m){
  ptr_elementos=NULO;
  longit=0;
  mem=m;

}

/*

lista.inserta_primero( E TipoElemento)
Inicio // x tendria direcion de memoria si existe espacio
x=M.New_espacio(‘elemento,sig’)
si x <> nulo entonces
 inicio
 m.poner_dato(x,’->elemento’,E)
 m.poner_dato(x,’->sig’,PtrElementos)
 longitud=longitud + 1
 PtrElementos = x
 fin
 caso contrario // llamar a exception existeespaciomemoria
Fin
*/                          //100
void ListaS::inserta_primero(int e){
  //mem->mostrar();       //sigNL = "->sig"
			//   datosNL="elemento.sig";     //elemNL=->elemento
 int x=mem->new_espacio(datosNL); //0    //Nulo=-1 ,ptr_elementos=-1
 if(x!=NULO){
   //poner_dato(dir,id,valor)
   mem->poner_dato(x,elemNL,e);
   //mem->mostrar();
   mem->poner_dato(x,sigNL,ptr_elementos);
   //mem->mostrar();
   ptr_elementos=x;
   longit++;

 }
 cout<< "ERROR:NO EXISTE ESPACIO EN LA MEMORIA\n";
}

int ListaS::primero() {
	if (!vacia())
		return ptr_elementos;
	else
		cout << "ERROR: LISTA VACIA\n";
}

int ListaS::fin() {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		int x = ptr_elementos; //4
		int ptr_fin;
		while (x != NULO) {
			ptr_fin = x;
			x = mem->obtenerDato(x, sigNL);
		}
		return ptr_fin;
	}
}

void ListaS::inserta_ultimo(int e){
// mem->mostrar();
 int x=mem->new_espacio(datosNL);
 if(x!=NULO){
   //poner_dato(dir,id,valor)
   mem->poner_dato(x,elemNL,e);
  // mem->mostrar();
   mem->poner_dato(x,sigNL,NULO);
   if(vacia()){
	  ptr_elementos=x;
   }else{
	 mem->poner_dato(fin(),sigNL,x);
   }
   //mem->mostrar();

   longit++;

 }
 cout<< "ERROR:NO EXISTE ESPACIO EN LA MEMORIA\n";

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

bool ListaS::vacia(){
 return longit==0;
}

void ListaS::inserta(int d, int e){
// mem->mostrar();
 int x=mem->new_espacio(datosNL);
 if(x!=NULO){
   //poner_dato(dir,id,valor)
   mem->poner_dato(x,elemNL,e);
   //mem->mostrar();
   mem->poner_dato(x,sigNL,NULO);
   if(vacia()){
	  ptr_elementos=x;
	  longit=-1;
   }else{
	  longit++;
	  if(d==primero()){
		  mem->poner_dato(x,sigNL,d);
			ptr_elementos=x;
	  }else{
		  int ant=anterior(d);
		  mem->poner_dato(ant,sigNL,x);
		  mem->poner_dato(x,sigNL,d);
	  }

   }
  // mem->mostrar();



 }else{
	cout<< "ERROR:NO EXISTE ESPACIO EN LA MEMORIA\n";
 }


}

string ListaS::to_str() {
	string s = "<";
	int aux = ptr_elementos;
	while (aux != NULO) {
		int el = mem->obtenerDato(aux, elemNL);
		s += to_string(el);
		aux = mem->obtenerDato(aux, sigNL);
		if (aux != NULO)
			s += ",";
	}
	return s + ">";
}









