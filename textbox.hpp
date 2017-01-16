#ifndef TEXTBOX_H
#define TEXTBOX_H

#define FONT_SIZE 20

#include <string>
#include <SFML/System.hpp>
#include "graphics.hpp"
#include "aliases.hpp"

#include <stdio.h>

extern Font font;

struct TextBox
{
	sf::RectangleShape shape;
	sf::Text text;
	bool visible = true;

	TextBox();
	void setPosition(Vector2f p);
	void appendText(char n);
	void appendText(string n);
};

#endif // TEXTBOX_H