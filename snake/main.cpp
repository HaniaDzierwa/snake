
#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Snake.h"
#include "Points.h"





using namespace std; 
int main()
{
   // init srand 

	srand(static_cast<unsigned>(time(NULL)));

	// init game engine 
	Game game;



	while (game.running() && !game.getEndGame())
	{
		//Update
		game.update();

		//Render
		game.render();
	}


	return 0;
}


