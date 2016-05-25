#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

extern sf::RenderWindow window;
extern sf::RectangleShape imageShape;

void draw()
{
  window.clear( sf::Color::Black );

  window.draw( imageShape );

  window.display();
}