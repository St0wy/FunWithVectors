#include "Vec3.hpp"

#include "gtest/gtest.h"
#include <numbers>

namespace stw
{
TEST(Vec3Test, DefaultConstructsWithZero)
{
	constexpr Vec3 v{};
	EXPECT_EQ(v.x, 0);
	EXPECT_EQ(v.y, 0);
	EXPECT_EQ(v.z, 0);
}

TEST(Vec3Test, Constructor)
{
	constexpr Vec3 v{-10, 42, 6.66};
	EXPECT_EQ(v.x, -10);
	EXPECT_EQ(v.y, 42);
	EXPECT_EQ(v.z, 6.66f);
}

TEST(Vec3Test, ZeroIsZero)
{
	constexpr Vec3 v = Vec3::Zero();
	EXPECT_EQ(v.x, 0);
	EXPECT_EQ(v.y, 0);
	EXPECT_EQ(v.z, 0);
}

TEST(Vec3Test, Lerp)
{
	constexpr Vec3 v{};
	constexpr Vec3 v2{2, 2, 2};
	constexpr auto vLerp = Vec3::Lerp(v, v2, 0.5f);
	EXPECT_FLOAT_EQ(vLerp.x, 1.0f);
	EXPECT_FLOAT_EQ(vLerp.y, 1.0f);
	EXPECT_FLOAT_EQ(vLerp.z, 1.0f);
}

TEST(Vec3Test, LerpNegative)
{
	constexpr Vec3 v{};
	constexpr Vec3 v2{-2, -2, -2};
	const auto vLerp = Vec3::Lerp(v, v2, 0.5f);
	EXPECT_FLOAT_EQ(vLerp.x, -1.0f);
	EXPECT_FLOAT_EQ(vLerp.y, -1.0f);
	EXPECT_FLOAT_EQ(vLerp.z, -1.0f);
}

TEST(Vec3Test, LerpMoreThanOne)
{
	constexpr Vec3 v{};
	constexpr Vec3 v2{2, 2, 2};
	const auto vLerp = Vec3::Lerp(v, v2, 2.0f);
	EXPECT_FLOAT_EQ(vLerp.x, 2.0f);
	EXPECT_FLOAT_EQ(vLerp.y, 2.0f);
	EXPECT_FLOAT_EQ(vLerp.z, 2.0f);
}

TEST(Vec3Test, LerpLessThanZero)
{
	constexpr Vec3 v{1, 1, 1};
	constexpr Vec3 v2{2, 2, 2};
	const auto vLerp = Vec3::Lerp(v, v2, -1.0f);
	EXPECT_FLOAT_EQ(vLerp.x, 1.0f);
	EXPECT_FLOAT_EQ(vLerp.y, 1.0f);
	EXPECT_FLOAT_EQ(vLerp.z, 1.0f);
}

TEST(Vec3Test, MagnitudeTwoZeros)
{
	constexpr Vec3 v{3, 0, 0};
	EXPECT_FLOAT_EQ(v.Magnitude(), 3.0f);
}


TEST(Vec3Test, MagnitudeNoZero)
{
	constexpr Vec3 v{3, 5, 6.2f};
	EXPECT_FLOAT_EQ(v.Magnitude(), 8.5111694f);
}

TEST(Vec3Test, SqrMagnitude)
{
	constexpr Vec3 v{3, 5, 6.2f};
	EXPECT_FLOAT_EQ(v.SqrMagnitude(), 72.440002);
}

TEST(Vec3Test, Normalized)
{
	constexpr Vec3 v{1, 2, 2};
	const Vec3 norm = v.Normalized();
	EXPECT_FLOAT_EQ(norm.x, 0.33333334);
	EXPECT_FLOAT_EQ(norm.y, 0.66666669);
	EXPECT_FLOAT_EQ(norm.z, 0.66666669);
}

TEST(Vec3Test, NormalizedZeroXZ)
{
	constexpr Vec3 v{0, 2, 0};
	const Vec3 norm = v.Normalized();
	EXPECT_FLOAT_EQ(norm.x, 0.0f);
	EXPECT_FLOAT_EQ(norm.y, 1.0f);
	EXPECT_FLOAT_EQ(norm.z, 0.0f);
}

TEST(Vec3Test, NormalizedZeroYZ)
{
	constexpr Vec3 v{2, 0, 0};
	const Vec3 norm = v.Normalized();
	EXPECT_FLOAT_EQ(norm.x, 1.0f);
	EXPECT_FLOAT_EQ(norm.y, 0.0f);
	EXPECT_FLOAT_EQ(norm.z, 0.0f);
}

TEST(Vec3Test, NormalizedZeroXY)
{
	constexpr Vec3 v{0, 0, 2.0f};
	const Vec3 norm = v.Normalized();
	EXPECT_FLOAT_EQ(norm.x, 0.0f);
	EXPECT_FLOAT_EQ(norm.y, 0.0f);
	EXPECT_FLOAT_EQ(norm.z, 1.0f);
}

TEST(Vec3Test, NormalizedZeroXYZ)
{
	constexpr Vec3 v{0, 0, 0};
	const Vec3 norm = v.Normalized();
	EXPECT_FLOAT_EQ(norm.x, 0.0f);
	EXPECT_FLOAT_EQ(norm.y, 0.0f);
	EXPECT_FLOAT_EQ(norm.z, 0.0f);
}

TEST(Vec3Test, Dot)
{
	constexpr Vec3 v1{2, 3, 2};
	constexpr Vec3 v2{1, 3, -7.6};
	const float dot = v1.Dot(v2);
	EXPECT_FLOAT_EQ(dot, -4.1999998);
}

TEST(Vec3Test, Cross)
{
	constexpr Vec3 v1{2, 3, 2};
	constexpr Vec3 v2{1, 3, -7.6};
	const Vec3 cross = v1.Cross(v2);
	EXPECT_FLOAT_EQ(cross.x, -28.799999);
	EXPECT_FLOAT_EQ(cross.y, 17.200001);
	EXPECT_FLOAT_EQ(cross.z, -18.200001);
}

TEST(Vec3Test, Distance)
{
	constexpr Vec3 v1{0, 5, 0};
	constexpr Vec3 v2{0, 0, 0};
	const float dist = v1.Distance(v2);
	EXPECT_FLOAT_EQ(dist, 5);
}

TEST(Vec3Test, MajorX)
{
	constexpr Vec3 v{5, 1, 2};
	const float major = v.Major();
	EXPECT_EQ(major, 5.0f);
	EXPECT_NE(major, 1.0f);
	EXPECT_NE(major, 2.0f);
}

TEST(Vec3Test, MajorY)
{
	constexpr Vec3 v{1, 5, 2};
	const float major = v.Major();
	EXPECT_EQ(major, 5.0f);
	EXPECT_NE(major, 1.0f);
	EXPECT_NE(major, 2.0f);
}

TEST(Vec3Test, NewMagnitude)
{
	constexpr Vec3 v{1, 0, 0};
	const Vec3 v2 = v.NewMagnitude(5);
	EXPECT_EQ(v2.x, 5.0f);
	EXPECT_EQ(v2.y, 0.0f);
	EXPECT_EQ(v2.z, 0.0f);
	EXPECT_FLOAT_EQ(v2.Magnitude(), 5.0f);
}

TEST(Vec3Test, ToString)
{
	constexpr Vec3 v{1, 0, 2};
	EXPECT_EQ(v.ToString(), "[1, 0, 2]");
}

TEST(Vec3Test, Add)
{
	constexpr Vec3 v1{1, 1, 1};
	const Vec3 v2 = v1 + v1;
	EXPECT_FLOAT_EQ(v2.x, 2);
	EXPECT_FLOAT_EQ(v2.y, 2);
	EXPECT_FLOAT_EQ(v2.z, 2);
}

TEST(Vec3Test, Sub)
{
	constexpr Vec3 v1{1, 1, 1};
	const Vec3 v2 = v1 - v1;
	EXPECT_FLOAT_EQ(v2.x, 0);
	EXPECT_FLOAT_EQ(v2.y, 0);
	EXPECT_FLOAT_EQ(v2.z, 0);
}

TEST(Vec3Test, AddEqual)
{
	Vec3 v1{1, 1, 1};
	v1 += v1;
	EXPECT_FLOAT_EQ(v1.x, 2);
	EXPECT_FLOAT_EQ(v1.y, 2);
	EXPECT_FLOAT_EQ(v1.z, 2);
}

TEST(Vec3Test, SubEqual)
{
	constexpr Vec3 v1{1, 1, 1};
	Vec3 v2{2, 2, 2};
	v2 -= v1;
	EXPECT_FLOAT_EQ(v2.x, 1);
	EXPECT_FLOAT_EQ(v2.y, 1);
	EXPECT_FLOAT_EQ(v2.z, 1);
}

TEST(Vec3Test, TimesEqualScalar)
{
	Vec3 v1{1, 1, 1};
	v1 *= 5.0f;
	EXPECT_FLOAT_EQ(v1.x, 5);
	EXPECT_FLOAT_EQ(v1.y, 5);
	EXPECT_FLOAT_EQ(v1.z, 5);
}

TEST(Vec3Test, DivideEqualScalar)
{
	Vec3 v1{5, 5, 5};
	v1 /= 2.0f;
	EXPECT_FLOAT_EQ(v1.x, 2.5f);
	EXPECT_FLOAT_EQ(v1.y, 2.5f);
	EXPECT_FLOAT_EQ(v1.z, 2.5f);
}

TEST(Vec3Test, EqualTrue)
{
	constexpr Vec3 v1{5, 5, 5};
	constexpr Vec3 v2{5, 5, 5};
	EXPECT_TRUE(v1 == v2);
}

TEST(Vec3Test, EqualFalse)
{
	constexpr Vec3 v1{5, 5, 5};
	constexpr Vec3 v2{5, 0, 5};
	EXPECT_FALSE(v1 == v2);
}

TEST(Vec3Test, Negative)
{
	constexpr Vec3 v1{5, -6, 7.7f};
	const Vec3 v2 = -v1;
	EXPECT_FLOAT_EQ(v2.x, -5);
	EXPECT_FLOAT_EQ(v2.y, 6);
	EXPECT_FLOAT_EQ(v2.z, -7.7f);
}

TEST(Vec3Test, TimesScalar)
{
	constexpr Vec3 v1{1, 1, 1};
	const Vec3 v2 = v1 * 5;
	EXPECT_FLOAT_EQ(v2.x, 5);
	EXPECT_FLOAT_EQ(v2.y, 5);
	EXPECT_FLOAT_EQ(v2.z, 5);
}

TEST(Vec3Test, ScalarTimesVec)
{
	constexpr Vec3 v1{1, 1, 1};
	const Vec3 v2 = 5 * v1;
	EXPECT_FLOAT_EQ(v2.x, 5);
	EXPECT_FLOAT_EQ(v2.y, 5);
	EXPECT_FLOAT_EQ(v2.z, 5);
}

TEST(Vec3Test, DivideScalar)
{
	constexpr Vec3 v1{5, 5, 5};
	const Vec3 v2 = v1 / 5;
	EXPECT_FLOAT_EQ(v2.x, 1);
	EXPECT_FLOAT_EQ(v2.y, 1);
	EXPECT_FLOAT_EQ(v2.z, 1);
}
}
