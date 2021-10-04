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
	#pragma region Spawn Player Location
	/*Spawn Player In center of PlaySpace*/
	m_position.x = arena.width / 2;
	m_position.y = arena.height / 2;
	#pragma endregion

	#pragma region Sizing of area, Tiles, Resolution
	/*Load the arena to m_arena*/
	m_arena.left = arena.left;
	m_arena.width = arena.width;
	m_arena.top = arena.top;
	m_arena.height = arena.height;

	/*Tile size*/
	m_tilesize = tileSize;

	/*Save resolution*/
	m_screenRes.x = resolution.x;
	m_screenRes.y = resolution.y;
	#pragma endregion
}

bool Player::hit(sf::Time timeHit)
{
	/*Creating a cool down hit time so player doesnt lose all their health at once*/
	if (timeHit.asMicroseconds() - m_lastHit.asMilliseconds() > 200) 
	{
		/*Update last hit time to create the cool down then take 10 health*/
		m_lastHit = timeHit;
		m_health -= 10;
		return true;
	}
	else
	{
		/*If cooldown isnt complete, do nothing*/
		return false;
	}
}

sf::Time Player::lastHitTime()
{
	return sf::Time();
}

sf::FloatRect Player::getPosition()
{
	/*Getting the current position from the sprite*/
	return m_Sprite.getLocalBounds();
}

float Player::getRotation()
{
	/*Get the current rotation of this sprite*/
	return m_Sprite.getRotation();
}

sf::Sprite Player::getSprite()
{
	return m_Sprite;
}

int Player::getHealth()
{
	return m_health;
}

sf::Vector2f Player::getCenter()
{
	/*Get the Position which will tell us the center*/
	return m_position;
}

void Player::moveLeft()
{
	m_leftArrowPressed = true;
}

void Player::moveRight()
{
	m_rightArrowPressed = true;
}

void Player::moveUp()
{
	m_upArrowPressed = true;
}

void Player::moveDown()
{
	m_downArrowPressed = true;
}

void Player::stopLeft()
{
	m_leftArrowPressed = false;
}

void Player::stopRight()
{
	m_rightArrowPressed = false;
}

void Player::stopUp()
{
	m_upArrowPressed = false;
}

void Player::stopDown()
{
	m_downArrowPressed = false;
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

void Player::resetPlayerState()
{
	/*Setting varibles with the constent when game starts / resets*/
	m_speed = START_SPEED;
	m_health = START_HEALTH;
	m_maxHealth = m_maxHealth;


}
