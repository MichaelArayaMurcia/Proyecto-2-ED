#include <iostream>
#define	infinito 9999999
#include "Grafo.h"
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "dlinkedlist.h"
#include <vector>
#include "Vertice.h"
#include "Arista.h"
#include "HeapPriorityQueue.h"
#include "LinkedPriorityQueue.h"
#include "Linkedqueue.h"
#include "Minheap.h"
#include "priorityQueue.h"
#include "Queue.h"
#include "Jugador.h"


using namespace std;

Grafo busquedaProfundidadModificadaAux(Grafo grafoResultante, Vertice* primerVertice) {
	//---- 2. Se obtiene la lista de vecinos no visitados
	Dlinkedlist<Vertice*>* vecinos = primerVertice->getlistaAdyacentes();
	Dlinkedlist<Vertice*>* vecinosNoVisitados = new Dlinkedlist<Vertice*>();

	for (vecinos->gotoStart(); !vecinos->atEnd(); vecinos->next()) {
		Vertice* vecino = vecinos->getElement();
		if (vecino->getVisitado() == false) {
			vecinosNoVisitados->append(vecino);
		}
	}

	//---- 3. Se deben recorrer los vecinos
	Dlinkedlist<int>* listaCantidadVecinos = new Dlinkedlist<int>();

	for (int i = 0; i < vecinosNoVisitados->getSize(); i++) {
		listaCantidadVecinos->append(i);
	}

	while (vecinosNoVisitados->getSize() > 0) {

		int numeroAleatorio = rand() % vecinosNoVisitados->getSize();
		vecinosNoVisitados->gotoPos(numeroAleatorio);
		Vertice* vecino = vecinosNoVisitados->getElement();

		//---- 3.a. Se marca el nodo como visitado
		primerVertice->setVisitado(true);

		//---- 3.b. Se agrega el arco correspondiente al grafo resultante

		if (vecino->getVisitado() == false) {
			grafoResultante.InsertaArista(primerVertice, vecino, 1);
			grafoResultante.InsertaArista(vecino, primerVertice, 1);
		}



		//---- 3.c. Se repite recursivamente desde el punto 2
		grafoResultante = busquedaProfundidadModificadaAux(grafoResultante, vecino);

		vecinosNoVisitados->remove();

	}

	return grafoResultante;
}

Grafo busquedaProfundidadModificada(Grafo oldGrafo, int filas, int columnas) {
	srand(time(0));
	int numeroVertices = oldGrafo.tamano();
	int numeroRandom = rand() % numeroVertices;

	//---- Inicializando el grafo

	Grafo grafoResultante = Grafo();
	int conta = 1;

	grafoResultante = oldGrafo;

	//---- 1. Se inicia en un nodo y se marca como visitado
	Vertice* primerVertice = oldGrafo.NodoActual();
	primerVertice->setVisitado(true);

	//---- 2. Se obtiene la lista de vecinos no visitados
	Dlinkedlist<Vertice*>* vecinos = primerVertice->getlistaAdyacentes();
	Dlinkedlist<Vertice*>* vecinosNoVisitados = new Dlinkedlist<Vertice*>();

	for (vecinos->gotoStart(); !vecinos->atEnd(); vecinos->next()) {
		Vertice* vecino = vecinos->getElement();
		if (vecino->getVisitado() == false) {
			vecinosNoVisitados->append(vecino);
		}
	}

	//---- 3. Se deben recorrer los vecinos
	Dlinkedlist<int>* listaCantidadVecinos = new Dlinkedlist<int>();

	for (int i = 0; i < vecinosNoVisitados->getSize(); i++) {
		listaCantidadVecinos->append(i);
	}

	while (vecinosNoVisitados->getSize() > 0) {

		int numeroAleatorio = rand() % vecinosNoVisitados->getSize();
		vecinosNoVisitados->gotoPos(numeroAleatorio);
		Vertice* vecino = vecinosNoVisitados->getElement();

		//---- 3.a. Se marca el nodo como visitado
		vecino->setVisitado(true);

		//---- 3.b. Se agrega el arco correspondiente al grafo resultante
		grafoResultante.InsertaArista(primerVertice, vecino, 1);
		grafoResultante.InsertaArista(vecino, primerVertice, 1);

		//---- 3.c. Se repite recursivamente desde el punto 2
		grafoResultante = busquedaProfundidadModificadaAux(grafoResultante, vecino);

		vecinosNoVisitados->remove();

	}




	return grafoResultante;

}

Grafo PrimModificado(Grafo oldGrafo, int filas, int columnas) {
	srand(time(0));
	
	Grafo grafoResultante = Grafo();
	
	int conta = 1;
	
	for (int i = 0; i < filas; i++) {
	
		for (int j = 0; j < columnas; j++) {
			grafoResultante.InsertaVertice(to_string(conta));
			conta += 1;
		}

	}

	//---------------------------- Insertando los arcos -------------------------
	//---------- Esquina superior izquierda ----------------------------------
	Vertice* vertice1 = oldGrafo.GetVertice(to_string(1));
	Vertice* vertice2 = oldGrafo.GetVertice(to_string(1 + 1));
	Vertice* vertice3 = oldGrafo.GetVertice(to_string(1 + columnas));

	oldGrafo.InsertaArista(vertice1, vertice2, 1);
	oldGrafo.InsertaArista(vertice1, vertice3, 1);
	oldGrafo.InsertaArista(vertice2, vertice1, 1);
	oldGrafo.InsertaArista(vertice3, vertice1, 1);

	//---------- Esquina superior derecha ------------------------------------
	Vertice* vertice4 = oldGrafo.GetVertice(to_string(columnas));
	Vertice* vertice5 = oldGrafo.GetVertice(to_string(columnas - 1));
	Vertice* vertice6 = oldGrafo.GetVertice(to_string((columnas - 1) + columnas + 1));

	oldGrafo.InsertaArista(vertice4, vertice5, 1);
	oldGrafo.InsertaArista(vertice4, vertice6, 1);
	oldGrafo.InsertaArista(vertice5, vertice4, 1);
	oldGrafo.InsertaArista(vertice6, vertice4, 1);


	//---------- Esquina inferior derecha ------------------------------------
	Vertice* vertice7 = oldGrafo.GetVertice(to_string((columnas * filas)));
	Vertice* vertice8 = oldGrafo.GetVertice(to_string(columnas * filas - 1));
	Vertice* vertice9 = oldGrafo.GetVertice(to_string((columnas * filas) - columnas));

	oldGrafo.InsertaArista(vertice7, vertice8, 1);
	oldGrafo.InsertaArista(vertice7, vertice9, 1);
	oldGrafo.InsertaArista(vertice8, vertice7, 1);
	oldGrafo.InsertaArista(vertice9, vertice7, 1);

	//---------- Esquina inferior izquierda ----------------------------------
	Vertice* vertice10 = oldGrafo.GetVertice(to_string((columnas * filas) - (columnas - 1)));
	Vertice* vertice11 = oldGrafo.GetVertice(to_string((columnas * filas) - (columnas - 1) + 1));
	Vertice* vertice12 = oldGrafo.GetVertice(to_string((columnas * filas) - (columnas - 1) - columnas));

	oldGrafo.InsertaArista(vertice10, vertice11, 1);
	oldGrafo.InsertaArista(vertice10, vertice12, 1);
	oldGrafo.InsertaArista(vertice11, vertice10, 1);
	oldGrafo.InsertaArista(vertice12, vertice10, 1);
	//---------------------------------------------------------------------------
	//---------- Poner las aristas de los lados ------------------------------
	//---------- Las aristas del lado superior -------------------------------
	for (int i = 2; i < columnas; i++) {
		Vertice* vertice13 = oldGrafo.GetVertice(to_string(i));
		Vertice* vertice14 = oldGrafo.GetVertice(to_string(i - 1));
		Vertice* vertice15 = oldGrafo.GetVertice(to_string(i + 1));
		Vertice* vertice16 = oldGrafo.GetVertice(to_string(i + columnas));

		oldGrafo.InsertaArista(vertice13, vertice14, 1);
		oldGrafo.InsertaArista(vertice13, vertice15, 1);
		oldGrafo.InsertaArista(vertice13, vertice16, 1);
		oldGrafo.InsertaArista(vertice14, vertice13, 1);
		oldGrafo.InsertaArista(vertice15, vertice13, 1);
		oldGrafo.InsertaArista(vertice16, vertice13, 1);

	}
	//---------- Las aristas del lado izquierdo -------------------------------
	int contaLateralIzquierdo = 1 + columnas;
	for (int i = 0; i < filas - 2; i++) {
		Vertice* vertice17 = oldGrafo.GetVertice(to_string(contaLateralIzquierdo));
		Vertice* vertice18 = oldGrafo.GetVertice(to_string(contaLateralIzquierdo - columnas));
		Vertice* vertice19 = oldGrafo.GetVertice(to_string(contaLateralIzquierdo + 1));
		Vertice* vertice20 = oldGrafo.GetVertice(to_string(contaLateralIzquierdo + columnas));

		oldGrafo.InsertaArista(vertice17, vertice18, 1);
		oldGrafo.InsertaArista(vertice17, vertice19, 1);
		oldGrafo.InsertaArista(vertice17, vertice20, 1);
		oldGrafo.InsertaArista(vertice18, vertice17, 1);
		oldGrafo.InsertaArista(vertice19, vertice17, 1);
		oldGrafo.InsertaArista(vertice20, vertice17, 1);

		contaLateralIzquierdo += columnas;
	}
	//---------- Las aristas del lado derecho -------------------------------
	int contaLateralDerecho = columnas * 2;
	for (int i = 0; i < filas - 2; i++) {
		Vertice* vertice21 = oldGrafo.GetVertice(to_string(contaLateralDerecho));
		Vertice* vertice22 = oldGrafo.GetVertice(to_string(contaLateralDerecho - columnas));
		Vertice* vertice23 = oldGrafo.GetVertice(to_string(contaLateralDerecho - 1));
		Vertice* vertice24 = oldGrafo.GetVertice(to_string(contaLateralDerecho + columnas));

		oldGrafo.InsertaArista(vertice21, vertice22, 1);
		oldGrafo.InsertaArista(vertice21, vertice23, 1);
		oldGrafo.InsertaArista(vertice21, vertice24, 1);
		oldGrafo.InsertaArista(vertice22, vertice21, 1);
		oldGrafo.InsertaArista(vertice23, vertice21, 1);
		oldGrafo.InsertaArista(vertice24, vertice21, 1);

		contaLateralDerecho += columnas;
	}
	//---------- Las aristas del lado inferior -------------------------------
	int inicioUltimaColumna = (columnas * filas) - (columnas - 1);

	for (int i = inicioUltimaColumna + 1; i < columnas * columnas; i++) {
		Vertice* vertice25 = oldGrafo.GetVertice(to_string(i));
		Vertice* vertice26 = oldGrafo.GetVertice(to_string(i - 1));
		Vertice* vertice27 = oldGrafo.GetVertice(to_string(i + 1));
		Vertice* vertice28 = oldGrafo.GetVertice(to_string(i - columnas));

		oldGrafo.InsertaArista(vertice25, vertice26, 1);
		oldGrafo.InsertaArista(vertice25, vertice27, 1);
		oldGrafo.InsertaArista(vertice25, vertice28, 1);
		oldGrafo.InsertaArista(vertice26, vertice25, 1);	
		oldGrafo.InsertaArista(vertice27, vertice25, 1);
		oldGrafo.InsertaArista(vertice28, vertice25, 1);

	}
	//--------------------------------------------------------------------------

	//---------- Poner las aristas del centro --------------------------------
	int contaCentro = 2 + columnas;
	for (int i = 0; i < filas - 2; i++) {
		for (int j = 0; j < columnas - 2; j++) {
			Vertice* vertice29 = oldGrafo.GetVertice(to_string(contaCentro));
			Vertice* vertice30 = oldGrafo.GetVertice(to_string(contaCentro));
			Vertice* vertice31 = oldGrafo.GetVertice(to_string(contaCentro + 1));
			Vertice* vertice32 = oldGrafo.GetVertice(to_string(contaCentro - columnas));
			Vertice* vertice33 = oldGrafo.GetVertice(to_string(contaCentro + columnas));

			oldGrafo.InsertaArista(vertice29, vertice30, 1);
			oldGrafo.InsertaArista(vertice29, vertice31, 1);
			oldGrafo.InsertaArista(vertice29, vertice32, 1);
			oldGrafo.InsertaArista(vertice29, vertice33, 1);	
			oldGrafo.InsertaArista(vertice30, vertice29, 1);
			oldGrafo.InsertaArista(vertice31, vertice29, 1);
			oldGrafo.InsertaArista(vertice32, vertice29, 1);
			oldGrafo.InsertaArista(vertice33, vertice29, 1);

			contaCentro += 1;
		}
		contaCentro += 2;
	}

	//------------------------------------------------------------------------

	
	//int nodoInicial = (rand() % (filas * columnas)) + 1;

	Vertice* inicio = oldGrafo.GetVertice(to_string(1));
	
	oldGrafo.iniciarGrafo(inicio);

	Vertice* inicioResultante = grafoResultante.GetVertice(to_string(1));
	
	grafoResultante.iniciarGrafo(inicioResultante);
	grafoResultante.NodoActual()->setVisitado(true);
	oldGrafo.NodoActual()->setVisitado(true);
	
	Dlinkedlist<Arista*>* listaArcos = new Dlinkedlist<Arista*>();
	listaArcos = oldGrafo.NodoActual()->getlistaArcos();
	
	while (!listaArcos->isEmpty()) {
		
		int siguienteArco = rand() % listaArcos->getSize();
		listaArcos->gotoPos(siguienteArco);
		Arista* temp = listaArcos->remove();
	
		if (temp->getVerticeady()->getVisitado() != true) {
			
			Vertice* vertice1 = grafoResultante.GetVertice(temp->getOrigen()->getNombre());
			Vertice* vertice2 = grafoResultante.GetVertice(temp->getVerticeady()->getNombre());

			grafoResultante.InsertaArista(vertice1 , vertice2, 1);
			grafoResultante.InsertaArista(vertice2, vertice1, 1);
			vertice2->setVisitado(true);
			Vertice* tempviejo = oldGrafo.GetVertice(vertice2->getNombre());
			tempviejo->setVisitado(true);
		
			temp->getVerticeady()->getlistaArcos()->gotoStart();
			
			for (int i = 0; i < temp->getVerticeady()->getlistaArcos()->getSize(); i++) {

				listaArcos->append(temp->getVerticeady()->getlistaArcos()->getElement());
				temp->getVerticeady()->getlistaArcos()->next();

			}

		}

	}
	return grafoResultante;
}

void algoritmoFloyd(int** &matrizConecciones, int** &matrizRutas, int cantidadNodos) {
	for (int i = 0; i < cantidadNodos; i++) {
		for (int f = 0; f < cantidadNodos; f++) {
			for (int c = 0; c < cantidadNodos; c++) {
				if (f != i && c != i && f != c) {
					int temp = matrizConecciones[f][i] + matrizConecciones[i][c];
					if (temp < matrizConecciones[f][c]) {
						matrizConecciones[f][c] = temp;
						matrizRutas[f][c] = matrizRutas[i][c];
					}
				}
			}
		}
	}
}
void crearMatriz(int** &matriz, int cantidadNodos) {
	matriz = new int* [cantidadNodos];
	for (int i = 0; i < cantidadNodos; i++) {
		matriz[i] = new int[cantidadNodos];
	}
}

void iniciarMatrizConecciones(int** &matriz, Grafo laberinto,int cantidadNodos) {
	for (int i = 0; i < cantidadNodos; i++) {
		for (int j = 0; j < cantidadNodos; j++) {
			matriz[i][j] = infinito;
		}
	}

	for (int i = 0; i < cantidadNodos; i++) {
		Dlinkedlist<Arista*>* listaAristas = laberinto.GetVertice(to_string(i + 1))->getlistaArcos();
		for (listaAristas->gotoStart(); !listaAristas->atEnd(); listaAristas->next()) {
			Arista* aristaTemp = listaAristas->getElement();
			matriz[i][stoi(aristaTemp->getVerticeady()->getNombre())-1] = aristaTemp->getPeso();
		}
	}
}

void iniciarMatrizRutas(int** &matriz, int cantidadNodos) {
	for (int i = 0; i < cantidadNodos; i++) {
		for (int j = 0; j < cantidadNodos; j++) {
			matriz[i][j] = i;
		}
	}
}

Grafo inicializarGrafo(Grafo nuevoGrafo, int filas, int columnas) {
	int conta = 1;
	
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			nuevoGrafo.InsertaVertice(to_string(conta));
			conta += 1;
		}

	}
	
	//---------- Poner las aristas de las esquinas ---------------------------
	//---------- Esquina superior izquierda ----------------------------------
	Vertice* vertice1 = nuevoGrafo.GetVertice(to_string(1));
	Vertice* vertice2 = nuevoGrafo.GetVertice(to_string(1 + 1));
	Vertice* vertice3 = nuevoGrafo.GetVertice(to_string(1 + columnas));

	vertice1->getlistaAdyacentes()->append(vertice2);
	vertice1->getlistaAdyacentes()->append(vertice3);
	vertice2->getlistaAdyacentes()->append(vertice1);
	vertice3->getlistaAdyacentes()->append(vertice1);

	//---------- Esquina superior derecha ------------------------------------
	Vertice* vertice4 = nuevoGrafo.GetVertice(to_string(columnas));
	Vertice* vertice5 = nuevoGrafo.GetVertice(to_string(columnas - 1));
	Vertice* vertice6 = nuevoGrafo.GetVertice(to_string((columnas - 1) + columnas + 1));

	vertice4->getlistaAdyacentes()->append(vertice5);
	vertice4->getlistaAdyacentes()->append(vertice6);
	vertice5->getlistaAdyacentes()->append(vertice4);
	vertice6->getlistaAdyacentes()->append(vertice4);


	//---------- Esquina inferior derecha ------------------------------------
	Vertice* vertice7 = nuevoGrafo.GetVertice(to_string((columnas * filas)));
	Vertice* vertice8 = nuevoGrafo.GetVertice(to_string(columnas * filas - 1));
	Vertice* vertice9 = nuevoGrafo.GetVertice(to_string((columnas * filas) - columnas));

	vertice7->getlistaAdyacentes()->append(vertice8);
	vertice7->getlistaAdyacentes()->append(vertice9);
	vertice8->getlistaAdyacentes()->append(vertice7);
	vertice9->getlistaAdyacentes()->append(vertice7);
	//---------- Esquina inferior izquierda ----------------------------------
	Vertice* vertice10 = nuevoGrafo.GetVertice(to_string((columnas * filas) - (columnas - 1)));
	Vertice* vertice11 = nuevoGrafo.GetVertice(to_string((columnas * filas) - (columnas - 1) + 1));
	Vertice* vertice12 = nuevoGrafo.GetVertice(to_string((columnas * filas) - (columnas - 1) - columnas));

	vertice10->getlistaAdyacentes()->append(vertice11);
	vertice10->getlistaAdyacentes()->append(vertice12);
	vertice11->getlistaAdyacentes()->append(vertice10);
	vertice12->getlistaAdyacentes()->append(vertice10);

	//---------- Poner las aristas de los lados ------------------------------
	//---------- Las aristas del lado superior -------------------------------
	for (int i = 2; i < columnas; i++) {
		Vertice* vertice13 = nuevoGrafo.GetVertice(to_string(i));
		Vertice* vertice14 = nuevoGrafo.GetVertice(to_string(i - 1));
		Vertice* vertice15 = nuevoGrafo.GetVertice(to_string(i + 1));
		Vertice* vertice16 = nuevoGrafo.GetVertice(to_string(i + columnas));

		vertice13->getlistaAdyacentes()->append(vertice14);
		vertice13->getlistaAdyacentes()->append(vertice15);
		vertice13->getlistaAdyacentes()->append(vertice16);
		vertice14->getlistaAdyacentes()->append(vertice13);
		vertice15->getlistaAdyacentes()->append(vertice13);
		vertice16->getlistaAdyacentes()->append(vertice13);
	}
	//---------- Las aristas del lado izquierdo -------------------------------
	int contaLateralIzquierdo = 1 + columnas;
	for (int i = 0; i < filas - 2; i++) {
		Vertice* vertice17 = nuevoGrafo.GetVertice(to_string(contaLateralIzquierdo));
		Vertice* vertice18 = nuevoGrafo.GetVertice(to_string(contaLateralIzquierdo - columnas));
		Vertice* vertice19 = nuevoGrafo.GetVertice(to_string(contaLateralIzquierdo + 1));
		Vertice* vertice20 = nuevoGrafo.GetVertice(to_string(contaLateralIzquierdo + columnas));

		vertice17->getlistaAdyacentes()->append(vertice18);
		vertice17->getlistaAdyacentes()->append(vertice19);
		vertice17->getlistaAdyacentes()->append(vertice20);
		vertice18->getlistaAdyacentes()->append(vertice17);
		vertice19->getlistaAdyacentes()->append(vertice17);
		vertice20->getlistaAdyacentes()->append(vertice17);

		contaLateralIzquierdo += columnas;
	}
	//---------- Las aristas del lado derecho -------------------------------
	int contaLateralDerecho = columnas * 2;
	for (int i = 0; i < filas - 2; i++) {
		Vertice* vertice21 = nuevoGrafo.GetVertice(to_string(contaLateralDerecho));
		Vertice* vertice22 = nuevoGrafo.GetVertice(to_string(contaLateralDerecho - columnas));
		Vertice* vertice23 = nuevoGrafo.GetVertice(to_string(contaLateralDerecho - 1));
		Vertice* vertice24 = nuevoGrafo.GetVertice(to_string(contaLateralDerecho + columnas));

		vertice21->getlistaAdyacentes()->append(vertice22);
		vertice21->getlistaAdyacentes()->append(vertice23);
		vertice21->getlistaAdyacentes()->append(vertice24);
		vertice22->getlistaAdyacentes()->append(vertice21);
		vertice23->getlistaAdyacentes()->append(vertice21);
		vertice24->getlistaAdyacentes()->append(vertice21);
		contaLateralDerecho += columnas;
	}
	//---------- Las aristas del lado inferior -------------------------------
	int inicioUltimaColumna = (columnas * filas) - (columnas - 1);

	for (int i = inicioUltimaColumna + 1; i < columnas * columnas; i++) {
		Vertice* vertice25 = nuevoGrafo.GetVertice(to_string(i));
		Vertice* vertice26 = nuevoGrafo.GetVertice(to_string(i - 1));
		Vertice* vertice27 = nuevoGrafo.GetVertice(to_string(i + 1));
		Vertice* vertice28 = nuevoGrafo.GetVertice(to_string(i - columnas));

		vertice25->getlistaAdyacentes()->append(vertice26);
		vertice25->getlistaAdyacentes()->append(vertice27);
		vertice25->getlistaAdyacentes()->append(vertice28);
		vertice26->getlistaAdyacentes()->append(vertice25);
		vertice27->getlistaAdyacentes()->append(vertice25);
		vertice28->getlistaAdyacentes()->append(vertice25);

	}
	//--------------------------------------------------------------------------

	//---------- Poner las aristas del centro --------------------------------
	int contaCentro = 2 + columnas;
	for (int i = 0; i < filas - 2; i++) {
		for (int j = 0; j < columnas - 2; j++) {
			Vertice* vertice29 = nuevoGrafo.GetVertice(to_string(contaCentro));
			Vertice* vertice30 = nuevoGrafo.GetVertice(to_string(contaCentro));
			Vertice* vertice31 = nuevoGrafo.GetVertice(to_string(contaCentro + 1));
			Vertice* vertice32 = nuevoGrafo.GetVertice(to_string(contaCentro - columnas));
			Vertice* vertice33 = nuevoGrafo.GetVertice(to_string(contaCentro + columnas));

			vertice29->getlistaAdyacentes()->append(vertice30);
			vertice29->getlistaAdyacentes()->append(vertice31);
			vertice29->getlistaAdyacentes()->append(vertice32);
			vertice29->getlistaAdyacentes()->append(vertice33);
			vertice30->getlistaAdyacentes()->append(vertice29);
			vertice31->getlistaAdyacentes()->append(vertice29);
			vertice32->getlistaAdyacentes()->append(vertice29);
			vertice33->getlistaAdyacentes()->append(vertice29);
			contaCentro += 1;
		}
		contaCentro += 2;
	}

	return nuevoGrafo;

}


int main()
{

	cout << "Escriba 1 si quiere usar el algoritmo de profundidad modificado" << endl;
	cout << "Escriba 2 si quiere usar el algoritmo de Prim modificado" << endl;


	string opcion = "0";

	cin >> opcion;

	//---------------- Inicializar las vertices ----------------

	//cout << "El size es: " << nuevoGrafo.tamano() << endl;

	//nuevoGrafo.ListaAdyacencia();
	//busquedaProfundidadModificada(nuevoGrafo, filas, columnas);
	//nuevoGrafo.ListaAdyacencia();

	
	//---------------------------------------------------
	//---------------------------------------------------
	//---------------------------------------------------

	// Create the main window

	bool gameOver = false;

	// Start the game loop


	int filas;
	int columnas;

	filas = 10;
	columnas = 10;

	int conta = 1;

	int puntuacion = 0;


	while (!gameOver) {
		Grafo nuevoGrafo = Grafo();
		Jugador jugador = Jugador();

		nuevoGrafo = inicializarGrafo(nuevoGrafo, filas, columnas);

		if (opcion == "1") {
			nuevoGrafo = busquedaProfundidadModificada(nuevoGrafo, filas, columnas);
		}
		else {
			nuevoGrafo = PrimModificado(nuevoGrafo, filas, columnas);
		}

		sf::RenderWindow window(sf::VideoMode(700, 700), "SFML window");


		float tamañoGeneral = 20;
		float sizeX2 = (window.getSize().x) / (filas * 1.50);
		float sizeY2 = (window.getSize().y) / (columnas * 1.30);

		int numeroNodoActual = 1;

		bool marcados = false;

		Dlinkedlist<float> listaPosicionesX;
		Dlinkedlist<float> listaPosicionesY;

		float numeroDistancia = tamañoGeneral * 2;

		bool cambiar = true;



		bool creado = false;

		nuevoGrafo = inicializarGrafo(nuevoGrafo, filas, columnas);


		while (window.isOpen())
		{
			// Process events
			sf::Event event;
			while (window.pollEvent(event))
			{
				// Close window: exit
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == sf::Event::KeyPressed)
				{

					if (event.key.code == sf::Keyboard::Left) {

						Vertice* vertice = nuevoGrafo.GetVertice(to_string(numeroNodoActual));

						Dlinkedlist<Arista*>* listaAristas = nuevoGrafo.GetVertice(to_string(numeroNodoActual))->getlistaArcos();


						for (listaAristas->gotoStart(); !listaAristas->atEnd(); listaAristas->next()) {
							Arista* arco = listaAristas->getElement();

							Vertice* verticeVecino = arco->getVerticeady();

							float posX2 = verticeVecino->getposX();
							float posY2 = verticeVecino->getposY();


							if (posX2 == jugador.getposX() - numeroDistancia && posY2 == jugador.getposY()) {

								numeroNodoActual -= 1;
								jugador.setposX(jugador.getposX() - numeroDistancia);
							}
						}

						//------------------ Verificar final -----------------------
						if (numeroNodoActual == filas * columnas && cambiar == true) {

							window.close();

						}

					}

					else if (event.key.code == sf::Keyboard::Right) {

						Vertice* vertice = nuevoGrafo.GetVertice(to_string(numeroNodoActual));

						Dlinkedlist<Arista*>* listaAristas = nuevoGrafo.GetVertice(to_string(numeroNodoActual))->getlistaArcos();


						for (listaAristas->gotoStart(); !listaAristas->atEnd(); listaAristas->next()) {
							Arista* arco = listaAristas->getElement();

							Vertice* verticeVecino = arco->getVerticeady();

							float posX2 = verticeVecino->getposX();
							float posY2 = verticeVecino->getposY();

							if (posX2 == jugador.getposX() + numeroDistancia && posY2 == jugador.getposY()) {


								numeroNodoActual += 1;
								jugador.setposX(jugador.getposX() + numeroDistancia);
							}
						}

						//------------------ Verificar final -----------------------
						if (numeroNodoActual == filas * columnas && cambiar == true) {

							window.close();

						}


					}

					else if (event.key.code == sf::Keyboard::Up)
					{
						Vertice* vertice = nuevoGrafo.GetVertice(to_string(numeroNodoActual));

						Dlinkedlist<Arista*>* listaAristas = nuevoGrafo.GetVertice(to_string(numeroNodoActual))->getlistaArcos();


						for (listaAristas->gotoStart(); !listaAristas->atEnd(); listaAristas->next()) {
							Arista* arco = listaAristas->getElement();

							Vertice* verticeVecino = arco->getVerticeady();

							float posX2 = verticeVecino->getposX();
							float posY2 = verticeVecino->getposY();

							if (posX2 == jugador.getposX() && posY2 == jugador.getposY() - numeroDistancia) {


								numeroNodoActual -= columnas;
								jugador.setposY(jugador.getposY() - numeroDistancia);
							}
						}

						//------------------ Verificar final -----------------------
						if (numeroNodoActual == filas * columnas && cambiar == true) {

							window.close();

						}

					}

					else if (event.key.code == sf::Keyboard::Down)
					{

						Vertice* vertice = nuevoGrafo.GetVertice(to_string(numeroNodoActual));

						Dlinkedlist<Arista*>* listaAristas = nuevoGrafo.GetVertice(to_string(numeroNodoActual))->getlistaArcos();


						for (listaAristas->gotoStart(); !listaAristas->atEnd(); listaAristas->next()) {
							Arista* arco = listaAristas->getElement();

							Vertice* verticeVecino = arco->getVerticeady();

							float posX2 = verticeVecino->getposX();
							float posY2 = verticeVecino->getposY();

							if (posX2 == jugador.getposX() && posY2 == jugador.getposY() + numeroDistancia) {


								numeroNodoActual += columnas;
								jugador.setposY(jugador.getposY() + numeroDistancia);
							}
						}

						//------------------ Verificar final -----------------------
						if (numeroNodoActual == filas * columnas && cambiar == true) {

							window.close();

						}

					}

				}
			}

			//--------- variables para los nodos
			float posY = 0.f;
			float posX = 0.f;
			float conta = 0;

			//--------- variables para las aristas
			float posAX = 0.f;
			float posAY = 0.f;
			float conta2 = 0;

			float tamañoGeneral = 20;



			for (int i = 1; i < filas * columnas + 1; i++) {
				posX = conta * (tamañoGeneral * 2); // tamañoGeneral * 2

				//----------------- Dibujar los vertices -----------
				sf::RectangleShape rectangleNodo(sf::Vector2f(120.f, 50.f));
				float sizeX1 = tamañoGeneral;
				float sizeY1 = tamañoGeneral;

				rectangleNodo.setSize(sf::Vector2f(sizeX1, sizeY1)); // tamañoGeneral
				rectangleNodo.setPosition(posX, posY);
				listaPosicionesX.append(posX);
				listaPosicionesY.append(posY);
				//rectangleNodo.setOutlineThickness(1);
				rectangleNodo.setOutlineColor(sf::Color(0, 0, 255));


				Vertice* primerNodo = nuevoGrafo.GetVertice(to_string(i));
				if (i != 0 && marcados == false && cambiar == true) {
					primerNodo->setposX(posX);
					primerNodo->setposY(posY);

					if (i == filas * columnas) {

						marcados = true;
					}

				}


				//--------- Nodo de entrada --------------
				if (primerNodo->getNombre() == "1") {
					rectangleNodo.setFillColor(sf::Color(255, 0, 0));
				}
				//--------- Nodo de salida ---------------
				else if (primerNodo->getNombre() == to_string(filas * columnas)) {
					rectangleNodo.setFillColor(sf::Color(0, 255, 0));
				}
				//--------- Nodos de en medio ------------
				else {
					rectangleNodo.setFillColor(sf::Color(0, 0, 255));
				}

				//---------------- Dibujar los arcos --------------
				Dlinkedlist<Arista*>* listaArcosVecinos = nuevoGrafo.GetVertice(to_string(i))->getlistaArcos();

				for (int j = 0; j < listaArcosVecinos->getSize(); j++) {
					sf::RectangleShape rectangleArcoVecino(sf::Vector2f(120.f, 50.f));

					rectangleArcoVecino.setSize(sf::Vector2f(sizeX1, sizeY1)); // tamañoGeneral

					listaArcosVecinos->gotoPos(j);
					Arista* aristaVecina = listaArcosVecinos->getElement();
					Vertice* vecino = aristaVecina->getVerticeady();


					if (aristaVecina->getOrigen()->getNombre() == primerNodo->getNombre() && aristaVecina->getVerticeady()->getNombre() == vecino->getNombre()) {

						rectangleArcoVecino.setFillColor(sf::Color(0, 0, 255));

						//---------- Dibujarlo arriba ----
						if (stoi(vecino->getNombre()) == i - columnas) {
							rectangleArcoVecino.setPosition(posX, posY - sizeY1); //tamañoGeneral
							window.draw(rectangleArcoVecino);
						}

						//---------- Dibujarlo abajo ----
						else if (stoi(vecino->getNombre()) == i + columnas) {
							rectangleArcoVecino.setPosition(posX, posY + sizeY1); //tamañoGeneral
							window.draw(rectangleArcoVecino);
						}

						//---------- Dibujarlo izquierda ----
						else if (stoi(vecino->getNombre()) == i - 1) {
							rectangleArcoVecino.setPosition(posX - sizeX1, posY); //tamañoGeneral
							window.draw(rectangleArcoVecino);
						}

						//---------- Dibujarlo derecha ----
						else if (stoi(vecino->getNombre()) == i + 1) {
							rectangleArcoVecino.setPosition(posX + sizeX1, posY); //tamañoGeneral
							window.draw(rectangleArcoVecino);
						}

					}
					else {

						rectangleArcoVecino.setFillColor(sf::Color(0, 0, 255));
						window.draw(rectangleArcoVecino);
					}

				}

				window.draw(rectangleNodo);

				conta += 1;

				if (i % columnas == 0 && i != 0) {
					posY += tamañoGeneral * 2; //tamañoGeneral * 2
					conta = 0;
				}
			}





			//------------------------ Dibujar al jugador y eso --------------------------
			sf::RectangleShape rectangleJugador(sf::Vector2f(120.f, 50.f));

			rectangleJugador.setSize(sf::Vector2f(tamañoGeneral, tamañoGeneral));
			rectangleJugador.setFillColor(sf::Color(255, 0, 255));
			rectangleJugador.setPosition(jugador.getposX(), jugador.getposY());
			window.draw(rectangleJugador);

			// Clear screen
			//window.clear();
			// Draw the sprite
			//window.draw(sprite);
			// Draw the string
			//window.draw(text);
			// Update the window
			window.display();
		}
	
		filas += 1;
		columnas += 1;

	}
}