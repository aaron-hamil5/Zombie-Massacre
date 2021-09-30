#include "Player.h"

Player::Player()
{
	#pragma region Linking Variables
	/*Linking the main constents to the variables*/
	m_speed = START_SPEED;
	m_health = START_HEALTH;
	m_maxHealth = START_HEALTH;
	#pragma endregion

	#pragma region Linking Textures4
	/*Setting image to texture and linking texture*/
	m_texture.loadFromFile("Assets/graphics/player.png");
	m_Sprite.setTexture(m_texture);
	#pragma endregion

	/*Getting the location*/
	m_Sprite.setOrigin(25, 25);
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
