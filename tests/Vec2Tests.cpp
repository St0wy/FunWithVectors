#include "Vec2.hpp"

#include "gtest/gtest.h"
#include <numbers>

namespace stw
{
TEST(Vec2Test, DefaultConstructsWithZero)
{
	constexpr Vec2 v{};
	EXPECT_EQ(v.x, 0);
	EXPECT_EQ(v.y, 0);
}

TEST(Vec2Test, Constructor)
{
	constexpr Vec2 v{ -10, 42 };
	EXPECT_EQ(v.x, -10);
	EXPECT_EQ(v.y, 42);
}

TEST(Vec2Test, ZeroIsZero)
{
	constexpr Vec2 v = Vec2::Zero();
	EXPECT_EQ(v.x, 0);
	EXPECT_EQ(v.y, 0);
}

TEST(Vec2Test, Lerp)
{
	constexpr Vec2 v{};
	constexpr Vec2 v2{ 2, 2 };
	const auto vLerp = Vec2::Lerp(v, v2, 0.5f);
	EXPECT_FLOAT_EQ(vLerp.x, 1.0f);
	EXPECT_FLOAT_EQ(vLerp.y, 1.0f);
}

TEST(Vec2Test, LerpNegative)
{
	constexpr Vec2 v{};
	constexpr Vec2 v2{ -2, -2 };
	const auto vLerp = Vec2::Lerp(v, v2, 0.5f);
	EXPECT_FLOAT_EQ(vLerp.x, -1.0f);
	EXPECT_FLOAT_EQ(vLerp.y, -1.0f);
}

TEST(Vec2Test, LerpMoreThanOne)
{
	constexpr Vec2 v{};
	constexpr Vec2 v2{ 2, 2 };
	const auto vLerp = Vec2::Lerp(v, v2, 2.0f);
	EXPECT_FLOAT_EQ(vLerp.x, 2.0f);
	EXPECT_FLOAT_EQ(vLerp.y, 2.0f);
}

TEST(Vec2Test, LerpLessThanZero)
{
	constexpr Vec2 v{ 1, 1 };
	constexpr Vec2 v2{ 2, 2 };
	const auto vLerp = Vec2::Lerp(v, v2, -1.0f);
	EXPECT_FLOAT_EQ(vLerp.x, 1.0f);
	EXPECT_FLOAT_EQ(vLerp.y, 1.0f);
}

TEST(Vec2Test, MagnitudeOneZero)
{
	constexpr Vec2 v{ 3, 0 };
	EXPECT_FLOAT_EQ(v.Magnitude(), 3.0f);
}


TEST(Vec2Test, MagnitudeNoZero)
{
	constexpr Vec2 v{ 3, 5 };
	EXPECT_FLOAT_EQ(v.Magnitude(), 5.8309518948f);
}

TEST(Vec2Test, SqrMagnitude)
{
	constexpr Vec2 v{ 3, 5 };
	EXPECT_FLOAT_EQ(v.SqrMagnitude(), 34);
}

TEST(Vec2Test, Normalized)
{
	constexpr Vec2 v{ 1, 2 };
	const Vec2 norm = v.Normalized();
	EXPECT_FLOAT_EQ(norm.x, 0.44721359f);
	EXPECT_FLOAT_EQ(norm.y, 0.89442718f);
}

TEST(Vec2Test, NormalizedZeroX)
{
	constexpr Vec2 v{ 0, 2 };
	const Vec2 norm = v.Normalized();
	EXPECT_FLOAT_EQ(norm.x, 0.0f);
	EXPECT_FLOAT_EQ(norm.y, 1.0f);
}

TEST(Vec2Test, NormalizedZeroY)
{
	constexpr Vec2 v{ 2, 0 };
	const Vec2 norm = v.Normalized();
	EXPECT_FLOAT_EQ(norm.x, 1.0f);
	EXPECT_FLOAT_EQ(norm.y, 0.0f);
}

TEST(Vec2Test, NormalizedZeroXY)
{
	constexpr Vec2 v{ 0, 0 };
	const Vec2 norm = v.Normalized();
	EXPECT_FLOAT_EQ(norm.x, 0.0f);
	EXPECT_FLOAT_EQ(norm.y, 0.0f);
}

TEST(Vec2Test, Dot)
{
	constexpr Vec2 v1{ 2, 3 };
	constexpr Vec2 v2{ 1, 3 };
	const float dot = v1.Dot(v2);
	EXPECT_FLOAT_EQ(dot, 11);
}

TEST(Vec2Test, Distance)
{
	constexpr Vec2 v1{ 0, 5 };
	constexpr Vec2 v2{ 0, 0 };
	const float dist = v1.Distance(v2);
	EXPECT_FLOAT_EQ(dist, 5);
}

TEST(Vec2Test, Angle)
{
	constexpr Vec2 v1{ 0, 5 };
	constexpr Vec2 v2{ 0, 0 };
	const float angle = v1.Angle(v2);
	EXPECT_FLOAT_EQ(angle, std::numbers::pi_v<float> / 2.0f);
}

TEST(Vec2Test, MajorX)
{
	constexpr Vec2 v{ 5, 1 };
	const float major = v.Major();
	EXPECT_EQ(major, 5.0f);
	EXPECT_NE(major, 1.0f);
}

TEST(Vec2Test, MajorY)
{
	constexpr Vec2 v{ 1, 5 };
	const float major = v.Major();
	EXPECT_EQ(major, 5.0f);
	EXPECT_NE(major, 1.0f);
}

TEST(Vec2Test, PositivePerpendicular)
{
	constexpr Vec2 v{ 1, 5 };
	const Vec2 pos = v.PositivePerpendicular();
	EXPECT_EQ(pos.x, -5.0f);
	EXPECT_EQ(pos.y, 1);
}

TEST(Vec2Test, NegativePerpendicular)
{
	constexpr Vec2 v{ 1, 5 };
	const Vec2 pos = v.NegativePerpendicular();
	EXPECT_EQ(pos.x, 5.0f);
	EXPECT_EQ(pos.y, -1.0f);
}

TEST(Vec2Test, NewMagnitude)
{
	constexpr Vec2 v{ 1, 0 };
	const Vec2 v2 = v.NewMagnitude(5);
	EXPECT_EQ(v2.x, 5.0f);
	EXPECT_EQ(v2.y, 0.0f);
}

TEST(Vec2Test, ToString)
{
	constexpr Vec2 v{ 1, 0 };
	EXPECT_EQ(v.ToString(), "[1, 0]");
}

TEST(Vec2Test, Add)
{
	constexpr Vec2 v1{ 1, 1 };
	const Vec2 v2 = v1 + v1;
	EXPECT_FLOAT_EQ(v2.x, 2);
	EXPECT_FLOAT_EQ(v2.y, 2);
}

TEST(Vec2Test, Sub)
{
	constexpr Vec2 v1{ 1, 1 };
	const Vec2 v2 = v1 - v1;
	EXPECT_FLOAT_EQ(v2.x, 0);
	EXPECT_FLOAT_EQ(v2.y, 0);
}

TEST(Vec2Test, AddEqual)
{
	Vec2 v1{ 1, 1 };
	v1 += v1;
	EXPECT_FLOAT_EQ(v1.x, 2);
	EXPECT_FLOAT_EQ(v1.y, 2);
}

TEST(Vec2Test, SubEqual)
{
	constexpr Vec2 v1{ 1, 1 };
	Vec2 v2{ 2, 2 };
	v2 -= v1;
	EXPECT_FLOAT_EQ(v2.x, 1);
	EXPECT_FLOAT_EQ(v2.y, 1);
}

TEST(Vec2Test, TimesEqualScalar)
{
	Vec2 v1{ 1, 1 };
	v1 *= 5.0f;
	EXPECT_FLOAT_EQ(v1.x, 5);
	EXPECT_FLOAT_EQ(v1.y, 5);
}

TEST(Vec2Test, DivideEqualScalar)
{
	Vec2 v1{ 5, 5 };
	v1 /= 2.0f;
	EXPECT_FLOAT_EQ(v1.x, 2.5f);
	EXPECT_FLOAT_EQ(v1.y, 2.5f);
}

TEST(Vec2Test, EqualTrue)
{
	constexpr Vec2 v1{ 5, 5 };
	constexpr Vec2 v2{ 5, 5 };
	EXPECT_TRUE(v1 == v2);
}

TEST(Vec2Test, EqualFalse)
{
	constexpr Vec2 v1{ 5, 5 };
	constexpr Vec2 v2{ 5, 0 };
	EXPECT_FALSE(v1 == v2);
}

TEST(Vec2Test, Negative)
{
	constexpr Vec2 v1{ 5, -6 };
	const Vec2 v2 = -v1;
	EXPECT_FLOAT_EQ(v2.x, -5);
	EXPECT_FLOAT_EQ(v2.y, 6);
}

TEST(Vec2Test, TimesScalar)
{
	constexpr Vec2 v1{ 1, 1 };
	const Vec2 v2 = v1 * 5;
	EXPECT_FLOAT_EQ(v2.x, 5);
	EXPECT_FLOAT_EQ(v2.y, 5);
}

TEST(Vec2Test, ScalarTimesVec)
{
	constexpr Vec2 v1{ 1, 1 };
	const Vec2 v2 = 5 * v1;
	EXPECT_FLOAT_EQ(v2.x, 5);
	EXPECT_FLOAT_EQ(v2.y, 5);
}

TEST(Vec2Test, DivideScalar)
{
	constexpr Vec2 v1{ 5, 5 };
	const Vec2 v2 = v1 / 5;
	EXPECT_FLOAT_EQ(v2.x, 1);
	EXPECT_FLOAT_EQ(v2.y, 1);
}
}
