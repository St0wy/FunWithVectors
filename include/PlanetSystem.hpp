#pragma once

#include <vector>

#include "Planet.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Window.hpp>

namespace stw
{
class PlanetSystem
{
public:
	static constexpr float INNER_RADIUS = 200.0f;
	static constexpr float OUTER_RADIUS = 800.0f;
	static constexpr float SIMULATION_SPEED = 16.0f;
	PlanetSystem(std::size_t planetsAmount, Vec2 sunPos, float sunMass);

	void Update(float deltaTime);
	void Draw(sf::RenderWindow&);

private:
	std::vector<Planet> m_Planets{};
	float m_SunMass{};
	Vec2 m_SunPos{};
	sf::CircleShape m_SunShape{};
};
} // stw
