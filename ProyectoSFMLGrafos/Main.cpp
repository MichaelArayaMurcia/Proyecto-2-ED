#include <SFML/Graphics.hpp>
#include "Grafo.h"
#include <iostream>
#include "arraylist.h"
//porque no?
using namespace std;

void busquedaProfundidadAux(NodoGrafo* nodoTemp, Dlinkedlist<NodoGrafo>* listaVecinosNoVisitados) {
    nodoTemp->visitar();
    //------- Lo del arco -------------------------------------

    //---------------------------------------------------------
    for (listaVecinosNoVisitados->gotoStart(); listaVecinosNoVisitados->atEnd(); listaVecinosNoVisitados->next()) {
        NodoGrafo vecinoNoVisitado = listaVecinosNoVisitados->getElement();
        Dlinkedlist<NodoGrafo>* listaVecinos = vecinoNoVisitado.retornarAdyacentes();
        Dlinkedlist<NodoGrafo>* listaVecinosNoVisitados = new Dlinkedlist<NodoGrafo>() ;
        for (listaVecinos->gotoStart(); !listaVecinos->atEnd(); listaVecinos->next()) {
            NodoGrafo vecino = listaVecinos->getElement();

            if (vecino.retornarVisitado() != false) {
                listaVecinosNoVisitados->append(vecino);
            }
        }

        NodoGrafo* vecinoNoVisitado2 = &vecinoNoVisitado;

        if (listaVecinos->getSize() != 0) {
            busquedaProfundidadAux(vecinoNoVisitado2, listaVecinosNoVisitados);
        }

        
    }

}

void busquedaProfundidad(ArrayList<ArrayList<NodoGrafo*>*>* lista) {
    for (lista->gotoStart(); !lista->atEnd(); lista->next()) {

        ArrayList<NodoGrafo*>* temp = lista->getElement();
        for (temp->gotoStart(); !temp->atEnd(); temp->next()) {

            NodoGrafo* nodoTemp = temp->getElement();
            nodoTemp->visitar();
            
            Dlinkedlist<NodoGrafo>* listaVecinos = nodoTemp->retornarAdyacentes();
            Dlinkedlist<NodoGrafo>* listaVecinosNoVisitados = new Dlinkedlist<NodoGrafo>();
           
            for (listaVecinos->gotoStart(); !listaVecinos->atEnd(); listaVecinos->next()) {
                NodoGrafo vecino = listaVecinos->getElement();

                if (vecino.retornarVisitado() != false) {
                    listaVecinosNoVisitados->append(vecino);
                }
            }

            //----------------- Ya esta lista de lista de vecinos no visitados


            busquedaProfundidadAux(nodoTemp , listaVecinosNoVisitados);

        }
    }

    
}



int main(){
    /*
    sf::RenderWindow window(sf::VideoMode(1830, 960), "SFML DOSEN'T works!(Te paras mike).");
    sf::RectangleShape shape(sf::Vector2f(10,10));
    sf::RectangleShape shape2(sf::Vector2f(10, 10));
    sf::RectangleShape shape3(sf::Vector2f(10, 10));
    sf::RectangleShape shape4(sf::Vector2f(10, 10));
    shape.setFillColor(sf::Color::Magenta);
    shape2.setFillColor(sf::Color::Green);
    shape3.setFillColor(sf::Color::Red);
    shape4.setFillColor(sf::Color::Blue);

    float rotacion = 0;
    float rotacion2 = 90;
    float rotacion3 = 180;
    float rotacion4 = 270;
    float x_coord = 0;
    float y_coord = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //window.draw(shape);
        //window.draw(shape2);
        window.draw(shape3);
        window.draw(shape4);
        window.display();
        shape2.setRotation(rotacion);
        shape.setRotation(rotacion2);
        //shape3.setRotation(rotacion3);
        //shape4.setRotation(rotacion4);
        rotacion -= 90.5;
        rotacion2 -= 90.5;
        //rotacion3 -= 90.5;
        //rotacion4 -= 90.5;
        shape2.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        shape.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        shape3.setPosition(x_coord, y_coord);
        shape4.setPosition(x_coord+1, y_coord+1);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            x_coord += 0.2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            x_coord -= 0.2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            y_coord -= 0.2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            y_coord += 0.2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            window.clear();
    }*/


    Grafo* nuevoGrafo = new Grafo(4);
    ArrayList<ArrayList<NodoGrafo*>*>* lista = nuevoGrafo->retornarListaNodos();
    for (lista->gotoStart();!lista->atEnd();lista->next()) {
        
        ArrayList<NodoGrafo*>* temp = lista->getElement();
        for (temp->gotoStart(); !temp->atEnd();temp->next()) {
            
            NodoGrafo* nodotemp = temp->getElement();
            cout << nodotemp->returnid() << "\t";
        }
        cout << endl;
    }

    //busquedaProfundidad(lista);

    return 0;
}
