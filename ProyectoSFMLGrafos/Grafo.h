#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <queue>
#include <list>
#include <stack>

using namespace std;

class Arista;

class Vertice
{
private:
	Vertice* sig;
	Arista* ady;
	string nombre;
	bool visitado;
	list<Vertice*> listaAdyacentes;
	friend class Grafo;

public:
	Vertice* getVerticesig() {
		return sig;
	}

	Arista* getAristaady() {
		return ady;
	}

	string getNombre() {
		return nombre;
	}

	bool getVisitado() {
		return visitado;
	}

	list<Vertice*> getlistaAdyacentes(){
		return listaAdyacentes;
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

	list<Vertice*> setlistaAdyacentes(list<Vertice*> otraLista) {
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
	void InsertaArista(Vertice* origen, Vertice* destino, int peso);
	void InsertaVertice(string nombre);
	void ListaAdyacencia();
	void EliminarArista(Vertice* origen, Vertice* destino);
	void Anular();
	void EliminarVertice(Vertice* vert);
	void RecorridoAnchura(Vertice* origen);
	void RecorridoProfundidad(Vertice* origen);
	void RecorridoProfundidadModificado();
};
#endif