#pragma once

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
