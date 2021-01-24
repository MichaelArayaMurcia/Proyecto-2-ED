#pragma once
#ifndef VERTICE_H
#define VERTICE_H
#include <iostream>
#include "dlinkedlist.h"

class Arista;

class Vertice
{
private:
	Vertice* sig;
	Arista* ady;
	string nombre;
	bool visitado;
	Dlinkedlist<Vertice*>* listaAdyacentes;
	Dlinkedlist<Arista*>* listaArcos;
	friend class Grafo;

public:
	Vertice() {
		listaAdyacentes = new Dlinkedlist<Vertice*>();
		listaArcos = new Dlinkedlist<Arista*>();
		visitado = false;
		sig = nullptr;
		ady = nullptr;
	}

	~Vertice() {}

	Vertice* getVerticesig() {
		return sig;
	}

	Arista* getAristaady() {
		return ady;
	}

	void insertarArco(Arista* nuevoArco) {
		listaArcos->append(nuevoArco);
	}

	string getNombre() {
		return nombre;
	}

	bool getVisitado() {
		return visitado;
	}

	Dlinkedlist<Vertice*>* getlistaAdyacentes() {
		return listaAdyacentes;
	}

	Dlinkedlist<Arista*>* getlistaArcos() {
		return listaArcos;
	}

	Vertice* setVerticesig(Vertice* siguiente) {
		sig = siguiente;
	}

	Arista* setAristaady(Arista* adyacente) {
		ady = adyacente;
	}

	string setNombre(string Nombre) {
		nombre = Nombre;
	}

	void setVisitado(bool Valor) {
		visitado = Valor;
	}

	Dlinkedlist<Vertice*> setlistaAdyacentes(Dlinkedlist<Vertice*>* otraLista) {
		listaAdyacentes = otraLista;
	}
};
#endif