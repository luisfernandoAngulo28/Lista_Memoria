//---------------------------------------------------------------------------

#pragma hdrstop

#include "CSMemoria.h"
//---------------------------------------------------------------------------
#include <iomanip>
#include <sstream>
#include <iostream>
int Numero_lds(string cadena){
	int cont=0;
	for (int i = 0; i < cadena.length(); i++) {
		if (cadena[i]=='.') {
			cont++;
		}
	}

	cont += (cadena.empty()?0:1);
	return cont;
}

string Obtener_id(string cadena,int n){
	string palabra = "";
	int i = 0;
	int contador = 0;
	while(contador<n-1 && i<cadena.length()-1){
		if(cadena.at(i)=='.'){
			contador+=1;
			cadena = cadena.substr(i+1,cadena.length()-(cadena.substr(0,i).length()));
			i=-1;
		}
		i+=1;
	}
	i=0;
	while(cadena[i]!='.' && i<cadena.length()){
			i+=1;
	}
	palabra = cadena.substr(0,i);

	return palabra;
}

void eliminarFlecha(string &cadena){
	int index = 0;
	if(cadena!=""){
		while (cadena[index]!='-' && cadena[index+1]!='>'){
			index+=1;
		}
	cadena = cadena.substr(index+2,cadena.length()-(cadena.substr(0,index+1).length()));
	}
}

CSMemoria::CSMemoria() {
	mem = new NodoM[MAX_MEMORIA];
	for(int i=0; i<MAX_MEMORIA;i=i+1){
		mem[i].dato = 0;
		mem[i].link = i+1;
	};
	mem[MAX_MEMORIA-1].link = -1;
	libre = 0;
}

direccion_mem CSMemoria::new_espacio(string cadena){
int cant = Numero_lds(cadena);
int dir = libre;
int d = libre;
	for(int i = 1;i<=cant-1;i =i+1){
		mem[d].id=Obtener_id(cadena,i);
		d = mem[d].link;
	}
	libre= mem[d].link;
	mem[d].link= -1;
	mem[d].id= Obtener_id(cadena,cant);
	return dir;
}

void CSMemoria::delete_espacio(direccion_mem dir) {
	int x = dir;
	while(mem[x].link !=-1){
		x = mem[x].link;
	}
	mem[x].link= libre;
	libre = dir;
}

void CSMemoria::poner_dato(direccion_mem dir, string id, int valor) {
	int z = dir;
	eliminarFlecha(id);
	while(z!=NULO){
		if(mem[z].id == id){
			mem[z].dato = valor;
		}
			z=mem[z].link;
	}

}

int CSMemoria::obtenerDato(direccion_mem dir, string id) {
	int z = dir;
	bool ex = false;
	eliminarFlecha(id);
	while(z!=NULO){
		if(mem[z].id == id)
			return mem[z].dato;
		z = mem[z].link;
	}
}

int CSMemoria::Espacio_disponible() {
	int x = libre;
	short c = 0;
	while(x!=NULO){
		c++;
		x = mem[x].link;
	}
	return c;
}

int CSMemoria::Espacio_ocupado() {
	short c = (MAX_MEMORIA)-Espacio_disponible();
	return c;
}

bool CSMemoria::dir_libre(direccion_mem dir) {
	int x = libre;
	int c =  false;
	while(x!=NULO && c == false){
		if(x == dir ){
			c = true;
		}
		x = mem[x].link;
	}
	return c;
}

void CSMemoria::mostrar(){
	stringstream oc;
	stringstream lb;
	oc<<"        OCUPADOS         \n"<<
		"+---------------------- +\n"<<
		"|DIR|"<<"DATO|"<<"---ID----|"<<"LINK|\n"<<setfill(' ');
	string ocupados;
	lb<<"          LIBRES         \n"<<
		"+---------------------- +\n"<<
		"|DIR|"<<"DATO|"<<"---ID----|"<<"LINK|\n";
	string libres;

	for( int i = 0 ; i < MAX_MEMORIA; i++){
		if(dir_libre(i)){
			lb<<"|"<<setw(3)<<i<<"|"<<setw(4)<<
			mem[i].dato<<"|"<<setw(9)<<mem[i].id<<
			"|"<<setw(4)<<mem[i].link<<"|\n";

		}
		if(!(dir_libre(i))){
			oc<<"|"<<setw(3)<<i<<"|"<<setw(4)<<
			mem[i].dato<<"|"<<setw(9)<<mem[i].id<<
			"|"<<setw(4)<<mem[i].link<<"|\n";

		}
	}

	oc<<"+-----------------------+\n";
	lb<<"+-----------------------+\n";
	cout<<oc.str()<<lb.str();
	cout<<"+\n";
	cout<<"LIBRE:"<<libre<<"\n";
	cout<<"ESPACIO DISPONIBLE:"<<Espacio_disponible()<<"\n";
	cout<<"ESPACIO OCUPADO:"<<Espacio_ocupado();

}

#pragma package(smart_init)
