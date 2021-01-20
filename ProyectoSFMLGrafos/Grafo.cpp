#include "Grafo.h"

void Grafo::Inicializa() 
{
	h = NULL;
}

bool Grafo::Vacio()
{
	if(h == NULL){
		return true;
	}
	else {
		return false;
	}
}

int Grafo::tamano() 
{
	int conta = 0;
	Vertice* aux;
	aux = h;

	while(aux != NULL){
		conta += 1;
		aux = aux->sig;
	}
	return conta;
}

Vertice* Grafo::GetVertice(string nombre)
{
	
	Vertice* aux;
	aux = h;
	while (aux != NULL) {
		if (aux->nombre == nombre) {
			return aux;
		}
		aux = aux->sig;

	}
	return NULL;
}

void Grafo::InsertaVertice(string nombre)
{
	Vertice* nuevo = new Vertice;
	nuevo->nombre = nombre;
	nuevo->sig = NULL;
	nuevo->ady = NULL;

	if (Vacio()) {
		h = nuevo;
	}
	else {
		Vertice* aux;
		aux = h;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

void Grafo::InsertaArista(Vertice *origen, Vertice *destino, int peso) 
{
	Arista* nueva = new Arista;
	nueva->peso = peso;
	nueva->sig = NULL;
	nueva->ady = NULL;

	Arista* aux;

	aux = origen->ady;

	if (aux == NULL) 
	{
		origen->ady = nueva;
		nueva->ady = destino;
	}
	else
	{
		while (aux->sig != NULL)
		{
			aux = aux->sig;
		}
		aux->sig = nueva;
		nueva->ady = destino;
	}


}

void Grafo::ListaAdyacencia() 
{
	Vertice* VertAux;
	Arista* ArisAux;

	VertAux = h;
	while (VertAux != NULL) {
		cout << VertAux->nombre << "->";
		
		ArisAux = VertAux->ady;
		while (ArisAux != NULL) {
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

	while (h != NULL) 
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

	if (actual == NULL) 
	{
		cout << "El vertice origen no tiene aristas" << endl;
	}
	else if(actual->ady == destino)
	{
		origen->ady = actual->sig;
		delete(actual);
	}
	else {
		while (actual != NULL)
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
	while (actual != NULL) {
		aux = actual->ady;
		while (aux != NULL) {
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

void Grafo::RecorridoAnchura(Vertice* origen)
{
	int band;
	int band2;
	Vertice* actual;
	queue<Vertice*> cola;
	list<Vertice*> lista;
	list<Vertice*>::iterator i;

	cola.push(origen);

	while (!cola.empty()) {
		band = 0;
		actual = cola.front();
		cola.pop();

		for(i = lista.begin(); i != lista.end(); i++)
		{
			if (*i == actual)
			{
				band = 1;
			}

		}
		if(band == 0)
		{
			cout << actual->nombre << ",";
			lista.push_back(actual);

			Arista* aux;
			aux = actual->ady;
			while (aux != NULL)
			{
				band2 = 0;
				for (i = lista.begin(); i != lista.end(); i++)
				{
					if (aux->ady == *i)
					{
						band2 = 1;
					}
				}
				if (band2 == 0)
				{
					cola.push(aux->ady);
				}
				aux = aux->sig;
			}
		}
	}
}

void Grafo::RecorridoProfundidad(Vertice* origen)
{
	int band;
	int band2;
	Vertice* actual;
	stack<Vertice*> pila;
	list<Vertice*> lista;
	list<Vertice*>::iterator i;

	pila.push(origen);

	while (!pila.empty())
	{
		actual = pila.top();
		pila.pop();

		for (i = lista.begin(); i != lista.end(); i++) {
			if (*i == actual)
			{
				band = 1;
			}
		}

		if (band == 0)
		{
			cout << actual->nombre << ",";
			lista.push_back(actual);

			Arista* aux;
			aux = actual->ady;

			while (aux != NULL)
			{

				band2 = 0;
				for (i = lista.begin(); i != lista.end(); i++)
				{
					if (*i == aux->ady)
					{
						band2 = 1;
					}
				}

				if (band2 == 0)
				{
					pila.push(aux->ady);
				}
	
				aux = aux->sig;
			}
		}
	}
}

void Grafo::RecorridoProfundidadModificado()
{
	int band;
	int band2;
	Vertice* actual;
	stack<Vertice*> pila;
	list<Vertice*> lista;
	list<Vertice*>::iterator i;

	//1. Se inicia en un nodo y se marca como visitado.
	actual = h;
	actual->visitado = true;
	//2. Se obtiene la lista de vecinos no visitados.
	
	//3. Por cada vecino no visitado, se repite lo siguiente.El orden en que se recorren los vecinos no visitados
	//debe ser aleatorio.
		//a.Se marca el nodo como visitado
		//b.Se agrega el arco correspondiente al grafo resultante
		//c.Se repite recursivamente desde el punto 2.

}

