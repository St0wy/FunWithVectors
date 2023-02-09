#include <raylib-cpp.hpp>
#include <spdlog/spdlog.h>

#include "SimdPlanetSystem.hpp"
#include "math/Vec2.hpp"

constexpr std::int32_t WINDOW_WIDTH = 1000;
constexpr std::int32_t WINDOW_HEIGHT = 650;

int main()
{
	spdlog::set_level(spdlog::level::debug);

	raylib::Window window{ WINDOW_WIDTH, WINDOW_HEIGHT, "planets go zoing" };
	window.SetState(FLAG_WINDOW_RESIZABLE);
	window.Maximize();

	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

	const stw::Vec2 windowSizeFloat{ static_cast<float>(window.GetWidth()),
							  static_cast<float>(window.GetHeight()) };
	const auto sunPos = stw::Vec2(windowSizeFloat / 2.0f);
	constexpr std::size_t planetAmount = 10'000;
	stw::SimdPlanetSystem<8> ps{ planetAmount, sunPos };
	ps.SetupSpeeds();

	while (!window.ShouldClose()) // Detect window close button or ESC key
	{
		const float deltaTime = GetFrameTime();
		window.BeginDrawing();

		window.ClearBackground(BLACK);

		window.DrawFPS();

		ps.Update(deltaTime);
		ps.Draw();

		window.EndDrawing();
	}
}
