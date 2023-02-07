#include <gtest/gtest.h>

#include "math/Vec2xN.hpp"

namespace stw
{
TEST(Vec2xNTest, DefaultMultiplyWorks)
{
	Vec2xN<2> v{ {1, 1}, {2, 2} };
	v *= 4.0f;

	for (std::size_t i = 0; i < v.size(); ++i)
	{
		EXPECT_FLOAT_EQ(v.AtX(i), 4.0f);
		EXPECT_FLOAT_EQ(v.AtY(i), 8.0f);
	}
}

TEST(Vec2xNTest, FourMultiplyWorks)
{
	Vec2x4 v{ {1, 1, 1, 1}, {2, 2, 2, 2} };
	v *= 4.0f;

	for (std::size_t i = 0; i < v.size(); ++i)
	{
		EXPECT_FLOAT_EQ(v.AtX(i), 4.0f);
		EXPECT_FLOAT_EQ(v.AtY(i), 8.0f);
	}
}

TEST(Vec2xNTest, EightMultiplyWorks)
{
	Vec2x8 v{ {1, 1, 1, 1, 1, 1, 1, 1}, {2, 2, 2, 2, 2, 2, 2, 2} };
	v *= 4.0f;

	for (std::size_t i = 0; i < v.size(); ++i)
	{
		EXPECT_FLOAT_EQ(v.AtX(i), 4.0f);
		EXPECT_FLOAT_EQ(v.AtY(i), 8.0f);
	}
}
}
