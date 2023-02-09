#include <spdlog/spdlog.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>

#include "PlanetSystem.hpp"
#include "math/Vec2.hpp"
#include "FpsCounter.hpp"

constexpr std::int64_t WINDOW_SCALE = 100;
constexpr std::int64_t WINDOW_WIDTH = 16 * WINDOW_SCALE;
constexpr std::int64_t WINDOW_HEIGHT = 9 * WINDOW_SCALE;
constexpr float CAM_SCALE = 100.0f;
constexpr float CAM_WIDTH = 16.0f * CAM_SCALE;
constexpr float CAM_HEIGHT = 9.0f * CAM_SCALE;

constexpr float VIEW_RATIO = CAM_SCALE / WINDOW_SCALE;

const sf::Vector2f CAM_SIZE{ CAM_WIDTH, CAM_HEIGHT };

int main()
{
	spdlog::set_level(spdlog::level::debug);

	sf::RenderWindow window{ sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "planets go zoing" };
	const sf::View defaultView(sf::Vector2f(0, 0), CAM_SIZE);
	window.setView(defaultView);
	sf::Font lModern;
	sf::Text fpsText;

	if (!lModern.loadFromFile("data/lmodern.otf"))
	{
		spdlog::error("Could not load lmodern font");
	}

	fpsText.setFont(lModern);
	fpsText.setCharacterSize(256);
	fpsText.setFillColor(sf::Color::White);
	fpsText.setPosition(-CAM_WIDTH / 2.0f, -CAM_HEIGHT / 2.0f);
	fpsText.setScale(0.3f, 0.3f);
	fpsText.setOutlineColor(sf::Color::Black);
	fpsText.setOutlineThickness(6.0f);

	FpsCounter fpsCounter;

	constexpr float sunMass = 100000000000000.0f;
	constexpr std::size_t planetAmount = 10'000;
	stw::PlanetSystem ps{ planetAmount, {0, 0}, sunMass };

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		sf::Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::Resized)
			{
				sf::Vector2f windowSize = {
					static_cast<float>(event.size.width) * VIEW_RATIO,
					static_cast<float>(event.size.height) * VIEW_RATIO
				};

				window.setView(sf::View({ 0,0 }, windowSize));
			}
		}

		fpsCounter.Update(deltaTime.asSeconds());
		fpsText.setString(fpsCounter.GetFpsString());

		window.clear(sf::Color::Black);

		ps.Update(deltaTime.asSeconds());
		ps.Draw(window);

		window.draw(fpsText);

		window.display();
	}
}
