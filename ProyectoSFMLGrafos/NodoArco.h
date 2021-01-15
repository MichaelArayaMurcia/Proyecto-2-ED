#pragma once
#ifndef NODOARCO_H
#define NODOARCO_H
#include "dlinkedlist.h"

using namespace std;

class NodoArco {
private:
	//Dlinkedlist<NodoGrafo>* listaAdyacentes;
	int valor;
	bool visitado;

public:
	NodoArco(int valor) {
		this->valor = valor;
		//listaAdyacentes = new Dlinkedlist<NodoGrafo>();
		visitado = false;
	}
	NodoArco() {
		this->valor = 0;
		visitado = false;
	}

	~NodoArco() {
	
	}

	void visitar() {
		visitado = true;
	}


	int returnValor() {
		return	valor;
	}

	bool retornarVisitado() {
		return visitado;
	}

};
#endif // NODOARCO_H

