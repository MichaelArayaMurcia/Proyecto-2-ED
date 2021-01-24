#pragma once
#ifndef ARISTA_H
#define ARISTA_H
#include <iostream>
#include "dlinkedlist.h"
class Arista
{
private:
	Arista* sig;
	Vertice* ady;
	Vertice* origen;
	int peso;
	friend class Grafo;

public:
	Arista() {
		sig = nullptr;
		ady = nullptr;
		origen = nullptr;
		peso = 1;
	}

	~Arista() {}

	Arista* getAristasig() {
		return sig;
	}

	Vertice* getVerticeady() {
		return ady;
	}

	int getPeso() {
		return peso;
	}

	void setOrigen(Vertice* origen) {
		this->origen = origen;
	}

	Vertice* getOrigen() {
		return origen;
	}

	Arista* setAristasig(Arista* siguiente) {
		sig = siguiente;
	}

	Vertice* setVerticeady(Vertice* adyacente) {
		ady = adyacente;
	}

	int setPeso(int nuevoPeso) {
		peso = nuevoPeso;
	}
};
#endif