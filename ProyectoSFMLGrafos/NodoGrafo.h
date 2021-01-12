#pragma once
#ifndef NODOGRAFO_H
#define NODOGRAFO_H
#include "dlinkedlist.h"

using namespace std;

class NodoGrafo{
private:
	Dlinkedlist<NodoGrafo>* listaAdyacentes;
	int id;
	bool visitado;

public:
	NodoGrafo(int id){
		this->id = id;
		listaAdyacentes = new Dlinkedlist<NodoGrafo>();
		visitado = false;
	}
	NodoGrafo() {
		this->id = 0;
		visitado = false;
	}

	~NodoGrafo() {
		delete listaAdyacentes;
	}

	void visitar() {
		visitado = true;
	}

	Dlinkedlist<NodoGrafo>* retornarAdyacentes() {
		return listaAdyacentes;
	}

	void agregarVecinirigillos(NodoGrafo nuevoVecino) {
		listaAdyacentes->append(nuevoVecino);
	}

	int returnid() {
		return	id;
	}

	bool retornarVisitado() {
		return visitado;
	}

};
#endif // NODOGRAFO_H

