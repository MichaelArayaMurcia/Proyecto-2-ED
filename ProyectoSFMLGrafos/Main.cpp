#include <SFML/Graphics.hpp>
//ahhhhhhhhhhhhhhhhhhhhhhhh
int main()
{
    sf::RenderWindow window(sf::VideoMode(1830, 960), "SFML DOSEN'T works!(Te paras mike).");
    sf::RectangleShape shape(sf::Vector2f(10,1000));
    sf::RectangleShape shape2(sf::Vector2f(10, 1000));
    sf::RectangleShape shape3(sf::Vector2f(10, 1000));
    sf::RectangleShape shape4(sf::Vector2f(10, 1000));
    shape.setFillColor(sf::Color::Magenta);
    shape2.setFillColor(sf::Color::Green);
    shape3.setFillColor(sf::Color::Red);
    shape4.setFillColor(sf::Color::Blue);

    float rotacion = 0;
    float rotacion2 = 90;
    float rotacion3 = 180;
    float rotacion4 = 270;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.draw(shape2);
        window.draw(shape3);
        window.draw(shape4);
        window.display();
        shape2.setRotation(rotacion);
        shape.setRotation(rotacion2);
        shape3.setRotation(rotacion3);
        shape4.setRotation(rotacion4);
        rotacion -= 90.5;
        rotacion2 -= 90.5;
        rotacion3 -= 90.5;
        rotacion4 -= 90.5;
        shape2.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        shape.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        shape3.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        shape4.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
    }

    return 0;
}
