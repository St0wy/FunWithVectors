#include "PlanetSystem.hpp"

#include <numbers>
#include "math/Utils.hpp"

stw::PlanetSystem::PlanetSystem(const std::size_t planetsAmount, const Vec2 sunPos, const float sunMass) : m_SunMass(sunMass),
                                                                                                                m_SunPos(sunPos)
{
	m_Planets.reserve(planetsAmount);
	for (std::size_t i = 0; i < planetsAmount; ++i)
	{
		const float radius = RandomRange(INNER_RADIUS, OUTER_RADIUS);
		const float angle = RandomRange(0.0f, std::numbers::pi_v<float> * 2.0f);

		const Vec2 position = sunPos + stw::Vec2(std::cos(angle) * radius, std::sin(angle) * radius);
		stw::Planet planet{position};
		planet.SetupSpeed(sunPos, sunMass);
		m_Planets.push_back(planet);
	}
}

void stw::PlanetSystem::Update(float deltaTime)
{
	for (std::size_t i = 0; i < m_Planets.size(); ++i)
	{
		for (std::size_t j = i + 1; j < m_Planets.size(); ++j)
		{
			m_Planets[i].AddGravityForce(m_Planets[j].GetPosition(), m_Planets[j].GetMass());
		}
		m_Planets[i].Update(m_SunPos, m_SunMass, deltaTime * SIMULATION_SPEED);
	}
}

void stw::PlanetSystem::Draw()
{
	DrawCircle(static_cast<int>(m_SunPos.x), static_cast<int>(m_SunPos.y), 15.0f, RED);

	for (const auto& planet: m_Planets)
	{
		planet.Draw();
	}
}
