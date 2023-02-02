#pragma once

#include <string>
#include <iostream>
#include <algorithm>

namespace stw
{
struct Vec3
{
	constexpr Vec3() : Vec3(0, 0, 0)
	{}

	constexpr Vec3(const float x, const float y, const float z) : x(x), y(y), z(z)
	{}

	float x;
	float y;
	float z;

	constexpr static Vec3 Lerp(Vec3 a, Vec3 b, float t);

	constexpr static Vec3 Zero();

	[[nodiscard]] float Magnitude() const;

	[[nodiscard]] constexpr float SqrMagnitude() const;

	[[nodiscard]] Vec3 Normalized() const;

	[[nodiscard]] constexpr float Dot(Vec3 other) const;

	[[nodiscard]] constexpr Vec3 Cross(Vec3 other) const;

	[[nodiscard]] float Distance(Vec3 other) const;

	[[nodiscard]] float Angle(Vec3 other) const;

	[[nodiscard]] constexpr float Major() const;

	[[nodiscard]] Vec3 NewMagnitude(float newMagnitude) const;

	[[nodiscard]] std::string ToString() const;

	constexpr Vec3 operator+(Vec3 other) const;

	constexpr Vec3 operator-(Vec3 other) const;

	constexpr Vec3 operator+=(Vec3 other);

	constexpr Vec3 operator-=(Vec3 other);

	constexpr Vec3 operator*=(float scalar);

	constexpr Vec3 operator/=(float scalar);

	constexpr bool operator==(Vec3 other) const;

	constexpr Vec3 operator-() const;

	friend Vec3 operator*(Vec3 vec, float scalar);

	friend Vec3 operator*(float scalar, Vec3 vec);

	friend Vec3 operator/(Vec3 vec, float scalar);
};

constexpr Vec3 Vec3::Lerp(const Vec3 a, const Vec3 b, float t)
{
	t = std::clamp(t, 0.0f, 1.0f);
	return {a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t};
}

constexpr Vec3 Vec3::Zero()
{
	return {0, 0, 0};
}

constexpr float Vec3::SqrMagnitude() const
{
	return x * x + y * y + z * z;
}

constexpr float Vec3::Dot(const Vec3 other) const
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}


constexpr float Vec3::Major() const
{
	return std::max(std::max(x, y), z);
}

constexpr Vec3 Vec3::operator+(const Vec3 other) const
{
	return {this->x + other.x, this->y + other.y, this->z + other.z};
}

constexpr Vec3 Vec3::operator-(const Vec3 other) const
{
	return {this->x - other.x, this->y - other.y, this->z - other.z};
}

constexpr Vec3 Vec3::operator+=(const Vec3 other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

constexpr Vec3 Vec3::operator-=(const Vec3 other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

constexpr Vec3 Vec3::operator*=(const float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	return *this;
}

constexpr Vec3 Vec3::operator/=(const float scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
	return *this;
}

constexpr bool Vec3::operator==(const Vec3 other) const
{
	return (x == other.x && y == other.y && z == other.z);
}

constexpr Vec3 Vec3::operator-() const
{
	return {-x, -y, -z};
}

constexpr Vec3 Vec3::Cross(Vec3 other) const
{
	return {(y * other.z) - (z * other.y), (z * other.x) - (x * other.z), (x * other.z) - (y * other.x)};
}

std::ostream& operator<<(std::ostream& os, Vec3 vec);
}

