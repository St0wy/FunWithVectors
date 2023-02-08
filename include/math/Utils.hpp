#pragma once

#include <raylib-cpp.hpp>
#include <xtr1common>
#include <random>

template<typename T>
std::enable_if_t<std::is_integral_v<T>, T> RandomRange(T start, T end)
{
	// Will be used to obtain a seed for the random number engine
	static std::random_device rd;
	// Standard mersenne_twister_engine seeded with rd()
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<T> dis(start, end);
	return dis(gen);
}

template<typename T>
std::enable_if_t<std::is_floating_point_v<T>, T> RandomRange(T start, T end)
{
	// Will be used to obtain a seed for the random number engine
	static std::random_device rd;
	// Standard mersenne_twister_engine seeded with rd()
	static std::mt19937 gen(rd());
	std::uniform_real_distribution<T> dis(start, end);
	return dis(gen);
}

inline bool RandomBool()
{
	return RandomRange<int>(0, 1) > 0;
}

inline raylib::Color GetRandomColor()
{
	const auto r = static_cast<unsigned char>(
		RandomRange(static_cast<unsigned short>(50), static_cast<unsigned short>(255)));
	const auto g = static_cast<unsigned char>(
		RandomRange(static_cast<unsigned short>(50), static_cast<unsigned short>(255)));
	const auto b = static_cast<unsigned char>(
		RandomRange(static_cast<unsigned short>(50), static_cast<unsigned short>(255)));
	return raylib::Color(r, g, b);
}