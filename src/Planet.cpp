#include "Planet.hpp"
#include "Consts.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

void stw::Planet::Update(const Vec2 sunPos, const float sunMass, const float deltaTime)
{
	AddGravityForce(sunPos, sunMass);
	const Vec2 acceleration = m_Force / m_Mass;
	m_Force = Vec2::Zero();
	m_Velocity += acceleration * deltaTime;
	m_Position += m_Velocity * deltaTime;
}

void stw::Planet::SetupSpeed(const Vec2 sunPos, const float sunMass)
{
	const Vec2 planetToSun = sunPos - m_Position;
	const float radius = planetToSun.Magnitude();
	const float force = (G * sunMass * m_Mass) / (radius * radius);
	const float accelerationAmount = force / m_Mass;
	const float velocityAmount = std::sqrt(accelerationAmount * radius);

	const Vec2 perpendicular = (planetToSun / radius).PositivePerpendicular();

	m_Velocity = perpendicular * velocityAmount;
}

void stw::Planet::Draw(sf::RenderWindow& window)
{
	m_Circle.setPosition(m_Position);
	window.draw(m_Circle);
}

void stw::Planet::AddGravityForce(const Vec2 pos, const float mass)
{
	const Vec2 planetToSun = pos - m_Position;
	const float radius = planetToSun.Magnitude();
	const float forceAmount = (G * mass * m_Mass) / (radius * radius);
	const Vec2 force = (planetToSun / radius) * forceAmount;
	m_Force += force;
}

