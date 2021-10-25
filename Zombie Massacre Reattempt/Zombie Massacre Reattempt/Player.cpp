#include "Player.h"

Player::Player()
{
	#pragma region Linking Variables

	/*Linking the main contents to the variables*/
	m_speed = START_SPEED;
	m_health = START_HEALTH;
	m_maxHealth = START_HEALTH;

	#pragma endregion

	#pragma region Linking Textures

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

	/*Spawn Player In centre of Play Space*/
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
	#pragma region Cool Down

	/*Creating a cool down hit time so player doesn’t lose all their health at once*/
	if (timeHit.asMicroseconds() - m_lastHit.asMilliseconds() > 200)
	{
		/*Update last hit time to create the cool down then take 10 health*/
		m_lastHit = timeHit;
		m_health -= 10;
		return true;
	}
	else
	{
		/*If cooldown isn’t complete, do nothing*/
		return false;
	}

	#pragma endregion
}

sf::Time Player::lastHitTime() { return sf::Time(); }

#pragma region Get Players Data on location and rotation
/*Getting the current position from the sprite*/
sf::FloatRect Player::getPosition() { return m_Sprite.getLocalBounds(); }

/*Get the current rotation of this sprite*/
float Player::getRotation() { return m_Sprite.getRotation(); }

sf::Sprite Player::getSprite() { return m_Sprite; }

int Player::getHealth() { return m_health; }

/*Get the Position which will tell us the centre*/
sf::Vector2f Player::getCenter() { return m_position; }
#pragma endregion

#pragma region Movement
#pragma region Button Pressed
void Player::moveLeft() { m_leftArrowPressed = true; }

void Player::moveRight() { m_rightArrowPressed = true; }

void Player::moveUp() { m_upArrowPressed = true; }

void Player::moveDown() { m_downArrowPressed = true; }
#pragma endregion

#pragma region Button Releced
void Player::stopLeft() { m_leftArrowPressed = false; }

void Player::stopRight() { m_rightArrowPressed = false; }

void Player::stopUp() { m_upArrowPressed = false; }

void Player::stopDown() { m_downArrowPressed = false; }
#pragma endregion
#pragma endregion

void Player::update(float elapsedTime, sf::Vector2i mousePos)
{
	#pragma region Movement
	/*If detect arrow presses and move it by the speed set*/
	if (m_upArrowPressed) { m_position.y -= m_speed * elapsedTime; }

	if (m_downArrowPressed) { m_position.y += m_speed * elapsedTime; }

	if (m_leftArrowPressed) { m_position.x -= m_speed * elapsedTime; }

	if (m_rightArrowPressed) { m_position.x += m_speed * elapsedTime; }
	#pragma endregion

	/*Update Position*/
	m_Sprite.setPosition(m_position);

	#pragma region Boundaries
	/*Making sure they can’t leave the play space*/
	if (m_position.x > m_arena.width - m_tilesize) { m_position.x = m_arena.width - m_tilesize; }

	if (m_position.x > m_arena.left + m_tilesize) { m_position.x = m_arena.left + m_tilesize; }

	if (m_position.y > m_arena.height - m_tilesize) { m_position.y = m_arena.height - m_tilesize; }

	if (m_position.y > m_arena.top + m_tilesize) { m_position.y = m_arena.top + m_tilesize; }
	#pragma endregion

	#pragma region Roation from Mouse
	float angle = (atan2(mousePos.y - m_screenRes.y / 2,
		mousePos.x - m_screenRes.x / 2) * 180)
		/ 3.141;

	m_Sprite.setRotation(angle);
	#pragma endregion
}

#pragma region Player Perks
/*Upgrade the health by 20%*/
void Player::upgradeHealth() { m_maxHealth += (START_HEALTH * .2); }

/*Upgrade the speed by 20%*/
void Player::upgradeSpeed() { m_speed += (START_SPEED * .2); }


void Player::increaseHealth(int amount)
{
	m_health += amount;

	/*But not pass the max health*/
	if (m_health > m_maxHealth) { m_health = m_maxHealth; }
}
#pragma endregion


void Player::resetPlayerState()
{
	/*Setting variables with the constant when game starts / resets*/
	m_speed = START_SPEED;
	m_health = START_HEALTH;
	m_maxHealth = m_maxHealth;
}

