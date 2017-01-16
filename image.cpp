#include "image.hpp"

extern sf::RenderWindow window;
extern sf::RectangleShape imageShape;
extern sf::Texture imageTexture;
extern sf::Image image;
extern std::string path;
extern bool update;

bool loadImage()
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
    imageShape.setTexture( &imageTexture, true );
  }
  catch (...)
  {
    throw "could not set imageShape's texture.";
    return true;
  }

  {
    string name = path.substr(filePath(path).length());
    if (name[0] == '/')
      name = name.substr(1);

    window.setTitle(name);
  }

  fitImage();
  update = true;

  return false;
}

bool nextImage()
{
  string rootPath = filePath(path);
  string currentImage = path;
  string nextImage = "";

  if (rootPath == "")
    rootPath = ".";
  else
    currentImage = path.substr(rootPath.length() + 1);

  std::vector<string> files = listImages(rootPath);
  sortVector(files);

  nextImage = files[0];
  for (unsigned int i = 0; i < files.size(); i++)
  {
    if (files[i] == currentImage)
    {
      if (i+1 < files.size())
        nextImage = files[i+1];
    }
  }

  path = rootPath + "/" + nextImage;
  loadImage();

  return false;
}

bool lastImage()
{
  string rootPath = filePath(path);
  string currentImage = path;
  string lastImage = "";

  if (rootPath == "")
    rootPath = ".";
  else
    currentImage = path.substr(rootPath.length() + 1);

  std::vector<string> files = listImages(rootPath);
  sortVector(files);

  lastImage = files[files.size()-1];
  for (unsigned int i = 0; i < files.size(); i++)
  {
    if (files[i] == currentImage)
    {
      if (i-1 > 0)
        lastImage = files[i-1];
    }
  }

  path = rootPath + "/" + lastImage;
  loadImage();

  return false;
}

void fitImage()
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

  imageShape.setSize( newSize );

  // centre image
  imageShape.setPosition( ( window.getSize().x - newSize.x ) / 2, imageShape.getPosition().y );
  imageShape.setPosition( imageShape.getPosition().x, ( window.getSize().y - newSize.y ) / 2 );

  update = true;
}

// written by terrence plunkett (eightys3v3n)