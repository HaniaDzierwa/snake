#include "Points.h"



// points and food generation

void Points::initPoint()
{

    this->apple.setPosition(0.f, 0.f);
    PossitionRandom();

 
}

Points::Points(sf::Texture *appleTexture)
{
   this->initPoint();
   this->score = 0;
   this->apple.setTexture(*appleTexture);
}

Points::~Points()
{

}

sf::FloatRect Points::getPossitionNowP()
{
    return apple.getGlobalBounds();
}

int Points::getPoints()
{
    return this->score;
}

void Points::setPoints(int points)
{
    points = points;
}




sf::Vector2f Points::PossitionRandom()
{
    this->apple.setPosition(
        static_cast<float>(rand() % (static_cast<int>(windowWidth - 2*( pointOffSet + pointSize))) + pointOffSet + pointSize),
            static_cast<float>(rand() % (static_cast<int>(windowHeight -  2*(pointOffSet + pointSize))) + pointOffSet + pointSize));

    return apple.getPosition();
}


void Points::update()
{
    PossitionRandom();

}


void Points::renderPoint(sf::RenderTarget* target)
{
    
    target->draw(this->apple);
   
}
