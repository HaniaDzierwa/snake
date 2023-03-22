#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include"Board.h"
#include"Snake.h"
#include"Points.h"
#include"State.h"
#include "MojeStale.h"
#include <stack>




class Game
{
private: 

	Board board;
	Snake *snake;
	Points *point;
	//State state; 

	std::stack<State::stateGame> status;
	// window
	sf::RenderWindow* window; 
	sf::VideoMode videoMode;
	sf::Event ev; 


	// object
	sf::Texture appleTexture;
	sf::Texture headTexture;
	sf::Texture bodyTexture;



	// mouse possition
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePos;





	//Game logic

	bool endGame;
	unsigned score;


	// Functions
	void initWindow();
	void initVariables();

	


public:
	
	
	// Constructors / Destructors
	Game();
	virtual ~Game();


	//Accessors 
	const bool running() const;
	const bool getEndGame() const;



	

	// Functions


	void statesGame();
	bool checkSnakePointCollision();
	void checkPoints();
	void endGameWall();
	void pollEvents();
    void update();
	void render();



};
