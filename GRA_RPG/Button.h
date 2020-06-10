#pragma once
#include<string>
#include <SFML/Graphics.hpp>

/*
Class to creat object button 
*/

using namespace std;
using namespace sf;

class Button
{
public:
	//constructor
	Button();
	Button(String,int,int, Color color,int,int);
	//destructor
	~Button();
	//function to set value
	void setButton(String write, int width, int height, Color color, int pos_x, int pos_y, int pos_x_txt, int pos_y_txt);
	//function to get object representation button
	RectangleShape getButton();
	//String to keep text button
	String write;
	//object help create view button
	RectangleShape button;
	//object use show text 
	Text text;
	//object font use to show text
	Font font; 
	//function return object showing text
	Text getText();
	//funcion set text to show 
	void setText(string write);
};

