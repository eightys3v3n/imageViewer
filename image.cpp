#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "filesystem.hpp"

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