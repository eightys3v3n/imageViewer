#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

extern bool running;

extern sf::RenderWindow window;

void input()
{
  sf::Event event;

  while ( window.pollEvent( event ) && running )
  {
    switch ( event.type )
    {
      case sf::Event::Closed:
        running = false;
        break;
    }
  }
}