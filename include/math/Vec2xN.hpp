#pragma once
#include <array>
#include <cassert>
#include <span>
#include <valarray>

#include "intrinsics.hpp"
#include "Utils.hpp"
#include "Vec2.hpp"

namespace stw
{
template<std::size_t N>
struct alignas(N * sizeof(float)) Vec2xN
{
public:
	constexpr Vec2xN() = default;

	constexpr Vec2xN(const std::array<float, N>& x, const std::array<float, N>& y) : m_X(x), m_Y(y) {}

	explicit constexpr Vec2xN(Vec2 vec)
	{
		for (std::size_t i = 0; i < N; ++i)
		{
			m_X[i] = vec.x;
			m_Y[i] = vec.y;
		}
	}

	constexpr std::span<float, N> GetX() { return m_X; }
	constexpr std::span<float, N> GetY() { return m_Y; }
	[[nodiscard]] constexpr float AtX(std::size_t i) const { return m_X[i]; }
	[[nodiscard]] constexpr float AtY(std::size_t i) const { return m_Y[i]; }

	static constexpr Vec2xN<N> NewRandom();
	[[nodiscard]] std::array<float, N> Magnitudes() const;
	[[nodiscard]] constexpr Vec2xN<N> PositivePerpendicular() const;

	// ReSharper disable once CppMemberFunctionMayBeStatic
	constexpr std::size_t size() { return N; }
	void Reset();

	Vec2xN operator*=(float scalar);
	Vec2xN operator*(float scalar) const;
	Vec2xN operator*(const Vec2xN& other) const;
	Vec2xN operator*(const std::valarray<float>& valarray) const;
	Vec2xN operator-(const Vec2xN& other) const;
	Vec2xN operator+(const Vec2xN& other) const;
	Vec2xN operator/(const std::valarray<float>& valarray) const;
	Vec2xN operator/(const std::array<float, N>& array) const;
	Vec2xN operator+=(const Vec2xN& other);

private:
	std::array<float, N> m_X{};
	std::array<float, N> m_Y{};
};

template <std::size_t N>
constexpr Vec2xN<N> Vec2xN<N>::NewRandom()
{
	Vec2xN<N> vec;
	for (std::size_t i = 0; i < N; ++i)
	{
		vec.m_X[i] = RandomRange(-100.0f, 100.0f);
		vec.m_Y[i] = RandomRange(-100.0f, 100.0f);
	}

	return vec;
}

template <std::size_t N>
constexpr Vec2xN<N> Vec2xN<N>::PositivePerpendicular() const
{
	Vec2xN<N> vec{};
	for (std::size_t i = 0; i < N; ++i)
	{
		vec.m_X[i] = -m_Y[i];
		vec.m_Y[i] = m_X[i];
	}

	return vec;
}

template <std::size_t N>
std::array<float, N> Vec2xN<N>::Magnitudes() const
{
	std::array<float, N> magnitudes{};
	for (std::size_t i = 0; i < N; ++i)
	{
		magnitudes[i] = std::sqrt(m_X[i] * m_X[i] + m_Y[i] * m_Y[i]);
	}

	return magnitudes;
}

template <std::size_t N>
void Vec2xN<N>::Reset()
{
	for (std::size_t i = 0; i < N; ++i)
	{
		m_X[i] = 0;
		m_Y[i] = 0;
	}
}

template<std::size_t N>
Vec2xN<N> Vec2xN<N>::operator*=(float scalar)
{
	for (std::size_t i = 0; i < N; ++i)
	{
		m_X[i] *= scalar;
		m_Y[i] *= scalar;
	}
	return *this;
}

template <std::size_t N>
Vec2xN<N> Vec2xN<N>::operator*(float scalar) const
{
	Vec2xN<N> vec{};
	for (std::size_t i = 0; i < N; ++i)
	{
		vec.m_X[i] = m_X[i] * scalar;
		vec.m_Y[i] = m_Y[i] * scalar;
	}

	return vec;
}

template <std::size_t N>
Vec2xN<N> Vec2xN<N>::operator*(const Vec2xN& other) const
{
	Vec2xN<N> vec{};
	for (std::size_t i = 0; i < N; ++i)
	{
		vec.m_X[i] = m_X[i] * other.m_X[i];
		vec.m_Y[i] = m_Y[i] * other.m_Y[i];
	}

	return vec;
}

template <std::size_t N>
Vec2xN<N> Vec2xN<N>::operator*(const std::valarray<float>& valarray) const
{
	assert(valarray.size() == N);
	Vec2xN<N> vec{};
	for (std::size_t i = 0; i < N; ++i)
	{
		vec.m_X[i] = m_X[i] * valarray[i];
		vec.m_Y[i] = m_Y[i] * valarray[i];
	}

	return vec;
}

template <std::size_t N>
Vec2xN<N> Vec2xN<N>::operator-(const Vec2xN& other) const
{
	Vec2xN<N> vec{};
	for (std::size_t i = 0; i < N; ++i)
	{
		vec.m_X[i] = m_X[i] - other.m_X[i];
		vec.m_Y[i] = m_Y[i] - other.m_Y[i];
	}

	return vec;
}

template <std::size_t N>
Vec2xN<N> Vec2xN<N>::operator+(const Vec2xN& other) const
{
	Vec2xN<N> vec{};
	for (std::size_t i = 0; i < N; ++i)
	{
		vec.m_X[i] = m_X[i] + other.m_X[i];
		vec.m_Y[i] = m_Y[i] + other.m_Y[i];
	}

	return vec;
}

template <std::size_t N>
Vec2xN<N> Vec2xN<N>::operator/(const std::valarray<float>& valarray) const
{
	assert(valarray.size() == N);
	Vec2xN<N> vec{};
	for (std::size_t i = 0; i < N; ++i)
	{
		vec.m_X[i] = m_X[i] / valarray[i];
		vec.m_Y[i] = m_Y[i] / valarray[i];
	}

	return vec;
}

template <std::size_t N>
Vec2xN<N> Vec2xN<N>::operator/(const std::array<float, N>& array) const
{
	Vec2xN<N> vec{};
	for (std::size_t i = 0; i < N; ++i)
	{
		vec.m_X[i] = m_X[i] / array[i];
		vec.m_Y[i] = m_Y[i] / array[i];
	}

	return vec;
}

template <std::size_t N>
Vec2xN<N> Vec2xN<N>::operator+=(const Vec2xN& other)
{
	for (std::size_t i = 0; i < N; ++i)
	{
		m_X[i] += other.m_X[i];
		m_Y[i] += other.m_Y[i];
	}

	return (*this);
}

using Vec2x4 = Vec2xN<4>;
using Vec2x8 = Vec2xN<8>;

#ifdef __SSE__
template<>
inline Vec2x4 Vec2x4::operator*=(const float scalar)
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
