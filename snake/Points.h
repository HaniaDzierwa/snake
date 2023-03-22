#pragma once

// wyswietle kolko w randowmym miejscu jesli na planszy nie ma kolka 
//- w snake jesli glowa trafi na kolko to zwieksze ogon i dodam plus jeden , kolko usune 

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "MojeStale.h"



class Points
{
private:

	int score;
	void initPoint();
	sf::Vector2f PossitionRandom();

	sf::Sprite apple; 

public:

	Points (sf::Texture *appleTexture);
	virtual ~Points();



	sf::FloatRect getPossitionNowP();
	
	int getPoints();
	void setPoints(int points);
		
	
	void update();
	
	void renderPoint(sf::RenderTarget*target);

};



