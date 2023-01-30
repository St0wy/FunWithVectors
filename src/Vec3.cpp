// ReSharper disable CppClangTidyClangDiagnosticFloatEqual
#include "Vec3.hpp"

#include <sstream>
#include <cmath>

namespace stw
{
	float Vec3::Magnitude() const
	{
		return std::sqrt(SqrMagnitude());
	}

	Vec3 Vec3::Normalized() const
	{
		if (x == 0 && y == 0 && z == 0)
		{
			return Vec3::Zero();
		}

		const float invMag = 1.0f / Magnitude();
		const Vec3 newVec = {x * invMag, y * invMag, z * invMag};
		return newVec;
	}

	float Vec3::Distance(const Vec3 other) const
	{
		return std::sqrt((this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y) +
						 (this->z - other.z) * (this->z - other.z));
	}

	Vec3 Vec3::NewMagnitude(const float newMagnitude) const
	{
		return (*this * newMagnitude) / Magnitude();
	}

	std::string Vec3::ToString() const
	{
		std::ostringstream ss;
		ss << "[" << x << ", " << y << ", " << z << "]";
		return ss.str();
		//	return std::format("[{}, {}, {}]", x, y, z);
	}

	std::ostream &operator<<(std::ostream &os, const Vec3 vec)
	{
		return os << vec.ToString();
	}

	Vec3 operator*(Vec3 vec, const float scalar)
	{
		return vec *= scalar;
	}

	Vec3 operator*(const float scalar, const Vec3 vec)
	{
		return operator*(vec, scalar);
	}

	Vec3 operator/(Vec3 vec, const float scalar)
	{
		return vec /= scalar;
	}
}
