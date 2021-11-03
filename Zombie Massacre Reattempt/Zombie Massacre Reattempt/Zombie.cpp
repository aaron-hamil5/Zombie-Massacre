#include "Zombie.h"
Zombie::Zombie()
{
}

bool Zombie::hit()
{
	return false;
}

bool Zombie::isAlive()
{
	return false;
}

void Zombie::spawn(float startX, float StartY, int type, int seed)
{
}

sf::FloatRect Zombie::getPosition()
{
	return sf::FloatRect();
}

sf::Sprite Zombie::getSprite()
{
	return sf::Sprite();
}

void Zombie::update(float elapsedTime, sf::Vector2i playerLocation)
{
}
