#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "image.hpp"
#include "input.hpp"
#include "window.hpp"
using namespace std;
using namespace sf;

bool running = true;

RenderWindow window;
RectangleShape imageShape;
Texture imageTexture;
Image image;

int main( int argc, char** argv )
{
  if ( argc == 1 )
  {
    cout << "imageView <image path>" << endl;
    return true;
  }
  else
  {
    try
    {
      loadImage( argv[1] );
    }
    catch ( string error )
    {
      cout << error << endl;
      return true;
    }
  }

  window.create( VideoMode( 800, 500 ), "image viewer" );
  window.setFramerateLimit( 11 );
  imageShape.setPosition(0,0);
  imageShape.setSize( sf::Vector2f( window.getSize().x, window.getSize().y ) );

  while ( window.isOpen() )
  {
    draw();
    input();
  }

  if ( window.isOpen() )
    window.close();

  return false;
}

// written by terrence plunkett (eightys3v3n)