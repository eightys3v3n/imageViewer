#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "filesystem.hpp"

extern sf::RenderWindow window;
extern sf::RectangleShape imageShape;
extern sf::Texture imageTexture;
extern sf::Image image;

bool loadImage( std::string path )
{
  if ( ! fileExists( path ) )
  {
    throw "image does not exist.";
    return true;
  }

  try
  {
    image.loadFromFile( path );
  }
  catch (...)
  {
    throw "could not load image.";
    return true;
  }

  try
  {
    imageTexture.loadFromImage( image, sf::IntRect(0,0, image.getSize().x, image.getSize().y ) );
  }
  catch (...)
  {
    throw "could not load texture from image.";
    return true;
  }

  try
  {
    imageShape.setTexture( &imageTexture );
  }
  catch (...)
  {
    throw "could not set imageShape's texture.";
    return true;
  }

  return false;
}

void fitImage( sf::RectangleShape* imageShape )
{
  sf::Vector2f newSize;

  newSize.x = (float)window.getSize().x / image.getSize().x;
  newSize.y = (float)window.getSize().y / image.getSize().y;

  if ( newSize.x < newSize.y )
  {
    newSize.y = image.getSize().y * newSize.x;
    newSize.x = image.getSize().x * newSize.x;
  }
  else
  {
    newSize.x = image.getSize().x * newSize.y;
    newSize.y = image.getSize().y * newSize.y;
  }

  imageShape->setSize( newSize );

  // centre image
  imageShape->setPosition( ( window.getSize().x - newSize.x ) / 2, imageShape->getPosition().y );
  imageShape->setPosition( imageShape->getPosition().x, ( window.getSize().y - newSize.y ) / 2 );
}

// written by terrence plunkett (eightys3v3n)