#include "PlanetSystem.hpp"

#include <numbers>

#include "math/Utils.hpp"
#include "math/Vec2.hpp"

stw::PlanetSystem::PlanetSystem(const std::size_t planetsAmount, const Vec2 sunPos, const float sunMass) :
	m_SunMass(sunMass), m_SunPos(sunPos), m_SunShape(15.0f)
{
	m_SunShape.setPosition(sunPos);
	m_SunShape.setFillColor(sf::Color::Red);

	m_Planets.reserve(planetsAmount);
	for (std::size_t i = 0; i < planetsAmount; ++i)
	{
		const float radius = RandomRange(INNER_RADIUS, OUTER_RADIUS);
		const float angle = RandomRange(0.0f, std::numbers::pi_v<float> *2.0f);

		const Vec2 position = sunPos + stw::Vec2(std::cos(angle) * radius, std::sin(angle) * radius);
		stw::Planet planet{ position };
		planet.SetupSpeed(sunPos, sunMass);
		m_Planets.push_back(planet);
	}
}

void stw::PlanetSystem::Update(const float deltaTime)
{
	for (auto& planet : m_Planets)
	{
		planet.Update(m_SunPos, m_SunMass, deltaTime * SIMULATION_SPEED);
	}
}

void stw::PlanetSystem::Draw(sf::RenderWindow& window)
{
	window.draw(m_SunShape);

	for (auto& planet : m_Planets)
	{
		planet.Draw(window);
	}
}
