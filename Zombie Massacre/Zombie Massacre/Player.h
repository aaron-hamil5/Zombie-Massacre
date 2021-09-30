#ifndef PLAYER_H
#define PLAYER_H

//SFML graphics
#include<SFML/Graphics.hpp>

class Player 
{
	private:
		#pragma region Variables
		/*Player speed*/
		const float START_SPEED = 200.0f;
		/*Player health*/
		const float START_HEALTH = 100.0f;
		int m_maxHealth;
		int m_health;

		/*Player location*/
		sf::Vector2f m_position;
		
		/*Players sprite and texture*/
		sf::Sprite m_Sprite;
		sf::Texture m_texture;
		
		/*Screen Bounderies*/
		sf::Vector2f m_screenRes;
		
		/*Playspace Boundries and size*/
		sf::IntRect m_arena;
		int m_tilesize;

		/* Player movement*/
		bool m_upArrowPressed = false;
		bool m_downArrowPressed = false;
		bool m_leftArrowPressed = false;
		bool m_rightArrowPressed = false;

		/*Player Taking damage*/
		sf::Time m_lastHit;

		/*Players movement in pixels per second*/
		float m_speed;
		#pragma endregion

	public:
		/*Constuctor*/
		Player();
		//Spawning in the player
		void spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize);

		#pragma region Meathods

		#pragma region Player Hit
		//Handle if the player is being hit
		bool hit(sf::Time timeHit);
		/*Last Time Hit*/
		sf::Time lastHitTime();
		#pragma endregion

		#pragma region Location and angle
		/*Current position*/
		sf::FloatRect getPosition();
		/*Current angle*/
		float getRotation();
		#pragma endregion

		#pragma region Sprite center and share to main
		/*Give Copy of sprite to main fuction*/
		sf::Sprite getSprite();
		/*Center of sprite*/
		sf::Vector2f getCenter();
		#pragma endregion

		#pragma region Movement
		/*Movement Meathods*/
		//Allow Movement
		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();
		//Restrict movement
		void stopLeft();
		void stopRight();
		void stopUp();
		void stopDown();
		#pragma endregion

		/*Update per frame*/
		void update(float elapsedTime, sf::Vector2i mousePos);

		#pragma region Upgrades
		//Giver Player Extra health
		void upgradeHealth();
		void upgradeSpeed();

		void increaseHealth();
		int getHealth();
		#pragma endregion

		//Resets the player when game over
		void resetPlayerState();
		#pragma endregion
};

#endif
