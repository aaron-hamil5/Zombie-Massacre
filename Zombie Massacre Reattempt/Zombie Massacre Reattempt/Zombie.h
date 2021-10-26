#ifndef ZOMBIE_H
#define ZOMBIE_H

#include<SFML/Graphics.hpp>

class Zombie
{
public:
	Zombie();

	/*Zombie getting hit*/
	bool hit();

	/*Alive?*/
	bool isAlive();

	/*Spawn in zombie*/
	void spawn(float startX, float StartY, int type, int seed);

	/*Get the play space*/
	sf::FloatRect getPosition();

	/*Get a copy of a sprite to create*/
	sf::Sprite getSprite();

	/*Update Zombie each frame*/
	void update(float elapsedTime, sf::Vector2i playerLocation);

private:
	#pragma region Speed
	/*How fast Zombies move*/
	const float BLOATER_SPEED = 40.0f;
	const float CHASER_SPEED = 80.0f;
	const float CRAWLER_SPEED = 20.0f;

	/*Speed they can move at*/
	float m_speed;

	/*Varying Speed*/
	const int MAX_VARIANCE;
	const int OFFSET = 101 - MAX_VARIANCE;
	#pragma endregion

	/*Damege inflict*/


	/*Location of zombie*/
	sf::Vector2f m_position;

	/*Zombie Sprite*/
	sf::Sprite m_sprite;

	/*Health*/
	const float BLOATER_HEALTH = 5.0f;
	const float CHASER_HEALTH = 1.0f;
	const float CRAWLER_HEALTH = 3.0f;
	float m_Health;

	/*Alive?*/
	bool m_isAlive;

};

#endif ZOMBIE_IF