#include "PlanetSystem.hpp"

#include <numbers>
#include "math/Utils.hpp"

stw::PlanetSystem::PlanetSystem(std::size_t planetsAmount, stw::Vec2 sunPos, float sunMass) : m_SunPos(sunPos),
																							  m_SunMass(sunMass)
{
	m_Planets.reserve(planetsAmount);
	for (std::size_t i = 0; i < planetsAmount; ++i)
	{
		const float radius = RandomRange(INNER_RADIUS, OUTER_RADIUS);
		const float angle = RandomRange(0.0f, std::numbers::pi_v<float> * 2.0f);

		const Vec2 position = sunPos + stw::Vec2(std::cos(angle) * radius, std::sin(angle) * radius);
		stw::Planet planet{100000000000.0f, position};
		planet.SetupSpeed(sunPos, sunMass);
		m_Planets.push_back(planet);
	}
}

void stw::PlanetSystem::Update(float deltaTime)
{
	for (auto& planet: m_Planets)
	{
		planet.Update(m_SunPos, m_SunMass, deltaTime * SIMULATION_SPEED);
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
