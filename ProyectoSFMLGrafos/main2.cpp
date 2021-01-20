#include <iostream>
#include "Grafo.h"
#include <string>
using namespace std;

int main()
{
	Grafo nuevoGrafo = Grafo();

	int filas;
	int columnas;

	cout << "Ingrese el número de filas ";
	cin >> filas;

	cout << "\nIngrese el número de columnas ";
	cin >> columnas;

	int conta = 1;

	//---------------- Inicializar las vertices ----------------

	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			nuevoGrafo.InsertaVertice(to_string(conta));
			conta += 1;
		}
		
	}

	//---------- Poner las aristas de las esquinas ---------------------------
	//---------- Esquina superior izquierda ----------------------------------
	nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(1)), nuevoGrafo.GetVertice(to_string(1 + 1)), 1);
	nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(1)), nuevoGrafo.GetVertice(to_string(1 + columnas)), 1);
	//---------- Esquina superior derecha ------------------------------------
	nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(columnas)) , nuevoGrafo.GetVertice(to_string(columnas - 1)), 1);
	nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(columnas)) , nuevoGrafo.GetVertice(to_string((columnas - 1) + columnas + 1)), 1);
	//---------- Esquina inferior derecha ------------------------------------
	nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string((columnas * filas))), nuevoGrafo.GetVertice(to_string(columnas * filas - 1)), 1);
	nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string((columnas * filas))), nuevoGrafo.GetVertice(to_string((columnas * filas) - columnas)), 1);
	//---------- Esquina inferior izquierda ----------------------------------
	nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string((columnas * filas) - (columnas - 1))), nuevoGrafo.GetVertice(to_string((columnas * filas) - (columnas - 1) + 1)), 1);
	nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string((columnas * filas) - (columnas - 1))), nuevoGrafo.GetVertice(to_string((columnas * filas) - (columnas - 1) - columnas)), 1);

	//---------- Poner las aristas de los lados ------------------------------
	//---------- Las aristas del lado superior -------------------------------
	for (int i = 2; i < columnas; i++) {
		nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(i)), nuevoGrafo.GetVertice(to_string(i - 1)), 1);
		nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(i)), nuevoGrafo.GetVertice(to_string(i + 1)), 1);
		nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(i)), nuevoGrafo.GetVertice(to_string(i + columnas)), 1);
	}
	//---------- Las aristas del lado izquierdo -------------------------------
	int contaLateralIzquierdo = 1 + columnas;
	for (int i = 0; i < filas - 2; i++) {
		nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(contaLateralIzquierdo)), nuevoGrafo.GetVertice(to_string(contaLateralIzquierdo - columnas)), 1);
		nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(contaLateralIzquierdo)), nuevoGrafo.GetVertice(to_string(contaLateralIzquierdo + 1)), 1);
		nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(contaLateralIzquierdo)), nuevoGrafo.GetVertice(to_string(contaLateralIzquierdo + columnas)), 1);
		contaLateralIzquierdo += columnas;
	}
	//---------- Las aristas del lado derecho -------------------------------
	int contaLateralDerecho = columnas * 2;
	for (int i = 0; i < filas - 2; i++) {
		nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(contaLateralDerecho)), nuevoGrafo.GetVertice(to_string(contaLateralDerecho - columnas)), 1);
		nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(contaLateralDerecho)), nuevoGrafo.GetVertice(to_string(contaLateralDerecho - 1)), 1);
		nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(contaLateralDerecho)), nuevoGrafo.GetVertice(to_string(contaLateralDerecho + columnas)), 1);
		contaLateralDerecho += columnas;
	}
	//---------- Las aristas del lado inferior -------------------------------
	int inicioUltimaColumna = (columnas * filas) - (columnas - 1);

	for (int i = inicioUltimaColumna + 1; i < columnas * columnas; i++) {
		nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(i)), nuevoGrafo.GetVertice(to_string(i - 1)), 1);
		nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(i)), nuevoGrafo.GetVertice(to_string(i + 1)), 1);
		nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(i)), nuevoGrafo.GetVertice(to_string(i - columnas)), 1);
	}
	//--------------------------------------------------------------------------

	//---------- Poner las aristas del centro --------------------------------
	int contaCentro = 2 + columnas;
	for (int i = 0; i < filas - 2; i++) {
		for (int j = 0; j < columnas - 2; j++) {
			nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(contaCentro)), nuevoGrafo.GetVertice(to_string(contaCentro - 1)), 1);
			nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(contaCentro)), nuevoGrafo.GetVertice(to_string(contaCentro + 1)), 1);
			nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(contaCentro)), nuevoGrafo.GetVertice(to_string(contaCentro - columnas)), 1);
			nuevoGrafo.InsertaArista(nuevoGrafo.GetVertice(to_string(contaCentro)), nuevoGrafo.GetVertice(to_string(contaCentro + columnas)), 1);
			cout << "Dentro del j: " << contaCentro << endl;
			contaCentro += 1;
		}
		contaCentro += 2;
		cout << "Dentro del i: " << contaCentro << endl;
	}



	cout << "El size es: " << nuevoGrafo.tamano() << endl;

	nuevoGrafo.ListaAdyacencia();
}