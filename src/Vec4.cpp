// ReSharper disable CppClangTidyClangDiagnosticFloatEqual
#include "Vec4.hpp"

#include <sstream>
#include <cmath>

namespace stw
{
	float Vec4::Magnitude() const
	{
		return std::sqrt(SqrMagnitude());
	}

	Vec4 Vec4::Normalized() const
	{
		if (x == 0 && y == 0 && z == 0 && w == 0)
		{
			return Vec4::Zero();
		}

		const float invMag = 1.0f / Magnitude();
		const Vec4 newVec = {x * invMag, y * invMag, z * invMag, w * invMag};
		return newVec;
	}

	float Vec4::Distance(const Vec4 other) const
	{
		return std::sqrt((this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y) +
						 (this->z - other.z) * (this->z - other.z) + (this->w - other.w) * (this->w - other.w));
	}

	Vec4 Vec4::NewMagnitude(const float newMagnitude) const
	{
		return (*this * newMagnitude) / Magnitude();
	}

	std::string Vec4::ToString() const
	{
		std::ostringstream ss;
		ss << "[" << x << ", " << y << ", " << z << ", " << w << "]";
		return ss.str();
		//	return std::format("[{}, {}, {}, {}]", x, y, z, w);
	}

	std::ostream &operator<<(std::ostream &os, const Vec4 vec)
	{
		return os << vec.ToString();
	}

	Vec4 operator*(Vec4 vec, const float scalar)
	{
		return vec *= scalar;
	}

	Vec4 operator*(const float scalar, const Vec4 vec)
	{
		return operator*(vec, scalar);
	}

	Vec4 operator/(Vec4 vec, const float scalar)
	{
		return vec /= scalar;
	}
}
