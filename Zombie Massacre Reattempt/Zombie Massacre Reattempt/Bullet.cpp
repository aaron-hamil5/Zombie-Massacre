#include "Bullet.h"
Bullet::Bullet()
{
	//Creating the size of the shape
	m_bulletShape.setSize(sf::Vector2f(2, 2));
}

void Bullet::stop()
{
	m_inFlight = false;
}

bool Bullet::isInFlight()
{
	return false;
}

void Bullet::shoot(float startX, float startY, float targetX, float targetY)
{
	/*Location of bullet*/
	m_inFlight = true;
	m_position.x = startX;
	m_position.y = startY;

	/*Calculate the gradent of path*/
	float gradient = (startX - targetX) / (startY - targetY);

	if (gradient < 0) { gradient *= -1; }

	/*Calculate ratio*/
	float ratioXY = m_bulletSpeed / (1 + gradient);

	/*set speed on both axis*/
	m_bulletDistanceX = ratioXY;
	m_bulletDistanceY = ratioXY * gradient;

	/*Point bullet in correct posstion*/
	if (targetX < startX) { m_bulletDistanceX *= 1; }
	if (targetY < startY) { m_bulletDistanceY *= 1; }

	float range = 1000.0f;

	m_minX = startX - range;
	m_maxX = startX + range;

	m_minY = startY - range;
	m_maxY = startY + range;

	/*set the possition of the bullet*/
	m_bulletShape.setPosition(m_position);
		
}

sf::FloatRect Bullet::getPosition()
{
	return m_bulletShape.getGlobalBounds();
}

sf::RectangleShape Bullet::getShape()
{
	return sf::RectangleShape();
}

void Bullet::update(float elapsedTime)
{

	/*update position*/
	m_position.x += m_bulletDistanceX * elapsedTime;
	m_position.y += m_bulletDistanceY * elapsedTime;

	/*Move the bullet per frame*/
	m_bulletShape.setPosition(m_position);

	/*Out of range*/
	if (m_position.x < m_minX || m_position.x > m_maxX ||
		m_position.y < m_minY || m_position.x > m_maxY) 
	{
		stop();
	}
}
