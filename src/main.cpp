#include <raylib-cpp.hpp>
#include <spdlog/spdlog.h>
#include <vector>

#include "math/Vec2.hpp"
#include "Planet.hpp"
#include "PlanetSystem.hpp"

constexpr std::int32_t WINDOW_WIDTH = 1000;
constexpr std::int32_t WINDOW_HEIGHT = 650;

int main()
{
	spdlog::set_level(spdlog::level::debug);

	raylib::Window window{WINDOW_WIDTH, WINDOW_HEIGHT, "planets go zoing"};
	window.SetState(FLAG_WINDOW_RESIZABLE);
	window.Maximize();

	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

	stw::Vec2 windowSizeFloat{static_cast<float>(window.GetWidth()), static_cast<float>(window.GetHeight())};
	const auto sunPos = stw::Vec2(windowSizeFloat / 2.0f);
	constexpr float sunMass = 100000000000000.0f;
	constexpr std::size_t planetAmount = 12000;
	stw::PlanetSystem ps{planetAmount, sunPos, sunMass};

	float deltaTime;
	while (!window.ShouldClose())    // Detect window close button or ESC key
	{
		deltaTime = GetFrameTime();
		window.BeginDrawing();

		window.ClearBackground(BLACK);

		window.DrawFPS();

		ps.Update(deltaTime);
		ps.Draw();

		window.EndDrawing();
	}
}
