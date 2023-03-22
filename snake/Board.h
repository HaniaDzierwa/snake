#pragma once

#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

const int sizeBoard = 100;


class Board
{
private : 

	// Variables
	enum state
	{
		blank,
		snake, 
		food,
		wall

	};

	// text
	sf::Text uiText;

	//Resources
	sf::Font font;

	void initFonts();
	
	void initText();
	/* Function to  update and render board  
	
	- update and render points 



	*/
public:

	
	Board();
	virtual ~Board();
	void updateText(int points);
	void renderText(sf::RenderTarget * target);
};
