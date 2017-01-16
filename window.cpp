#include "window.hpp"

extern sf::RenderWindow window;
extern sf::RectangleShape imageShape;
extern TextBox commands;

void draw()
{
  window.clear( sf::Color::Black );

  window.draw( imageShape );
  #warning still working on the textbox for tagging images and commands
  /*if (commands.visible)
  {
  	window.draw(commands.shape);
  	window.draw(commands.text);
  }*/

  window.display();
}

// written by terrence plunkett (eightys3v3n)