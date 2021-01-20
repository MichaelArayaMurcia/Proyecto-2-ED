#include <iostream>
#include "Grafo.h"
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
	Grafo nuevoGrafo = Grafo();

	int filas;
	int columnas;

	cout << "Ingrese el numero de filas ";
	cin >> filas;

	cout << "\nIngrese el numero de columnas ";
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


	//---------------------------------------------------
	//---------------------------------------------------
	//---------------------------------------------------

	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//--------- variables para los nodos
		float posY = 0.f;
		float posX = 0.f;
		float conta = 0;

		//--------- variables para las aristas
		float posAX = 0.f;
		float posAY = 0.f;
		float conta2 = 0;

		for (int i = 1; i < filas * columnas + 1; i++) {
			posX = conta * 60;
			
			//----------------- Dibujar los vertices -----------
			sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
			rectangle.setSize(sf::Vector2f(30.f, 30.f));
			rectangle.setPosition(posX, posY);
			rectangle.setOutlineThickness(1);
			rectangle.setOutlineColor(sf::Color(0,0,255));

			if (nuevoGrafo.GetVertice(to_string(i)) != NULL) {
				rectangle.setFillColor(sf::Color(100, 250, 50));
			}
			else {
				rectangle.setFillColor(sf::Color(0, 0, 0));
			}

			
			window.draw(rectangle);

			conta += 1;

			if (i % columnas == 0 && i != 0) {
				posY += 60;
				conta = 0;
			}
		}
		

		// Clear screen
		//window.clear();
		// Draw the sprite
		//window.draw(sprite);
		// Draw the string
		//window.draw(text);
		// Update the window
		window.display();
	}
}
