#pragma once
#ifndef NODOGRAFO_H
#define NODOGRAFO_H
#include "dlinkedlist.h"
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


};
#endif // NODOGRAFO_H

