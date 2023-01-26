#include "Vec2.hpp"

#include <format>

#include "gtest/gtest.h"

std::string Vec2::ToString() const
{
	return std::format("[{}, {}]", x, y);
}

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions)
{
	constexpr Vec2 v = {1.0f, 2.0f};
	const std::string val = "[1, 2]";

	// Expect two strings not to be equal.
	EXPECT_EQ(v.ToString(), val);

	// Expect equality.
	EXPECT_EQ(7 * 6, 42);
}
