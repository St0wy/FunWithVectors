#pragma once
#include <string>
#include <iostream>

namespace stw
{
struct Vec2
{
	constexpr Vec2()
		: Vec2(0, 0)
	{}

	constexpr Vec2(const float x, const float y)
		: x(x), y(y)
	{}

	float x;
	float y;

	static Vec2 Lerp(Vec2 a, Vec2 b, float t);
	constexpr static Vec2 Zero();

	[[nodiscard]] float Magnitude() const;

	[[nodiscard]] float SqrMagnitude() const;

	[[nodiscard]] Vec2 Normalized() const;

	[[nodiscard]] float Dot(Vec2 other) const;

	[[nodiscard]] float Distance(Vec2 other) const;

	[[nodiscard]] float Angle(Vec2 other) const;

	[[nodiscard]] float Major() const;

	[[nodiscard]] Vec2 PositivePerpendicular() const;

	[[nodiscard]] Vec2 NegativePerpendicular() const;

	[[nodiscard]] Vec2 NewMagnitude(float newMagnitude) const;

	[[nodiscard]] std::string ToString() const;

	Vec2 operator+(Vec2 other) const;
	Vec2 operator-(Vec2 other) const;
	Vec2 operator+=(Vec2 other);
	Vec2 operator-=(Vec2 other);
	Vec2 operator*=(float scalar);
	Vec2 operator/=(float scalar);
	bool operator==(Vec2 other) const;
	Vec2 operator-() const;

	friend Vec2 operator*(Vec2 vec, float scalar);
	friend Vec2 operator*(float scalar, Vec2 vec);
	friend Vec2 operator/(Vec2 vec, float scalar);
};

constexpr Vec2 Vec2::Zero()
{
	return {0, 0};
}

std::ostream& operator<<(std::ostream& os, Vec2 vec);
}

