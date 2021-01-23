#include "Grafo.h"

void Grafo::Inicializa() 
{
	h = nullptr;
}

bool Grafo::Vacio()
{
	return h == nullptr;
}

int Grafo::tamano() 
{
	int conta = 0;
	Vertice* aux;
	aux = h;

	while(aux != nullptr){
		conta += 1;
		aux = aux->sig;
	}
	return conta;
}

Vertice* Grafo::GetVertice(string nombre)
{
	
	Vertice* aux;
	aux = h;
	while (aux != nullptr) {
		if (aux->nombre == nombre) {
			return aux;
		}
		aux = aux->sig;

	}
	return nullptr;
}

void Grafo::InsertaVertice(string nombre)
{
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
}

void Grafo::InsertaArista(Vertice *origen, Vertice *destino, int peso) 
{
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

}

void Grafo::ListaAdyacencia() 
{
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
}

void Grafo::Anular()
{
	Vertice* aux;

	while (h != nullptr)
	{
		aux = h;
		h = h->sig;
		delete(aux);
	}
}

void Grafo::EliminarArista(Vertice* origen, Vertice* destino)
{
	int band = 0;
	Arista* actual;
	Arista* anterior;

	actual = origen->ady;
	anterior = actual;

	if (actual == nullptr)
	{
		cout << "El vertice origen no tiene aristas" << endl;
	}
	else if(actual->ady == destino)
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
}

void Grafo::EliminarVertice(Vertice* vert)
{
	Vertice* actual, * anterior;
	Arista* aux;

	actual = h;
	anterior = actual;
	while (actual != nullptr) {
		aux = actual->ady;
		while (aux != nullptr) {
			if(aux->ady == vert)
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
		while(actual != vert)
		{
			anterior = actual;
			actual = actual->sig;
		}
		anterior->sig = actual->sig;
		delete(actual);
	}
}

Vertice* Grafo::NodoActual() {
	return h;
}

void Grafo::iniciarGrafo(Vertice* inicio) {
	h = inicio;
}




