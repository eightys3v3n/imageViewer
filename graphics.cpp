#include "graphics.hpp"


void centre_origin(RectangleShape& o)
{
	o.setOrigin(o.getGlobalBounds().width/2,o.getGlobalBounds().height/2);
}

void centre_origin(Text& o)
{
	o.setOrigin(o.getGlobalBounds().width/2,o.getGlobalBounds().height/2);
}