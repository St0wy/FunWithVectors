#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <Vector2.hpp>

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

	Vec2(const raylib::Vector2 vec) : x(vec.x), y(vec.y) {} // NOLINT(google-explicit-constructor)

	float x;
	float y;

	constexpr static Vec2 Lerp(Vec2 a, Vec2 b, float t);

	constexpr static Vec2 Zero();

	[[nodiscard]] float Magnitude() const;

	[[nodiscard]] constexpr float SqrMagnitude() const;

	[[nodiscard]] Vec2 Normalized() const;

	[[nodiscard]] constexpr float Dot(Vec2 other) const;

	[[nodiscard]] float Distance(Vec2 other) const;

	[[nodiscard]] float Angle(Vec2 other) const;

	[[nodiscard]] constexpr float Major() const;

	[[nodiscard]] constexpr Vec2 PositivePerpendicular() const;

	[[nodiscard]] constexpr Vec2 NegativePerpendicular() const;

	[[nodiscard]] Vec2 NewMagnitude(float newMagnitude) const;

	[[nodiscard]] std::string ToString() const;

	constexpr Vec2 operator+(Vec2 other) const;

	constexpr Vec2 operator-(Vec2 other) const;

	constexpr Vec2 operator+=(Vec2 other);

	constexpr Vec2 operator-=(Vec2 other);

	constexpr Vec2 operator*=(float scalar);

	constexpr Vec2 operator/=(float scalar);

	constexpr bool operator==(Vec2 other) const;

	constexpr Vec2 operator-() const;

	friend Vec2 operator*(Vec2 vec, float scalar);

	friend Vec2 operator*(float scalar, Vec2 vec);

	friend Vec2 operator/(Vec2 vec, float scalar);

	operator raylib::Vector2() const;
};

constexpr Vec2 Vec2::Lerp(const Vec2 a, const Vec2 b, float t)
{
	t = std::clamp(t, 0.0f, 1.0f);
	return {
			a.x + (b.x - a.x) * t,
			a.y + (b.y - a.y) * t
	};
}

constexpr Vec2 Vec2::Zero()
{
	return {0, 0};
}

constexpr float Vec2::SqrMagnitude() const
{
	return x * x + y * y;
}

constexpr float Vec2::Dot(const Vec2 other) const
{
	return this->x * other.x + this->y * other.y;
}


constexpr float Vec2::Major() const
{
	return std::max(x, y);
}

constexpr Vec2 Vec2::PositivePerpendicular() const
{
	return {-y, x};
}

constexpr Vec2 Vec2::NegativePerpendicular() const
{
	return {y, -x};
}

constexpr Vec2 Vec2::operator+(const Vec2 other) const
{
	return {this->x + other.x, this->y + other.y};
}

constexpr Vec2 Vec2::operator-(const Vec2 other) const
{
	return {this->x - other.x, this->y - other.y};
}

constexpr Vec2 Vec2::operator+=(const Vec2 other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

constexpr Vec2 Vec2::operator-=(const Vec2 other)
{
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

constexpr Vec2 Vec2::operator*=(const float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	return *this;
}

constexpr Vec2 Vec2::operator/=(const float scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	return *this;
}

constexpr bool Vec2::operator==(const Vec2 other) const
{
	return (x == other.x && y == other.y);
}

constexpr Vec2 Vec2::operator-() const
{
	return {-x, -y};
}

std::ostream& operator<<(std::ostream& os, Vec2 vec);
}

