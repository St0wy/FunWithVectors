#pragma once

#include <raylib-cpp.hpp>

#include "math/Vec2.hpp"
#include "math/Vec2xN.hpp"

namespace stw
{
class SimdPlanetSystem
{
public:
	static constexpr float INNER_RADIUS = 200.0f;
	static constexpr float OUTER_RADIUS = 800.0f;
	static constexpr float SIMULATION_SPEED = 16.0f;
	static constexpr std::size_t SOA_SIZE = 8;

	SimdPlanetSystem(std::size_t planetsAmount, Vec2 sunPos, float sunMass);

	void Update(float deltaTime);
	void Draw() const;

private:
	std::vector<Vec2xN<SOA_SIZE>> m_CurrentPositions{};
	std::vector<Vec2xN<SOA_SIZE>> m_OldPositions{};
	std::vector<Vec2xN<SOA_SIZE>> m_Accelerations{};
	std::vector<raylib::Color> m_Colors{};
	std::vector<float> m_Radii{};
	float m_SunMass;
	Vec2 m_SunPos;

	Vec2 GetRandomPositionInSystem() const;
};
} // stw