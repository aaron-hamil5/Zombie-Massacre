#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

class Bullet
{
	private:
		sf::Vector2f m_position;
		sf::RectangleShape m_bulletShape;

		bool m_inFlight = false;

		float m_bulletSpeed = 1000.0f;
		float m_bulletDistanceX, m_bulletDistanceY;

		float m_maxX, m_minX, m_maxY, m_minY;
	public:
		Bullet();

		void stop();
		bool isInFlight();
		void shoot(float, float, float, float);

		sf::FloatRect getPosition();
		sf::RectangleShape getShape();

		void update(float);
};

#endif BULLET_H