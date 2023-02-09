#pragma once

#include <numbers>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Planet.hpp"

#include "math/Vec2.hpp"
#include "math/Vec2xN.hpp"

namespace stw
{
template<std::size_t N>
class SimdPlanetSystem
{
public:
	static constexpr float INNER_RADIUS = 200.0f;
	static constexpr float OUTER_RADIUS = 1200.0f;
	static constexpr float GRAVITY_CONSTANT = 1000000.0f;

	SimdPlanetSystem(std::size_t planetsAmount, Vec2 sunPos);

	void SetupSpeeds();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow&);

private:
	std::vector<Vec2xN<N>> m_Positions{};
	std::vector<Vec2xN<N>> m_Velocities{};
	std::vector<Vec2xN<N>> m_Forces{};
	std::vector<sf::CircleShape> m_Shapes{};
	Vec2 m_SunPos;
	sf::CircleShape m_SunShape{};

	[[nodiscard]] Vec2 GetRandomPositionInSystem() const;
};

template <std::size_t N>
SimdPlanetSystem<N>::SimdPlanetSystem(const std::size_t planetsAmount, const Vec2 sunPos)
	: m_SunPos(sunPos)
{
	assert(planetsAmount % N == 0);
	m_SunShape.setPosition(sunPos);
	m_SunShape.setRadius(15.0f);
	m_SunShape.setFillColor(sf::Color::Red);

	const std::size_t dividedAmount = planetsAmount / N;

	m_Positions.reserve(dividedAmount);
	m_Velocities.reserve(dividedAmount);
	m_Forces.reserve(dividedAmount);
	m_Shapes.reserve(planetsAmount);

	for (std::size_t i = 0; i < planetsAmount; ++i)
	{
		m_Shapes.emplace_back(RandomRange(Planet::MIN_RADIUS, Planet::MAX_RADIUS));
		m_Shapes[i].setFillColor(GetRandomColor());

		if (i % N == 0)
		{
			std::array<float, N> x{};
			std::array<float, N> y{};

			for (std::size_t j = 0; j < N; ++j)
			{
				const auto pos = GetRandomPositionInSystem();
				x[j] = pos.x;
				y[j] = pos.y;
			}

			m_Positions.emplace_back(x, y);
			m_Velocities.emplace_back();
			m_Forces.emplace_back();
		}
	}
}

template <std::size_t N>
void SimdPlanetSystem<N>::SetupSpeeds()
{
	for (std::size_t i = 0; i < m_Positions.size(); ++i)
	{
		Vec2xN<N> sunPos{ m_SunPos };
		auto planetToSun = sunPos - m_Positions[i];
		auto radii = planetToSun.Magnitudes();
		const std::valarray<float> radiiWorking{ radii.data(), radii.size() };
		const auto accelerationAmount = GRAVITY_CONSTANT / (radiiWorking * radiiWorking);
		const auto velocityAmount = (accelerationAmount * radiiWorking).apply([](const float elem) { return std::sqrt(elem); });

		const auto perpendicular = (planetToSun / radii).PositivePerpendicular();
		m_Velocities[i] = perpendicular * velocityAmount;
	}
}

template <std::size_t N>
void SimdPlanetSystem<N>::Update(const float deltaTime)
{
	for (std::size_t i = 0; i < m_Positions.size(); ++i)
	{
		// Apply sun gravity
		Vec2xN<N> sunPos{ m_SunPos };
		auto planetToSun = sunPos - m_Positions[i];
		auto radii = planetToSun.Magnitudes();
		const std::valarray<float> radiiWorking{ radii.data(), radii.size() };
		const auto forceAmount = GRAVITY_CONSTANT / (radiiWorking * radiiWorking);
		const auto force = (planetToSun / radiiWorking) * forceAmount;
		m_Forces[i] += force;

		// Update positions
		m_Velocities[i] += m_Forces[i] * deltaTime;
		m_Forces[i].Reset();
		m_Positions[i] += m_Velocities[i] * deltaTime;
	}
}

template <std::size_t N>
void SimdPlanetSystem<N>::Draw(sf::RenderWindow& window)
{
	window.draw(m_SunShape);

	for (std::size_t i = 0; i < m_Shapes.size(); ++i)
	{
		const std::size_t j = i / N;
		const std::size_t rest = i % N;

		const int x = static_cast<int>(m_Positions[j].AtX(rest));
		const int y = static_cast<int>(m_Positions[j].AtY(rest));
		m_Shapes[i].setPosition(m_Positions[j].GetSubVec(rest));
		window.draw(m_Shapes[i]);
	}
}

template <std::size_t N>
Vec2 SimdPlanetSystem<N>::GetRandomPositionInSystem() const
{
	const float radius = RandomRange(INNER_RADIUS, OUTER_RADIUS);
	const float angle = RandomRange(0.0f, std::numbers::pi_v<float> *2.0f);
	return m_SunPos + stw::Vec2(std::cos(angle) * radius, std::sin(angle) * radius);
}
} // stw