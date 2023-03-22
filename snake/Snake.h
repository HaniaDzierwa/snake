#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include "MojeStale.h"



struct position {

	//przechowuje pozycje w pikselach, pozycja lewego gornego rogu prostokata : ))
	int x, y;
};

enum heading
{
	up,
	down,
	left,
	right,
};

 class Snake
 {
 private :
	 // snake body
	// std::vector <position> body;
	 std::vector<sf::Sprite> bodyApperance; // static_cast<int>(name of float )
	 heading snakeHeading; 
	 heading snakeBodyHeading;


	 sf::Sprite head;
	 

	 sf::Texture* bodyTexture;
	 sf::Texture* headTexture;


	 
	 void initVariables();
	 void initBody();
	 void initSnakeHeading();
	 void initBodyApperance();
	 void rotateHead();

	 void getUserInput();

	 sf::Vector2f getTurnPos();
	 sf::Vector2f moveHead();
	
	 
	 //void moveBody();
	// void moveElement(int index, heading whereBody, sf::Vector2f positionPrev);

	
	 
 public:
	 Snake(sf::Texture * headTexture, sf::Texture * bodyTexture);
	 virtual ~Snake();

	  sf::FloatRect getPossitionNowS();
	 std::vector<sf::Sprite>* getBodyApperance();

	 int getSize();
	 bool checkEnd();
	 
	 void grow();
	 void move();
	 void update();
	 void renderBody(sf::RenderTarget *target);


 };

