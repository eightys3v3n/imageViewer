#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "image.hpp"
#include "input.hpp"
#include "window.hpp"
#include "textbox.hpp"
using namespace std;
using namespace sf;

bool running = true;

RenderWindow window;
RectangleShape imageShape;
Texture imageTexture;
Font font;
Image image;
string path;
TextBox commands;
bool update = false;

void init()
{
  sf::ContextSettings s;
  s.antialiasingLevel = 8;
  window.create( VideoMode( 800, 500 ), "", sf::Style::Default, s );
  window.setFramerateLimit( 30 );
  window.setVerticalSyncEnabled(true);

  imageTexture.setSmooth(true);
  imageShape.setPosition(0,0);

  font.loadFromFile("font.ttf");

  commands.setPosition(Vector2f(0,window.getSize().y-commands.shape.getSize().y));
}

int main( int argc, char** argv )
{
  if ( argc == 1 )
  {
    cout << "imageView <image path>" << endl;
    return true;
  }
  else
  {
    init();

    try
    {
      path = argv[1];
      loadImage();
    }
    catch ( string error )
    {
      cout << error << endl;
      return true;
    }
  }

  while ( running )
  {
    draw();
    input();
  }

  if ( window.isOpen() )
    window.close();

  return false;
}

// written by terrence plunkett (eightys3v3n)