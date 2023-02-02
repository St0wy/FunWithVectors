//
// Created by stowy on 02/02/2023.
//
#include "Planet.hpp"
#include "Consts.hpp"

void stw::Planet::Update(Vec2 sunPos, float sunMass, float deltaTime)
{
	const Vec2 planetToSun = sunPos - m_Position;
	const float radius = planetToSun.Magnitude();
	const float forceAmount = (G * sunMass * m_Mass) / (radius * radius);
	const Vec2 force = (planetToSun / radius) * forceAmount;
	const Vec2 acceleration = force / m_Mass;
	m_Velocity += acceleration * deltaTime;
	m_Position += m_Velocity * deltaTime;
}

void stw::Planet::SetupSpeed(stw::Vec2 sunPos, float sunMass)
{
	const Vec2 planetToSun = sunPos - m_Position;
	const float radius = planetToSun.Magnitude();
	const float force = (G * sunMass * m_Mass) / (radius * radius);
	const float accelerationAmount = force / m_Mass;
	const float velocityAmount = std::sqrt(accelerationAmount * radius);

	const Vec2 perpendicular = (planetToSun / radius).PositivePerpendicular();

	m_Velocity = perpendicular * velocityAmount;
}

void stw::Planet::Draw() const
{
	DrawCircle(static_cast<int>(m_Position.x), static_cast<int>(m_Position.y), m_Radius, m_Color);
}

