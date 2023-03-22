#include "Board.h"
#include <iostream>

void Board::initFonts()
{
	if (!this->font.loadFromFile("Fonts/BubbleShine.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::failed to load font!" << "\n";
	}
}

Board::Board()
{
	this->initFonts();
	this->initText();

}

Board::~Board()
{
	
}


void Board::updateText(int points)
{
	std::stringstream ss;
	ss << "Points: " << points << "\n";
	this->uiText.setString(ss.str());
	//std:: cout << "Points: " << this->points << std::endl;
}



void Board::renderText(sf::RenderTarget *target)
{
	target->draw(this->uiText);
}

void Board::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(24);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setString("NONE");
}