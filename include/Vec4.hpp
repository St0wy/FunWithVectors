#pragma once

#include <string>
#include <iostream>
#include <algorithm>

namespace stw
{
struct Vec4
{
	constexpr Vec4() : Vec4(0, 0, 0, 0)
	{}

	constexpr Vec4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w)
	{}

	float x;
	float y;
	float z;
	float w;

	constexpr static Vec4 Lerp(Vec4 a, Vec4 b, float t);

	constexpr static Vec4 Zero();

	[[nodiscard]] constexpr float SqrMagnitude() const;

	[[nodiscard]] float Magnitude() const;

	[[nodiscard]] Vec4 Normalized() const;

	[[nodiscard]] constexpr float Dot(Vec4 other) const;

	[[nodiscard]] float Distance(Vec4 other) const;

	[[nodiscard]] float Angle(Vec4 other) const;

	[[nodiscard]] constexpr float Major() const;

	[[nodiscard]] Vec4 NewMagnitude(float newMagnitude) const;

	[[nodiscard]] std::string ToString() const;

	constexpr Vec4 operator+(Vec4 other) const;

	constexpr Vec4 operator-(Vec4 other) const;

	constexpr Vec4 operator+=(Vec4 other);

	constexpr Vec4 operator-=(Vec4 other);

	constexpr Vec4 operator*=(float scalar);

	constexpr Vec4 operator/=(float scalar);

	constexpr bool operator==(Vec4 other) const;

	constexpr Vec4 operator-() const;

	friend Vec4 operator*(Vec4 vec, float scalar);

	friend Vec4 operator*(float scalar, Vec4 vec);

	friend Vec4 operator/(Vec4 vec, float scalar);
};

constexpr Vec4 Vec4::Lerp(const Vec4 a, const Vec4 b, float t)
{
	t = std::clamp(t, 0.0f, 1.0f);
	return {a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t, a.w + (b.w - a.w) * t};
}

constexpr Vec4 Vec4::Zero()
{
	return {0, 0, 0, 0};
}

constexpr float Vec4::SqrMagnitude() const
{
	return x * x + y * y + z * z + w * w;
}

constexpr float Vec4::Dot(const Vec4 other) const
{
	return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w;
}

constexpr float Vec4::Major() const
{
	return std::max(std::max(std::max(x, y), z), w);
}

constexpr Vec4 Vec4::operator+(const Vec4 other) const
{
	return {this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w};
}

constexpr Vec4 Vec4::operator-(const Vec4 other) const
{
	return {this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w};
}

constexpr Vec4 Vec4::operator+=(const Vec4 other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	this->w += other.w;
	return *this;
}

constexpr Vec4 Vec4::operator-=(const Vec4 other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	this->w -= other.w;
	return *this;
}

constexpr Vec4 Vec4::operator*=(const float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	this->w *= scalar;
	return *this;
}

constexpr Vec4 Vec4::operator/=(const float scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
	this->w /= scalar;
	return *this;
}

constexpr bool Vec4::operator==(const Vec4 other) const
{
	return (x == other.x && y == other.y && z == other.z && w == other.w);
}

constexpr Vec4 Vec4::operator-() const
{
	return {-x, -y, -z, -w};
}

std::ostream& operator<<(std::ostream& os, Vec4 vec);
}

