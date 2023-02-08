#pragma once
#include <array>
#include <span>

#include "intrinsics.hpp"
#include "Utils.hpp"

namespace stw
{
template<std::size_t N>
struct alignas(N * sizeof(float)) Vec2xN
{
public:
	constexpr Vec2xN() = default;

	constexpr Vec2xN(const std::array<float, N>& x, const std::array<float, N>& y) : m_X(x), m_Y(y) {}

	constexpr std::span<float, N> GetX() { return m_X; }
	constexpr std::span<float, N> GetY() { return m_Y; }
	constexpr float AtX(std::size_t i) { return m_X[i]; }
	constexpr float AtY(std::size_t i) { return m_Y[i]; }
	// ReSharper disable once CppMemberFunctionMayBeStatic
	constexpr std::size_t size() { return N; }
	static constexpr Vec2xN<N> NewRandom()
	{
		Vec2xN<N> vec;
		for (std::size_t i = 0; i < N; ++i)
		{
			vec.m_X[i] = RandomRange(-100.0f, 100.0f);
			vec.m_Y[i] = RandomRange(-100.0f, 100.0f);
		}

		return vec;
	}


	Vec2xN operator*=(float scalar)
	{
		for (std::size_t i = 0; i < N; ++i)
		{
			m_X[i] *= scalar;
			m_Y[i] *= scalar;
		}
		return *this;
	}

private:
	std::array<float, N> m_X{};
	std::array<float, N> m_Y{};
};

using Vec2x4 = Vec2xN<4>;
using Vec2x8 = Vec2xN<8>;

#ifdef __SSE__
template<>
inline Vec2x4 Vec2x4::operator*=(float scalar)
{
	const auto scalarMm = _mm_load1_ps(&scalar);

	auto x = _mm_load_ps(m_X.data());
	auto y = _mm_load_ps(m_Y.data());

	x = _mm_mul_ps(x, scalarMm);
	y = _mm_mul_ps(y, scalarMm);

	_mm_store_ps(m_X.data(), x);
	_mm_store_ps(m_Y.data(), y);

	return *this;
}
#endif

#ifdef __AVX__
template<>
inline Vec2x8 Vec2x8::operator*=(float scalar)
{
	const auto scalarMm = _mm256_broadcast_ss(&scalar);

	auto x = _mm256_load_ps(m_X.data());
	auto y = _mm256_load_ps(m_Y.data());

	x = _mm256_mul_ps(x, scalarMm);
	y = _mm256_mul_ps(y, scalarMm);

	_mm256_store_ps(m_X.data(), x);
	_mm256_store_ps(m_Y.data(), y);

	return *this;
}
#endif
}
