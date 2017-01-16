#include "textbox.hpp"

TextBox::TextBox()
{
	text.setFont(font);
	text.setCharacterSize(FONT_SIZE);
	text.setFillColor(sf::Color::Black);

	shape.setFillColor(sf::Color::White);
	shape.setSize(Vector2f(100,font.getLineSpacing(FONT_SIZE)+30));
}

void TextBox::setPosition(Vector2f p)
{
	shape.setPosition(p);
	text.setPosition(p);
}

void TextBox::appendText(char n)
{
	string o = text.getString();
	o += n;

	text.setString(o.c_str());
	shape.setSize(Vector2f(text.getGlobalBounds().width+5,shape.getSize().y));
	printf("textbox:%s\n", o.c_str());
	fflush(stdout);
}

void TextBox::appendText(string n)
{
	string o = text.getString();
	o += n;

	text.setString(o);
	printf("textbox:%s\n", o.c_str());
	fflush(stdout);
}