#include <benchmark/benchmark.h>

#include "PlanetSystem.hpp"
#include "SimdPlanetSystem.hpp"

constexpr float DELTA_TIME = 1.0f / 60.0f;
constexpr std::int64_t MIN_PLANETS = 1;
constexpr std::int64_t MAX_PLANETS = 1 << 20;

static void BM_Planets(benchmark::State& state)
{
	const std::size_t planetsAmount = state.range(0);
	constexpr auto sunPos = stw::Vec2(0, 0);
	constexpr float sunMass = 100000000000000.0f;
	stw::PlanetSystem ps{ planetsAmount, sunPos, sunMass };

	for (auto _ : state)
	{
		ps.Update(DELTA_TIME);
	}
}
BENCHMARK(BM_Planets)->Range(MIN_PLANETS, MAX_PLANETS);

static void BM_PlanetsSIMDx4(benchmark::State& state)
{
	const std::size_t planetsAmount = state.range(0);
	constexpr auto sunPos = stw::Vec2(0, 0);
	stw::SimdPlanetSystem<4> ps{ planetsAmount, sunPos };

	for (auto _ : state)
	{
		ps.Update(DELTA_TIME);
	}
}
BENCHMARK(BM_PlanetsSIMDx4)->Range(MIN_PLANETS, MAX_PLANETS);

static void BM_PlanetsSIMDx8(benchmark::State& state)
{
	const std::size_t planetsAmount = state.range(0);
	constexpr auto sunPos = stw::Vec2(0, 0);
	stw::SimdPlanetSystem<8> ps{ planetsAmount, sunPos };

	for (auto _ : state)
	{
		ps.Update(DELTA_TIME);
	}
}
BENCHMARK(BM_PlanetsSIMDx8)->Range(MIN_PLANETS, MAX_PLANETS);

static void BM_PlanetsSIMDx16(benchmark::State& state)
{
	const std::size_t planetsAmount = state.range(0);
	constexpr auto sunPos = stw::Vec2(0, 0);
	stw::SimdPlanetSystem<16> ps{ planetsAmount, sunPos };

	for (auto _ : state)
	{
		ps.Update(DELTA_TIME);
	}
}
BENCHMARK(BM_PlanetsSIMDx16)->Range(MIN_PLANETS, MAX_PLANETS);

static void BM_PlanetsSIMDx32(benchmark::State& state)
{
	const std::size_t planetsAmount = state.range(0);
	constexpr auto sunPos = stw::Vec2(0, 0);
	stw::SimdPlanetSystem<32> ps{ planetsAmount, sunPos };

	for (auto _ : state)
	{
		ps.Update(DELTA_TIME);
	}
}
BENCHMARK(BM_PlanetsSIMDx32)->Range(MIN_PLANETS, MAX_PLANETS);

static void BM_PlanetsSIMDx64(benchmark::State& state)
{
	const std::size_t planetsAmount = state.range(0);
	constexpr auto sunPos = stw::Vec2(0, 0);
	stw::SimdPlanetSystem<64> ps{ planetsAmount, sunPos };

	for (auto _ : state)
	{
		ps.Update(DELTA_TIME);
	}
}
BENCHMARK(BM_PlanetsSIMDx64)->Range(MIN_PLANETS, MAX_PLANETS);

static void BM_PlanetsSIMDx128(benchmark::State& state)
{
	const std::size_t planetsAmount = state.range(0);
	constexpr auto sunPos = stw::Vec2(0, 0);
	stw::SimdPlanetSystem<128> ps{ planetsAmount, sunPos };

	for (auto _ : state)
	{
		ps.Update(DELTA_TIME);
	}
}
BENCHMARK(BM_PlanetsSIMDx128)->Range(MIN_PLANETS, MAX_PLANETS);

static void BM_PlanetsSIMDx256(benchmark::State& state)
{
	const std::size_t planetsAmount = state.range(0);
	constexpr auto sunPos = stw::Vec2(0, 0);
	stw::SimdPlanetSystem<256> ps{ planetsAmount, sunPos };

	for (auto _ : state)
	{
		ps.Update(DELTA_TIME);
	}
}
BENCHMARK(BM_PlanetsSIMDx256)->Range(MIN_PLANETS, MAX_PLANETS);

BENCHMARK_MAIN();
