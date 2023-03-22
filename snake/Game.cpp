#include "Game.h"



void Game::initWindow()
{
	this->videoMode.height = windowHeight;
	this->videoMode.width = windowWidth;

	this->window = new sf::RenderWindow(this->videoMode, "Snake", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(5);


}

void Game::initVariables()
{
	this->window = nullptr;

	// Game logic
	this->endGame = false;
	this->score = 0;
	this-> appleTexture.loadFromFile("jablko.png");
	this->headTexture.loadFromFile("head.png");
	this->bodyTexture.loadFromFile("body.png");


	this->point = new Points(&(this->appleTexture));
	this->snake = new Snake(&this->headTexture, &this->bodyTexture);

	/*this->status.push(State::stateGame::start);
	this->status.push(State::stateGame::play);
	this->status.push(State::stateGame::pause);
	this->status.push(State::stateGame::end);
	*/

}


Game::Game()
{
	this->initVariables();
	this->initWindow();

}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
}



 /*
 void Game::statesGame()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) // end game
	{
		state.endPlayingGame(); // tutaj pokaz napis koniec 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) // trzeba dwa razy esc kliknac zeby zakonczyc gre 
			this->endGame = true;
		// zakoncz gre 

		status.pop();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) // pause game
	{

		state.pausePlayingGame();
	status.pop();
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) // start game
	{
		state.startPlayingGame();
		bool checkSnakePointCollision();
		void checkPoints();
		void endGameWall();
		void pollEvents();
		void update();
		void render();
		status.pop();
	}
	
}
*/

bool  Game::checkSnakePointCollision()
{
	
	for (int i = 0; i < snake->getSize() - 1; i++)
	{
		if ((*(snake->getBodyApperance()))[i].getGlobalBounds().intersects(point->getPossitionNowP()))
		{
			return true;
		}
	}
	return false;
}

void Game::checkPoints()
{
	point->renderPoint(this->window);

	if (snake->getPossitionNowS().intersects(point->getPossitionNowP()))
	{
		point->update();
	
		while (checkSnakePointCollision())
		{
			point->update();
		}
		
	
			
		point->setPoints(score++);
		snake->grow();
		
		
			
		
	}
}


void Game::endGameWall()
{
	if (snake->checkEnd())

		//state.endPlayingGame();
		this->endGame = true;
	
}

void Game::pollEvents()
{

	// Event pooling 
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;

		}
	}
}

void Game::update()
{	
	this->checkPoints();
	this->board.updateText(score);
	this->snake->update();
	this->endGameWall();
	this->pollEvents();
	

}

void Game::render()
{
	/*
	
	@return void 
	- clear old frame 
	- render objects
	- display frame in window

	Renders the game objects
	*/
	this->window->clear();

	//Draw objects
	
	
	this->snake->renderBody(this->window);
	this->point->renderPoint(this->window);
	this->board.renderText(this->window);
	//this->statesGame();
	this->window->display();
}


