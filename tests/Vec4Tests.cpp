#include "Vec4.hpp"

#include "gtest/gtest.h"
#include <numbers>

namespace stw
{
TEST(Vec4Test, DefaultConstructsWithZero)
{
	constexpr Vec4 v{};
	EXPECT_EQ(v.x, 0);
	EXPECT_EQ(v.y, 0);
	EXPECT_EQ(v.z, 0);
	EXPECT_EQ(v.w, 0);
}

TEST(Vec4Test, Constructor)
{
	constexpr Vec4 v{-10, 42, 6.66, 1};
	EXPECT_EQ(v.x, -10);
	EXPECT_EQ(v.y, 42);
	EXPECT_EQ(v.z, 6.66f);
	EXPECT_EQ(v.w, 1.0f);
}

TEST(Vec4Test, ZeroIsZero)
{
	constexpr Vec4 v = Vec4::Zero();
	EXPECT_EQ(v.x, 0);
	EXPECT_EQ(v.y, 0);
	EXPECT_EQ(v.z, 0);
	EXPECT_EQ(v.w, 0);
}

TEST(Vec4Test, Lerp)
{
	constexpr Vec4 v{};
	constexpr Vec4 v2{2, 2, 2, 2};
	constexpr auto vLerp = Vec4::Lerp(v, v2, 0.5f);
	EXPECT_FLOAT_EQ(vLerp.x, 1.0f);
	EXPECT_FLOAT_EQ(vLerp.y, 1.0f);
	EXPECT_FLOAT_EQ(vLerp.z, 1.0f);
	EXPECT_FLOAT_EQ(vLerp.w, 1.0f);
}

TEST(Vec4Test, LerpNegative)
{
	constexpr Vec4 v{};
	constexpr Vec4 v2{-2, -2, -2, -2};
	const auto vLerp = Vec4::Lerp(v, v2, 0.5f);
	EXPECT_FLOAT_EQ(vLerp.x, -1.0f);
	EXPECT_FLOAT_EQ(vLerp.y, -1.0f);
	EXPECT_FLOAT_EQ(vLerp.z, -1.0f);
	EXPECT_FLOAT_EQ(vLerp.w, -1.0f);
}

TEST(Vec4Test, LerpMoreThanOne)
{
	constexpr Vec4 v{};
	constexpr Vec4 v2{2, 2, 2, 2};
	const auto vLerp = Vec4::Lerp(v, v2, 2.0f);
	EXPECT_FLOAT_EQ(vLerp.x, 2.0f);
	EXPECT_FLOAT_EQ(vLerp.y, 2.0f);
	EXPECT_FLOAT_EQ(vLerp.z, 2.0f);
	EXPECT_FLOAT_EQ(vLerp.w, 2.0f);
}

TEST(Vec4Test, LerpLessThanZero)
{
	constexpr Vec4 v{1, 1, 1, 1};
	constexpr Vec4 v2{2, 2, 2, 2};
	const auto vLerp = Vec4::Lerp(v, v2, -1.0f);
	EXPECT_FLOAT_EQ(vLerp.x, 1.0f);
	EXPECT_FLOAT_EQ(vLerp.y, 1.0f);
	EXPECT_FLOAT_EQ(vLerp.z, 1.0f);
	EXPECT_FLOAT_EQ(vLerp.w, 1.0f);
}

TEST(Vec4Test, MagnitudeTwoZeros)
{
	constexpr Vec4 v{3, 0, 0, 0};
	EXPECT_FLOAT_EQ(v.Magnitude(), 3.0f);
}

TEST(Vec4Test, MagnitudeNoZero)
{
	constexpr Vec4 v{3, 5, 6.2f, -5.0f};
	EXPECT_FLOAT_EQ(v.Magnitude(), 9.87117f);
}

TEST(Vec4Test, SqrMagnitude)
{
	constexpr Vec4 v{3, 5, 6.2f, -5.0f};
	EXPECT_FLOAT_EQ(v.SqrMagnitude(), 97.440002f);
}

TEST(Vec4Test, Normalized)
{
	constexpr Vec4 v{1, 2, 2, 2};
	const Vec4 norm = v.Normalized();
	EXPECT_FLOAT_EQ(norm.x,0.2773501f);
	EXPECT_FLOAT_EQ(norm.y, 0.5547002);
	EXPECT_FLOAT_EQ(norm.z, 0.5547002);
	EXPECT_FLOAT_EQ(norm.w, 0.5547002);
}

TEST(Vec4Test, NormalizedZeroXZW)
{
	constexpr Vec4 v{0, 2, 0, 0};
	const Vec4 norm = v.Normalized();
	EXPECT_FLOAT_EQ(norm.x, 0.0f);
	EXPECT_FLOAT_EQ(norm.y, 1.0f);
	EXPECT_FLOAT_EQ(norm.z, 0.0f);
	EXPECT_FLOAT_EQ(norm.w, 0.0f);
}

TEST(Vec4Test, NormalizedZeroXY)
{
	constexpr Vec4 v{0, 0, 2.0f, 0};
	const Vec4 norm = v.Normalized();
	EXPECT_FLOAT_EQ(norm.x, 0.0f);
	EXPECT_FLOAT_EQ(norm.y, 0.0f);
	EXPECT_FLOAT_EQ(norm.z, 1.0f);
	EXPECT_FLOAT_EQ(norm.w, 0.0f);
}

TEST(Vec4Test, NormalizedZeroXYZW)
{
	constexpr Vec4 v{0, 0, 0, 0};
	const Vec4 norm = v.Normalized();
	EXPECT_FLOAT_EQ(norm.x, 0.0f);
	EXPECT_FLOAT_EQ(norm.y, 0.0f);
	EXPECT_FLOAT_EQ(norm.z, 0.0f);
	EXPECT_FLOAT_EQ(norm.w, 0.0f);
}

TEST(Vec4Test, Dot)
{
	constexpr Vec4 v1{2, 3, 2, -3};
	constexpr Vec4 v2{1, 3, -7.6, 29.02};
	const float dot = v1.Dot(v2);
	EXPECT_FLOAT_EQ(dot, -91.259995);
}

TEST(Vec4Test, Distance)
{
	constexpr Vec4 v1{0, 5, 0, 0};
	constexpr Vec4 v2{0, 0, 0, 0};
	const float dist = v1.Distance(v2);
	EXPECT_FLOAT_EQ(dist, 5);
}

TEST(Vec4Test, MajorX)
{
	constexpr Vec4 v{5, 1, 2, -10};
	const float major = v.Major();
	EXPECT_EQ(major, 5.0f);
	EXPECT_NE(major, 1.0f);
	EXPECT_NE(major, 2.0f);
	EXPECT_NE(major, -10.0f);
}

TEST(Vec4Test, MajorY)
{
	constexpr Vec4 v{1, 5, 2, -10};
	const float major = v.Major();
	EXPECT_EQ(major, 5.0f);
	EXPECT_NE(major, 1.0f);
	EXPECT_NE(major, 2.0f);
	EXPECT_NE(major, -10.0f);
}

TEST(Vec4Test, MajorW)
{
	constexpr Vec4 v{1, 5, 2, 10};
	const float major = v.Major();
	EXPECT_EQ(major, 10.0f);
	EXPECT_NE(major, 1.0f);
	EXPECT_NE(major, 2.0f);
	EXPECT_NE(major, 5.0f);
}

TEST(Vec4Test, NewMagnitude)
{
	constexpr Vec4 v{1, 0, 0, 0};
	const Vec4 v2 = v.NewMagnitude(5);
	EXPECT_EQ(v2.x, 5.0f);
	EXPECT_EQ(v2.y, 0.0f);
	EXPECT_EQ(v2.z, 0.0f);
	EXPECT_EQ(v2.w, 0.0f);
	EXPECT_FLOAT_EQ(v2.Magnitude(), 5.0f);
}

TEST(Vec4Test, ToString)
{
	constexpr Vec4 v{1, 0, 2, -10};
	EXPECT_EQ(v.ToString(), "[1, 0, 2, -10]");
}

TEST(Vec4Test, Add)
{
	constexpr Vec4 v1{1, 1, 1, 1};
	const Vec4 v2 = v1 + v1;
	EXPECT_FLOAT_EQ(v2.x, 2);
	EXPECT_FLOAT_EQ(v2.y, 2);
	EXPECT_FLOAT_EQ(v2.z, 2);
	EXPECT_FLOAT_EQ(v2.w, 2);
}

TEST(Vec4Test, Sub)
{
	constexpr Vec4 v1{1, 1, 1, 1};
	const Vec4 v2 = v1 - v1;
	EXPECT_FLOAT_EQ(v2.x, 0);
	EXPECT_FLOAT_EQ(v2.y, 0);
	EXPECT_FLOAT_EQ(v2.z, 0);
	EXPECT_FLOAT_EQ(v2.w, 0);
}

TEST(Vec4Test, AddEqual)
{
	Vec4 v1{1, 1, 1, 1};
	v1 += v1;
	EXPECT_FLOAT_EQ(v1.x, 2);
	EXPECT_FLOAT_EQ(v1.y, 2);
	EXPECT_FLOAT_EQ(v1.z, 2);
	EXPECT_FLOAT_EQ(v1.w, 2);
}

TEST(Vec4Test, SubEqual)
{
	constexpr Vec4 v1{1, 1, 1, 1};
	Vec4 v2{2, 2, 2, 2};
	v2 -= v1;
	EXPECT_FLOAT_EQ(v2.x, 1);
	EXPECT_FLOAT_EQ(v2.y, 1);
	EXPECT_FLOAT_EQ(v2.z, 1);
	EXPECT_FLOAT_EQ(v2.w, 1);
}

TEST(Vec4Test, TimesEqualScalar)
{
	Vec4 v1{1, 1, 1, 1};
	v1 *= 5.0f;
	EXPECT_FLOAT_EQ(v1.x, 5);
	EXPECT_FLOAT_EQ(v1.y, 5);
	EXPECT_FLOAT_EQ(v1.z, 5);
	EXPECT_FLOAT_EQ(v1.w, 5);
}

TEST(Vec4Test, DivideEqualScalar)
{
	Vec4 v1{5, 5, 5, 5};
	v1 /= 2.0f;
	EXPECT_FLOAT_EQ(v1.x, 2.5f);
	EXPECT_FLOAT_EQ(v1.y, 2.5f);
	EXPECT_FLOAT_EQ(v1.z, 2.5f);
	EXPECT_FLOAT_EQ(v1.w, 2.5f);
}

TEST(Vec4Test, EqualTrue)
{
	constexpr Vec4 v1{5, 5, 5, 5};
	constexpr Vec4 v2{5, 5, 5, 5};
	EXPECT_TRUE(v1 == v2);
}

TEST(Vec4Test, EqualFalse)
{
	constexpr Vec4 v1{5, 5, 5, 5};
	constexpr Vec4 v2{5, 5, 5, 0};
	EXPECT_FALSE(v1 == v2);
}

TEST(Vec4Test, Negative)
{
	constexpr Vec4 v1{5, -6, 7.7f, 1};
	const Vec4 v2 = -v1;
	EXPECT_FLOAT_EQ(v2.x, -5);
	EXPECT_FLOAT_EQ(v2.y, 6);
	EXPECT_FLOAT_EQ(v2.z, -7.7f);
	EXPECT_FLOAT_EQ(v2.w, -1);
}

TEST(Vec4Test, TimesScalar)
{
	constexpr Vec4 v1{1, 1, 1, 1};
	const Vec4 v2 = v1 * 5;
	EXPECT_FLOAT_EQ(v2.x, 5);
	EXPECT_FLOAT_EQ(v2.y, 5);
	EXPECT_FLOAT_EQ(v2.z, 5);
	EXPECT_FLOAT_EQ(v2.w, 5);
}

TEST(Vec4Test, ScalarTimesVec)
{
	constexpr Vec4 v1{1, 1, 1, 1};
	const Vec4 v2 = 5 * v1;
	EXPECT_FLOAT_EQ(v2.x, 5);
	EXPECT_FLOAT_EQ(v2.y, 5);
	EXPECT_FLOAT_EQ(v2.z, 5);
	EXPECT_FLOAT_EQ(v2.w, 5);
}

TEST(Vec4Test, DivideScalar)
{
	constexpr Vec4 v1{5, 5, 5, 5};
	const Vec4 v2 = v1 / 5;
	EXPECT_FLOAT_EQ(v2.x, 1);
	EXPECT_FLOAT_EQ(v2.y, 1);
	EXPECT_FLOAT_EQ(v2.z, 1);
	EXPECT_FLOAT_EQ(v2.w, 1);
}
}
