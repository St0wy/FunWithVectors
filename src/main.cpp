//
// Created by stowy on 29/01/2023.
//

#include <iostream>
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

	stw::Vec2 planetPos{600, 170};

	while (!window.ShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();

		ClearBackground(BLACK);

		DrawText("Moi j'aime les planètes.", 0, 0, 20, LIGHTGRAY);

		constexpr float scale = 0.2f;
		raylib::Vector2 pos = raylib::Vector2((WINDOW_WIDTH / 2.0f - sun.GetWidth() * scale / 2.0f),
											  (WINDOW_HEIGHT / 2.0f - sun.GetHeight() * scale / 2.0f));
		sun.Draw(pos, 0.0f, scale);
		planet.Draw({planetPos.x, planetPos.y}, 0.0f, scale);

		EndDrawing();
	}
}
