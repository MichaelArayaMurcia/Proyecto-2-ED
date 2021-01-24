#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include "dlinkedlist.h"
#include "Vertice.h"
#include "Arista.h"

using namespace std;


class Grafo
{
	Vertice* h; //Primer vertice del grafo
public:
	void Inicializa() {
		h = nullptr;
	}
	
	bool Vacio() {
		return h == nullptr;
	};
	
	int tamano() {
		int conta = 0;
		Vertice* aux;
		aux = h;

		while (aux != nullptr) {
			conta += 1;
			aux = aux->sig;
		}
		return conta;
	};

	Vertice* GetVertice(string nombre) {
		Vertice* aux;
		aux = h;
		while (aux != nullptr) {
			if (aux->nombre == nombre) {
				return aux;
			}
			aux = aux->sig;

		}
		return nullptr;
	};

	void iniciarGrafo(Vertice* inicio) {
		h = inicio;
	};

	void InsertaArista(Vertice* origen, Vertice* destino, int peso) {
		Arista* nueva = new Arista();
		nueva->peso = peso;
		nueva->sig = nullptr;
		nueva->ady = nullptr;
		nueva->setOrigen(origen);

		Arista* aux;

		aux = origen->ady;

		if (aux == nullptr)
		{
			origen->ady = nueva;
			nueva->ady = destino;
		}
		else
		{
			while (aux->sig != nullptr)
			{
				aux = aux->sig;
			}
			aux->sig = nueva;
			nueva->ady = destino;
		}

		origen->insertarArco(nueva);
	};
	
	void InsertaVertice(string nombre) {
		Vertice* nuevo = new Vertice();
		nuevo->nombre = nombre;
		nuevo->sig = nullptr;
		nuevo->ady = nullptr;

		if (Vacio()) {
			h = nuevo;
		}
		else {
			Vertice* aux;
			aux = h;
			while (aux->sig != nullptr) {
				aux = aux->sig;
			}
			aux->sig = nuevo;
		}
	};
	
	void ListaAdyacencia() {
		Vertice* VertAux;
		Arista* ArisAux;

		VertAux = h;
		while (VertAux != nullptr) {
			cout << VertAux->nombre << "->";

			ArisAux = VertAux->ady;
			while (ArisAux != nullptr) {
				cout << ArisAux->ady->nombre << "->";
				ArisAux = ArisAux->sig;

			}

			VertAux = VertAux->sig;
			cout << endl;
		}
	};

	void EliminarArista(Vertice* origen, Vertice* destino) {
		int band = 0;
		Arista* actual;
		Arista* anterior;

		actual = origen->ady;
		anterior = actual;

		if (actual == nullptr)
		{
			cout << "El vertice origen no tiene aristas" << endl;
		}
		else if (actual->ady == destino)
		{
			origen->ady = actual->sig;
			delete(actual);
		}
		else {
			while (actual != nullptr)
			{
				if (actual->ady == destino)
				{
					band = 1;
					anterior->sig = actual->sig;
					delete(actual);
					break;
				}
				anterior = actual;
				actual = actual->sig;
			}
			if (band == 0)
			{
				cout << "Esos dos vertices no estan conectados" << endl;
			}
		}
	};
	
	void Anular() {
		Vertice* aux;

		while (h != nullptr)
		{
			aux = h;
			h = h->sig;
			delete(aux);
		}
	};
	
	void EliminarVertice(Vertice* vert) {
		Vertice* actual, * anterior;
		Arista* aux;

		actual = h;
		anterior = actual;
		while (actual != nullptr) {
			aux = actual->ady;
			while (aux != nullptr) {
				if (aux->ady == vert)
				{
					EliminarArista(actual, aux->ady);
				}
				aux = aux->sig;
			}
			actual = actual->sig;
		}

		actual = h;
		if (h == vert)
		{
			h = h->sig;
			delete(actual);
		}
		else
		{
			while (actual != vert)
			{
				anterior = actual;
				actual = actual->sig;
			}
			anterior->sig = actual->sig;
			delete(actual);
		}
	};
	
	Vertice* NodoActual() {
		return h;
	};
};
#endif