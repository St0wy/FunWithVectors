// ReSharper disable CppClangTidyClangDiagnosticFloatEqual
#include "Vec2.hpp"

#include <sstream>
#include <cmath>

namespace stw
{
float Vec2::Magnitude() const
{
	return std::sqrt(SqrMagnitude());
}

Vec2 Vec2::Normalized() const
{
	if (x == 0 && y == 0)
	{
		return {0, 0};
	}

	const float invMag = 1.0f / Magnitude();
	const Vec2 newVec = {x * invMag, y * invMag};
	return newVec;
}

float Vec2::Distance(const Vec2 other) const
{
	return std::sqrt((this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y));
}

float Vec2::Angle(const Vec2 other) const
{
	return std::acos(this->Dot(other) / Magnitude() * other.Magnitude());
}

Vec2 Vec2::NewMagnitude(const float newMagnitude) const
{
	return (*this * newMagnitude) / Magnitude();
}

std::string Vec2::ToString() const
{
	std::ostringstream ss;
	ss << "[" << x << ", " << y << "]";
	return ss.str();
	//	return std::format("[{}, {}]", x, y);
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

Vec2::operator raylib::Vector2() const
{
	return {x, y};
}

}
