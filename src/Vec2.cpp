// ReSharper disable CppClangTidyClangDiagnosticFloatEqual
#include "Vec2.hpp"

#include <format>

namespace stw
{
Vec2 Vec2::Lerp(const Vec2 a, const Vec2 b, float t)
{
	t = std::clamp(t, 0.0f, 1.0f);
	return {
		a.x + (b.x - a.x) * t,
		a.y + (b.y - a.y) * t
	};
}

float Vec2::Magnitude() const
{
	return std::sqrt(SqrMagnitude());
}

float Vec2::SqrMagnitude() const
{
	return x * x + y * y;
}

Vec2 Vec2::Normalized() const
{
	if (x == 0 && y == 0)
	{
		return { 0, 0 };
	}

	const float invMag = 1.0f / Magnitude();
	const Vec2 newVec = { x * invMag, y * invMag };
	return newVec;
}

float Vec2::Dot(const Vec2 other) const
{
	return this->x * other.x + this->y * other.y;
}

float Vec2::Distance(const Vec2 other) const
{
	return std::sqrt((this->x - other.x) * (this->x - other.x) +
        (this->y - other.y) * (this->y - other.y));
}

float Vec2::Angle(const Vec2 other) const
{
	return std::acos(this->Dot(other) / Magnitude() * other.Magnitude());
}

float Vec2::Major() const
{
	if (x >= y)
    {
        return x;
    }

    return y;
}

Vec2 Vec2::PositivePerpendicular() const
{
	return {-y, x};
}

Vec2 Vec2::NegativePerpendicular() const
{
	return {y, -x};
}

Vec2 Vec2::NewMagnitude(const float newMagnitude) const
{
	return (*this * newMagnitude) / Magnitude();
}

std::string Vec2::ToString() const
{
	return std::format("[{}, {}]", x, y);
}

Vec2 Vec2::operator+(const Vec2 other) const
{
	return {this->x + other.x, this->y + other.y};
}

Vec2 Vec2::operator-(const Vec2 other) const
{
	return {this->x - other.x, this->y - other.y};
}

Vec2 Vec2::operator+=(const Vec2 other)
{
	this->x += other.x;
    this->y += other.y;
    return *this;
}

Vec2 Vec2::operator-=(const Vec2 other)
{
	this->x -= other.x;
    this->y -= other.y;
    return *this;
}

Vec2 Vec2::operator*=(const float scalar)
{
	this->x *= scalar;
    this->y *= scalar;
    return *this;
}

Vec2 Vec2::operator/=(const float scalar)
{
	this->x /= scalar;
    this->y /= scalar;
    return *this;
}

bool Vec2::operator==(const Vec2 other) const
{
	return (x == other.x && y == other.y);
}

Vec2 Vec2::operator-() const
{
	return {-x, -y};
}

std::ostream& operator<<(std::ostream& os, const Vec2 vec)
{
	return os << vec.ToString();
}

Vec2 operator*(Vec2 vec, const float scalar)
{
	return vec *= scalar;
}

Vec2 operator*(const float scalar, const Vec2 vec)
{
	return operator*(vec, scalar);
}

Vec2 operator/(Vec2 vec, const float scalar)
{
	return vec /= scalar;
}
}

