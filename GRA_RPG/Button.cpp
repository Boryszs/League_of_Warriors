#include "Button.h"
#include<iostream>
using namespace sf;

Button::~Button()
{


}
Button::Button()
{


}
Button::Button(String write,int width,int height, Color color,int pos_x,int pos_y)
{
	button.setSize(Vector2f(width,height));
	button.setFillColor(color);
	button.setPosition(pos_x, pos_y);
	if (!font.loadFromFile("Fonts/Arial.ttf"))
	{
		std::cout << "eerr";
	}
	std::cout << "eerr";
	text.setFont(font);
	text.setString("fff");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(pos_x, pos_y);
	text.setStyle(sf::Text::Bold);

}

void Button::setButton(String write, int width, int height, Color color, int pos_x, int pos_y,int pos_x_txt,int pos_y_txt)
{
	button.setSize(Vector2f(width, height));
	button.setFillColor(color);
	button.setPosition(pos_x, pos_y);
	if (!font.loadFromFile("Fonts/Arial.ttf"))
	{
		std::cout << "eerr";
	}
	text.setFont(font);
	text.setString(write);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(pos_x_txt, pos_y_txt);
	text.setStyle(sf::Text::Bold);
}
RectangleShape Button::getButton()
{
	return button;
}

Text Button::getText()
{
	return text;
}

void Button::setText(string write)
{
	text.setString(write);
}