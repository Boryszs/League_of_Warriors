#pragma once
#include<string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

/// Class to creat object button 
class Button
{
public:
	/// Constructor Class Button
	Button();
	/// Constructor Class Button
	/// <param name="text"> - Text on the button</param>
	/// <param name="pos_x"> - Position width button</param>
	/// <param name="pos_y"> - Position height button</param>
	/// <param name="color"> - Color button</param>
	/// <param name="text_pos_x"> - Position width text on button</param>
	/// <param name="text_pos_y"> - Position height text on button</param>
	/// <returns></returns>
	Button(String text,int pos_x, int pos_y, Color color, int text_pos_x, int text_pos_y);

	///Destructor Button
	~Button();

	/// Function to set value
	/// <param name="write"> - The inscription that will be shown on the button </param>
	/// <param name="width"> - Width button</param>
	/// <param name="height"> - Height button</param>
	/// <param name="color"> - Color background button</param>
	/// <param name="pos_x"> - Position x button</param>
	/// <param name="pos_y"> - Position y button </param>
	/// <param name="pos_x_txt"> - Possition x text on button </param>
	/// <param name="pos_y_txt"> - Possition y text on button </param>
	void setButton(String write, int width, int height, Color color, int pos_x, int pos_y, int pos_x_txt, int pos_y_txt);

	/// Function get RectangleShape use to show create graphic button
	RectangleShape getButton();
	/// String to keep text button
	String write;
	/// Object temporary use to create view button
	RectangleShape button;
	/// Object use to show string button
	Text text;
	/// Object font use load Font used for entering text
	Font font; 
	/// Function return object Text to printnig text
	Text getText();
	/// Function set new text on button 
	void setText(string write);
};

