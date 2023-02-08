#include "SimdPlanetSystem.hpp"

#include <cassert>
#include <numbers>

#include "Planet.hpp"


stw::SimdPlanetSystem::SimdPlanetSystem(const std::size_t planetsAmount, const Vec2 sunPos, const float sunMass)
	: m_SunMass(sunMass), m_SunPos(sunPos)
{
	assert(planetsAmount % SOA_SIZE > == 0);
	const std::size_t dividedAmount = planetsAmount / SOA_SIZE;

	m_CurrentPositions.reserve(dividedAmount);
	m_OldPositions.reserve(dividedAmount);
	m_Accelerations.reserve(dividedAmount);
	m_Colors.reserve(planetsAmount);
	m_Radii.reserve(planetsAmount);

	for (std::size_t i = 0; i < planetsAmount; ++i)
	{
		m_Colors.push_back(GetRandomColor());
		m_Radii.push_back(RandomRange(Planet::MIN_RADIUS, Planet::MAX_RADIUS));

		if (i % SOA_SIZE == 0)
		{
			const auto pos1 = GetRandomPositionInSystem();
			const auto pos2 = GetRandomPositionInSystem();
			const auto pos3 = GetRandomPositionInSystem();
			const auto pos4 = GetRandomPositionInSystem();
			const auto pos5 = GetRandomPositionInSystem();
			const auto pos6 = GetRandomPositionInSystem();
			const auto pos7 = GetRandomPositionInSystem();
			const auto pos8 = GetRandomPositionInSystem();

			std::array x = { pos1.x, pos2.x, pos3.x, pos4.x, pos5.x, pos6.x, pos7.x, pos8.x };
			std::array y = { pos1.y, pos2.y, pos3.y, pos4.y, pos5.y, pos6.y, pos7.y, pos8.y };
			m_CurrentPositions.emplace_back(x, y);
			m_OldPositions.emplace_back();
			m_Accelerations.emplace_back();
		}
	}
}

void stw::SimdPlanetSystem::Update(float deltaTime)
{

}

stw::Vec2 stw::SimdPlanetSystem::GetRandomPositionInSystem() const
{
	const float radius = RandomRange(INNER_RADIUS, OUTER_RADIUS);
	const float angle = RandomRange(0.0f, std::numbers::pi_v<float> *2.0f);
	return m_SunPos + stw::Vec2(std::cos(angle) * radius, std::sin(angle) * radius);
}
