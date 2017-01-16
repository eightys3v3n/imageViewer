#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "image.hpp"
#include "window.hpp"
#include "filesystem.hpp"
#include "textbox.hpp"

extern bool running;
extern sf::RenderWindow window;
extern sf::RectangleShape imageShape;
extern TextBox commands;

sf::View view( window.getDefaultView() );

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

      case sf::Event::Resized:
        // this stupid statement is required because sfml stretches the window contents AUTOMATICALLY
        // and i don't see a way to turn it off. that's 30 minutes spent because i thought my fitImage()
        // function was broken; nope sfml just does that stupid stuff on it's own.
        window.setView( sf::View( sf::FloatRect(0, 0, event.size.width, event.size.height) ) );
        fitImage();
        break;

      case sf::Event::KeyPressed:
        switch (event.key.code)
        {
          case 71: // left
            nextImage();
            break;

          case 72: // right
            lastImage();
            break;

          default:
            commands.visible = true;
        }

#warning still working on textboxes for the command thing
/*      case sf::Event::TextEntered:
        if (commands.visible)
        {
          switch (event.key.code)
          {
            case 1:
              break;

            default:
              {
                char c = (char)event.text.unicode;
                printf("%i\n",(int)c);
                commands.appendText(c);
              }
          }
        }*/
        break;

      default:
        break;
    }
  }
}

// written by terrence plunkett (eightys3v3n)