#include "Player.h"

Player::Player()
{
}

void Player::spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize)
{
}

bool Player::hit(sf::Time timeHit)
{
	return false;
}

sf::Time Player::lastHitTime()
{
	return sf::Time();
}

sf::FloatRect Player::getPosition()
{
	return sf::FloatRect();
}

float Player::getRotation()
{
	return 0.0f;
}

sf::Sprite Player::getSprite()
{
	return sf::Sprite();
}

sf::Vector2f Player::getCenter()
{
	return sf::Vector2f();
}

void Player::moveLeft()
{
}

void Player::moveRight()
{
}

void Player::moveUp()
{
}

void Player::moveDown()
{
}

void Player::stopLeft()
{
}

void Player::stopRight()
{
}

void Player::stopUp()
{
}

void Player::stopDown()
{
}

void Player::update(float elapsedTime, sf::Vector2i mousePos)
{
}

void Player::upgradeHealth()
{
}

void Player::upgradeSpeed()
{
}

void Player::increaseHealth()
{
}

int Player::getHealth()
{
	return 0;
}

void Player::resetPlayerState()
{
}
