#pragma once
#ifndef GRAFO_H
#define GRAFO_H
#include "arraylist.h"
#include "NodoGrafo.h"

class Grafo{
private:
	ArrayList<ArrayList<NodoGrafo*>*>* listasNodos;
	int cantidadNodos;
public:
	Grafo(int tamanoGrafo) {
		this->cantidadNodos = 0;
		listasNodos = new ArrayList<ArrayList<NodoGrafo*>*>(tamanoGrafo);
		int conta = 1;
		for (int i = 0; i < tamanoGrafo; i++) {
			listasNodos->insert(new ArrayList<NodoGrafo*>(tamanoGrafo));
			ArrayList<NodoGrafo*>* temp = listasNodos->getElement();
			for (int j = 0; j < tamanoGrafo; j++) {
				temp->append(new NodoGrafo(conta));
				conta++;
				cantidadNodos++;
			}
		}
	}

	~Grafo() {
		listasNodos->clear();
		delete listasNodos;
	}

	ArrayList<ArrayList<NodoGrafo*>*>* retornarListaNodos() {
		return listasNodos;
	}
};
#endif // GRAFO_H

