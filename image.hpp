#ifndef IMAGE_
#define IMAGE_

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "filesystem.hpp"
#include "sorting.hpp"

typedef std::string string;

bool loadImage();
void fitImage();
bool nextImage();
bool lastImage();

#endif // IMAGE_

// written by terrence plunkett (eightys3v3n)