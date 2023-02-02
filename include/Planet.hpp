#pragma once

#include "raylib-cpp.hpp"

#include "math/Vec2.hpp"
#include "math/Utils.hpp"

namespace stw
{

class Planet
{
public:
	Planet() : Planet(0.0f, {})
	{}

	Planet(float mass, Vec2 position) : m_Mass(mass), m_Position(position), m_Radius(RandomRange(7.0f, 17.0f))
	{
		const auto r = static_cast<unsigned char>(
				RandomRange(static_cast<unsigned short>(50), static_cast<unsigned short>(255)));
		const auto g = static_cast<unsigned char>(
				RandomRange(static_cast<unsigned short>(50), static_cast<unsigned short>(255)));
		const auto b = static_cast<unsigned char>(
				RandomRange(static_cast<unsigned short>(50), static_cast<unsigned short>(255)));
		m_Color = raylib::Color(r, g, b);
	}

	void SetupSpeed(Vec2 sunPos, float sunMass);

	void Update(Vec2 sunPos, float sunMass, float deltaTime);

	void Draw() const;

	[[nodiscard]] Vec2 GetPosition() const
	{ return m_Position; }

	[[nodiscard]] Vec2 GetVelocity() const
	{ return m_Velocity; }

private:
	float m_Radius{};
	float m_Mass{};
	Vec2 m_Position{};
	Vec2 m_Velocity{};
	raylib::Color m_Color{};
};

} // stw
