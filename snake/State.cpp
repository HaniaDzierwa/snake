#include "State.h"

bool State::endPlayingGame()
{

	//std:: cout << "Points: " << this->points << std::endl;

	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(24);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setString("NONE");

	
	return false;
}

bool State::pausePlayingGame()
{
	this->window = new sf::RenderWindow(this->videoMode, "Pause", sf::Style::Close);
	return false;
}

bool State::PlayingGame()
{
	this->window = new sf::RenderWindow(this->videoMode, "Play", sf::Style::Close);
	return false;
}

bool State::startPlayingGame()
{
	this->window = new sf::RenderWindow(this->videoMode, "Start ", sf::Style::Close);
	return false;
}
