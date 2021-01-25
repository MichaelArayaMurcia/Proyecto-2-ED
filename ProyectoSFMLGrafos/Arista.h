#pragma once
#ifndef ARISTA_H
#define ARISTA_H
#include <iostream>
#include "dlinkedlist.h"
#include "Vertice.h"

class Arista
{
private:
	Arista* sig;
	Vertice* ady;
	Vertice* origen;
	int peso;
	friend class Grafo;
	float posX;
	float posY;

public:
	Arista() {
		sig = nullptr;
		ady = nullptr;
		origen = nullptr;
		peso = 1;
		posX = 0;
		posY = 0;
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

	float getposX() {
		return posX;
	}

	float getposY() {
		return posY;
	}

	void setposX(float posX1) {
		posX = posX1;
	}

	void setposY(float posY1) {
		posY = posY1;
	}
};
#endif