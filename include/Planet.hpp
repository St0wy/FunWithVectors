#pragma once

#include <raylib-cpp.hpp>

#include "math/Vec2.hpp"
#include "math/Utils.hpp"

namespace stw
{

class Planet
{
public:
	static constexpr float BASE_MASS = 100000000000.0f;
	static constexpr float MIN_RADIUS = 7.0f;
	static constexpr float MAX_RADIUS = 17.0f;

	Planet() : Planet({ 0.0f, 0.0f })
	{}

	explicit Planet(const Vec2 position) : m_Position(position)
	{
		m_Radius = RandomRange(MIN_RADIUS, MAX_RADIUS);
		m_Mass = BASE_MASS * m_Radius;
		const auto r = static_cast<unsigned char>(
			RandomRange(static_cast<unsigned short>(50), static_cast<unsigned short>(255)));
		const auto g = static_cast<unsigned char>(
			RandomRange(static_cast<unsigned short>(50), static_cast<unsigned short>(255)));
		const auto b = static_cast<unsigned char>(
			RandomRange(static_cast<unsigned short>(50), static_cast<unsigned short>(255)));
		m_Color = raylib::Color(r, g, b);
	}

	Planet(const Vec2 position, const float mass, const float radius) : m_Radius(radius), m_Mass(mass), m_Position(position)
	{}

	void SetupSpeed(Vec2 sunPos, float sunMass);

	void Update(Vec2 sunPos, float sunMass, float deltaTime);

	void AddGravityForce(Vec2 pos, float mass);

	void Draw() const;

	[[nodiscard]] Vec2 GetPosition() const
	{
		return m_Position;
	}

	[[nodiscard]] Vec2 GetVelocity() const
	{
		return m_Velocity;
	}

	[[nodiscard]] float GetMass() const
	{
		return m_Mass;
	}

private:
	float m_Radius{};
	float m_Mass{};
	Vec2 m_Position{};
	Vec2 m_Velocity{};
	Vec2 m_Force{};
	raylib::Color m_Color{};
};

} // stw
