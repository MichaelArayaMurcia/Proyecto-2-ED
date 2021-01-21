#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include "dlinkedlist.h"


using namespace std;

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

	Dlinkedlist<Vertice*>* getlistaAdyacentes(){
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

	bool setVisitado(bool Valor) {
		visitado = Valor;
	}

	Dlinkedlist<Vertice*> setlistaAdyacentes(Dlinkedlist<Vertice*>* otraLista) {
		listaAdyacentes = otraLista;
	}
};

class Arista
{
private:
	Arista* sig;
	Vertice* ady;
	int peso;
	friend class Grafo;

public:
	Arista* getAristasig() {
		return sig;
	}

	Vertice* getVerticeady() {
		return ady;
	}

	int getPeso() {
		return peso;
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

class Grafo
{
	Vertice* h; //Primer vertice del grafo
public:
	void Inicializa();
	bool Vacio();
	int tamano();
	Vertice* GetVertice(string nombre);
	void iniciarGrafo(Vertice* inicio);
	void InsertaArista(Vertice* origen, Vertice* destino, int peso);
	void InsertaVertice(string nombre);
	void ListaAdyacencia();
	void EliminarArista(Vertice* origen, Vertice* destino);
	void Anular();
	void EliminarVertice(Vertice* vert);
	Vertice* NodoActual();
};
#endif