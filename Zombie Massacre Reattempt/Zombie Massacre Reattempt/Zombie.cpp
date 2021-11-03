#include "Zombie.h"
#include "TextureHolder.h"
Zombie::Zombie()
{
}

bool Zombie::hit()
{
	m_Health--;

	if (m_Health <= 0)
	{
		m_isAlive = false;
		//Swap current texture to blood
		m_sprite.setTexture(TextureHolder::GetTexture("assets/graphics/blood.png"));
		return true;
	}
	//Lost health but isnt dead yet
	return false;
}

bool Zombie::isAlive()
{
	return m_isAlive;
}

void Zombie::spawn(float startX, float StartY, int type, int seed)
{
#pragma region Diffrent types spawn in
	/*We will use our own Texture holder to handlethe textures effisently*/
	/*We will create a switch statement to spawn random zombies in*/
	switch (type)
	{
#pragma region Bloater '0'
	case 0:
		/*Spawn Bloater*/
		m_sprite = sf::Sprite(TextureHolder::GetTexture("assets/graphics/bloater.png"));

		/*Now linking the speed amd Health*/
		m_speed = BLOATER_SPEED;
		m_Health = BLOATER_HEALTH;

		/*Get out of switch*/
		break;
#pragma endregion

#pragma region Chaser '1'
	case 1:
		/*Spawn Bloater*/
		m_sprite = sf::Sprite(TextureHolder::GetTexture("assets/graphics/chaser.png"));

		/*Now linking the speed amd Health*/
		m_speed = CHASER_SPEED;
		m_Health = CHASER_HEALTH;

		/*Get out of switch*/
		break;
#pragma endregion

#pragma region Crawler '2'
	case 2:
		/*Spawn Bloater*/
		m_sprite = sf::Sprite(TextureHolder::GetTexture("assets/graphics/crawler.png"));

		/*Now linking the speed amd Health*/
		m_speed = CRAWLER_SPEED;
		m_Health = CRAWLER_HEALTH;

		/*Get out of switch*/
		break;
#pragma endregion

	default:
		break;
	}
#pragma endregion

#pragma region Unique speed
	/*Create unique speed*/
	srand((int)time(0) * seed);

	/*Between 80 to 100*/
	float modifier = (rand() % MAX_VARIANCE) + OFFSET;

	/*Express as a fraction of 1 making it .8 to 1*/
	modifier /= 100;

	/*Adding the extra speed*/
	m_speed *= modifier;
#pragma endregion

	/*Setting its location*/
	m_position.x = startX;
	m_position.y = StartY;

	/*Set Origin to center of sprite*/
	m_sprite.setOrigin(25, 25);

	/*Spawn location*/
	m_sprite.setPosition(m_position);
}

sf::FloatRect Zombie::getPosition()
{
	return m_sprite.getLocalBounds();
}

sf::Sprite Zombie::getSprite()
{
	return m_sprite;
}

void Zombie::update(float elapsedTime, sf::Vector2i playerLocation)
{
	/*Getting player position*/
	float playerPosX = playerLocation.x;
	float playerPosY = playerLocation.y;

	if (playerPosX > m_position.x) { m_position.x = m_position.x + m_speed * elapsedTime; }

	if (playerPosY > m_position.y) { m_position.y = m_position.y + m_speed * elapsedTime; }

	if (playerPosX < m_position.x) { m_position.x = m_position.x - m_speed * elapsedTime; }

	if (playerPosY < m_position.y) { m_position.y = m_position.y - m_speed * elapsedTime; }

	/*move the sprite*/
	m_sprite.setPosition(m_position);

	/*Look at the player*/
	float angle = (atan2(playerPosY - m_position.y, playerPosX - m_position.x) * 180) / 3.141;

	m_sprite.setRotation(angle);
}
