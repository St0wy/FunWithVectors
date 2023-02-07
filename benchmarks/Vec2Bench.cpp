#include <vector>
#include <benchmark/benchmark.h>

#include "math/Vec2.hpp"
#include "math/Vec2xN.hpp"

constexpr std::size_t LENGTH = 2048;

static void BM_VectorMultiplyAOS(benchmark::State& state)
{
	std::vector<stw::Vec2> vectors;
	vectors.reserve(LENGTH);

	for (std::size_t i = 0; i < LENGTH; ++i)
	{
		vectors.emplace_back(rand(), rand());
	}

	for (auto _ : state)
	{
		for (auto& vec : vectors)
		{
			benchmark::DoNotOptimize(vec *= 6.66f);
		}
	}
}
BENCHMARK(BM_VectorMultiplyAOS);

static void BM_VectorMultiplySOA(benchmark::State& state)
{
	stw::Vec2xN<LENGTH> vectors;

	for (auto _ : state)
	{
		benchmark::DoNotOptimize(vectors *= 6.66f);
	}
}
BENCHMARK(BM_VectorMultiplySOA);


static void BM_VectorMultiplyAOSOAx4(benchmark::State& state)
{
	constexpr std::size_t len = LENGTH / 4;
	std::vector<stw::Vec2x4> vectors;
	vectors.reserve(len);

	for (std::size_t i = 0; i < len; ++i)
	{
		vectors.emplace_back();
	}

	for (auto _ : state)
	{
		for (auto& vec : vectors)
		{
			benchmark::DoNotOptimize(vec *= 6.66f);
		}
	}
}
BENCHMARK(BM_VectorMultiplyAOSOAx4);

static void BM_VectorMultiplyAOSOAx8(benchmark::State& state)
{
	constexpr std::size_t len = LENGTH / 8;
	std::vector<stw::Vec2x8> vectors;
	vectors.reserve(len);

	for (std::size_t i = 0; i < len; ++i)
	{
		vectors.emplace_back();
	}

	for (auto _ : state)
	{
		for (auto& vec : vectors)
		{
			benchmark::DoNotOptimize(vec *= 6.66f);
		}
	}
}
BENCHMARK(BM_VectorMultiplyAOSOAx8);

static void BM_VectorMultiplyAOSSize4(benchmark::State& state)
{
	std::vector<stw::Vec2> vectors;
	vectors.reserve(4);

	for (std::size_t i = 0; i < 4; ++i)
	{
		vectors.emplace_back(rand(), rand());
	}

	for (auto _ : state)
	{
		for (auto& vec : vectors)
		{
			benchmark::DoNotOptimize(vec *= 6.66f);
		}
	}
}
BENCHMARK(BM_VectorMultiplyAOSSize4);

static void BM_VectorMultiplySOASize4(benchmark::State& state)
{
	stw::Vec2x4 vectors;

	for (auto _ : state)
	{
		benchmark::DoNotOptimize(vectors *= 6.66f);
	}
}
BENCHMARK(BM_VectorMultiplySOASize4);

static void BM_VectorMultiplyAOSSize8(benchmark::State& state)
{
	std::vector<stw::Vec2> vectors;
	vectors.reserve(8);

	for (std::size_t i = 0; i < 8; ++i)
	{
		vectors.emplace_back(rand(), rand());
	}

	for (auto _ : state)
	{
		for (auto& vec : vectors)
		{
			benchmark::DoNotOptimize(vec *= 6.66f);
		}
	}
}
BENCHMARK(BM_VectorMultiplyAOSSize8);

static void BM_VectorMultiplySOASize8(benchmark::State& state)
{
	stw::Vec2x8 vectors;

	for (auto _ : state)
	{
		benchmark::DoNotOptimize(vectors *= 6.66f);
	}
}
BENCHMARK(BM_VectorMultiplySOASize8);

BENCHMARK_MAIN();