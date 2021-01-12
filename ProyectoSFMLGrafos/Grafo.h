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
		listasNodos = new ArrayList<ArrayList<NodoGrafo*>*>(tamanoGrafo);
		int conta = 1;
		for (listasNodos->gotoStart(); !listasNodos->atEnd();listasNodos->next()) {
			listasNodos->insert(new ArrayList<NodoGrafo*>(tamanoGrafo));
			ArrayList<NodoGrafo*>* temp = listasNodos->getElement();
			for (temp->gotoStart(); !temp->atEnd(); temp->next()) {
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

