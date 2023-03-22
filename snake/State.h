#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

class State
{
public:
	enum stateGame
	{
		end,
		pause,
		play,
		start
	};


	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	
	sf::Text uiText;

	//Resources
	sf::Font font;





    bool endPlayingGame();
	bool pausePlayingGame();
	bool PlayingGame();
	bool startPlayingGame();

};
