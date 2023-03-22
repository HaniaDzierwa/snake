#include "Snake.h"

void Snake::initVariables()
{

}

void Snake::initBody()
{  
	head.setOrigin(15.f, 15.f);
	head.setPosition(50.f, 100.f);
	bodyApperance.push_back(head);
	

}

void Snake::initSnakeHeading()
{
	this->snakeHeading = down;
}

void Snake::initBodyApperance()
{
	this->snakeBodyHeading = right;
}



Snake::Snake(sf::Texture *headTexture,sf::Texture *bodyTexture)
{
	this->initVariables();
	this->initBody();
	this->initSnakeHeading();
	this->initBodyApperance();


	this->headTexture = headTexture;
	this->bodyTexture = bodyTexture;

	this->head.setTexture(*headTexture);
	
	this->bodyApperance[0].setTexture(*headTexture);

	for ( int i=1 ; i < bodyApperance.size(); i++)
	{
		this->bodyApperance[i].setTexture(*bodyTexture);
	}



	
}

Snake::~Snake()
{
	// krzysiu jest super <3 

}


void Snake::update()
{
	getUserInput();
	move();
	
	
}
void Snake::rotateHead()
{
	

	switch (snakeHeading)
	{
		
	case left:
		
		bodyApperance[0].setRotation(90);
		break;

	case right:
		
		bodyApperance[0].setRotation(270);
		break;

	case up:
		
		bodyApperance[0].setRotation(180);
		break;

	case down:
		
		bodyApperance[0].setRotation(0);
		break;

	}
}
sf::Vector2f Snake::moveHead()
{
	// it moves head in indicated direction 
	// dlaczego tutaj nie dziala bodyAperacne[0]  tylko musi byd head , w kazdej innej funkcji dziala bodyApperacne
	rotateHead();

	switch (snakeHeading)
	{
	case left:
		head.move(sf::Vector2f(-snakeElementSize, 0.f));
		
		break;

	case right:
		head.move(sf::Vector2f(snakeElementSize, 0.f));
	
		break;

	case up:
		head.move(sf::Vector2f(0.f, -snakeElementSize));
		
		break;

	case down:
		head.move(sf::Vector2f(0.f, snakeElementSize));
		break;

	}
	

	return getTurnPos();
	 
}

sf::Vector2f Snake::getTurnPos()
{
	return head.getPosition();
}

void Snake::move()
{
	// ustawiam ostatni element na pozycje wczesniejszego, glowe ustawiam tak jak gracz chce 
	for (int i = bodyApperance.size() - 1; i > 0; i--)
	{
		bodyApperance[i].setPosition(bodyApperance[i - 1].getPosition());
	}
	
	if (this->bodyApperance.size() >= 1)
	{
		bodyApperance[0].setPosition(moveHead());

	}
	
}

bool Snake::checkEnd ()
{
	// check collision with walls
	if (this->bodyApperance[0].getPosition().x < 0 || this->bodyApperance[0].getPosition().x> (windowWidth-snakeElementSize ))
	{
		return true;
	}

	if (this->bodyApperance[0].getPosition().y < 0 || this->bodyApperance[0].getPosition().y > (windowHeight-snakeElementSize ))
	{
		return true;
	}

	return false;

}

void Snake::getUserInput()
{
	// use to turn snake head, if key is not pressed- direction stays the same
	// and block the move into to snake body
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) and snakeHeading != heading::right)
	{
		this->snakeHeading = left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) and snakeHeading != heading::left)
	{
		this->snakeHeading = right;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) and snakeHeading != heading::down)
	{
		this->snakeHeading = up;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) and snakeHeading != heading::up)
	{
		this->snakeHeading = down;
	}

}

int Snake::getSize()
{
	return this->bodyApperance.size();
}

void Snake::grow()
{
	sf::Sprite bodyNext;

	bodyNext.setOrigin(15.f, 15.f);

	bodyNext.setTexture(*this->bodyTexture);
	

	auto posLast =this-> bodyApperance[bodyApperance.size()-1].getPosition();
	
	if (this->bodyApperance.size() == 1)
	{
		bodyNext.setPosition(posLast.x - snakeElementSize, posLast.y);
		bodyApperance.push_back(bodyNext);
		return; 
	}
	
	auto pos = this->bodyApperance[bodyApperance.size() - 2].getPosition();

		// robimy switach i bedziemy dodawac tam element gdzie idzie dalej cialo 
		if (posLast.x > pos.x)
			snakeBodyHeading = right;
		if (posLast.x < pos.x)
			snakeBodyHeading = left;
		if (posLast.x > pos.y)
			snakeBodyHeading = down;
		if (posLast.y < pos.y)
			snakeBodyHeading = up;

		switch (snakeBodyHeading)
		{
		case left:
			bodyNext.setPosition(posLast.x + snakeElementSize, posLast.y);
			break;

		case right:
			bodyNext.setPosition(posLast.x - snakeElementSize, posLast.y);
			break;

		case up:
			bodyNext.setPosition(posLast.x, posLast.y + snakeElementSize);
			break;
		case down:
			bodyNext.setPosition(posLast.x, posLast.y - snakeElementSize);
			break;
		}

		bodyApperance.push_back(bodyNext);
}

sf::FloatRect Snake::getPossitionNowS()
{
	return head.getGlobalBounds();
		
}


std::vector<sf::Sprite>* Snake::getBodyApperance()
{
	return &(this->bodyApperance);
}




void Snake::renderBody(sf::RenderTarget* target)
{
	target->draw(this->bodyApperance[0]);

	for (auto i : bodyApperance)
	{
		target->draw(i);
	}


}

/*
 void Snake::moveElement(int index, heading whereBody, sf::Vector2f pos)
{

	// moves elements step by step 
	switch (whereBody)
	{
	case left:
		bodyApperance[index].setPosition(pos);
		//bodyApperance[index].move(pos);
		break;

	case right:
		bodyApperance[index].setPosition(pos);
		//bodyApperance[index].move(pos);
		break;

	case up:
		bodyApperance[index].setPosition(pos);
		//bodyApperance[index].move(pos);
		break;
	case down:
		bodyApperance[index].setPosition(pos);
		//bodyApperance[index].move(pos);
		break;
	}
	
	//auto newpos = getTurnPos();

	//bodyApperance[index].setPosition(pos);
}

void Snake::moveBody()
{
	// moves the whole body by checking previous possition
	if (this->bodyApperance.size() == 1)
		return;

	for (int i = 1; i < bodyApperance.size(); i++)
	{
		auto positionPrev = this->bodyApperance[i - 1].getPosition();
		auto position = this->bodyApperance[i].getPosition();


		bodyApperance[i].setPosition(position);
		// check where is the previous possition to set body in right direction

		if (positionPrev.x > position.x && snakeHeading !=left)
			snakeBodyHeading = right;
		if (positionPrev.x < position.x && snakeHeading != right)
			snakeBodyHeading = left;
		if (positionPrev.y > position.y && snakeHeading != up)
			snakeBodyHeading = down;
		if (positionPrev.y < position.y && snakeHeading != down)
			snakeBodyHeading = up;

		moveElement(i, snakeBodyHeading, positionPrev);
	}
}
*/