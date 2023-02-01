//
// Created by stowy on 29/01/2023.
//

#include <raylib-cpp.hpp>
#include "Vec2.hpp"

constexpr std::int32_t WINDOW_WIDTH = 1000;
constexpr std::int32_t WINDOW_HEIGHT = 650;

int main()
{
	raylib::Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "planets go zoing");
	raylib::Texture sun("data/Sun.png");
	raylib::Texture planet("data/Planet.png");

	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

	constexpr float sunScale = 0.3f;
	const float width = static_cast<float>(sun.GetWidth());
	const float height = static_cast<float>(sun.GetHeight());

	auto sunPos = stw::Vec2((WINDOW_WIDTH / 2.0f - width * sunScale / 2.0f),
							(WINDOW_HEIGHT / 2.0f - height * sunScale / 2.0f));
	constexpr float planetScale = 0.2f;
	constexpr float planetSpeed = 5.0f;
	constexpr float planetDistance = 300.0f;
	stw::Vec2 planetPos{600, 170};
	float planetAngle = 0.0f;

	float deltaTime;
	while (!window.ShouldClose())    // Detect window close button or ESC key
	{
		deltaTime = GetFrameTime();
		BeginDrawing();

		ClearBackground(BLACK);

		planetAngle += planetSpeed * deltaTime;

		DrawText("Moi j'aime les planètes.", 0, 0, 20, LIGHTGRAY);

		sun.Draw(sunPos, 0.0f, sunScale);

		planetPos.x = std::cos(planetAngle) * planetDistance;
		planetPos.y = std::sin(planetAngle) * planetDistance;
		planetPos += sunPos;
		planet.Draw(planetPos, 0.0f, planetScale);

		EndDrawing();
	}
}
