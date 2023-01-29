//
// Created by stowy on 29/01/2023.
//

#include <iostream>
#include <raylib-cpp.hpp>
#include "Vec2.hpp"

void UpdateDrawFrame();

int main()
{
	raylib::Window window(800, 450, "raylib-cpp [core] example - basic window");
	SetTargetFPS(60);

	while (!window.ShouldClose())    // Detect window close button or ESC key
	{
		UpdateDrawFrame();
	}
}

void UpdateDrawFrame()
{
	BeginDrawing();

	ClearBackground(BLACK);

	DrawText("Congrats! You created your first raylib-cpp window!", 190, 200, 20, LIGHTGRAY);

	EndDrawing();
}
