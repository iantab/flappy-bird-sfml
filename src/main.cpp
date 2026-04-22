#include "Bird.hpp"
#include "Constants.hpp"
#include <SFML/Graphics.hpp>
#include <optional>

int main() {
	sf::RenderWindow window(sf::VideoMode({1280u, 720u}), "Flappy Bird");
	window.setVerticalSyncEnabled(true);

	sf::View view(
			sf::FloatRect({0.f, 0.f}, {bird::VIRTUAL_WIDTH, bird::VIRTUAL_HEIGHT}));
	window.setView(view);

	sf::Texture backgroundTex("assets/background.png");
	sf::Texture groundTex("assets/ground.png");
	backgroundTex.setSmooth(false);
	groundTex.setSmooth(false);

	sf::Sprite background(backgroundTex);
	sf::Sprite ground(groundTex);

	float backgroundScroll = 0.f;
	float groundScroll = 0.f;

	sf::Clock clock;

	Bird flappy;

	while (window.isOpen()) {
		const float dt = clock.restart().asSeconds();

		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
			if (const auto *key = event->getIf<sf::Event::KeyPressed>()) {
				if (key->code == sf::Keyboard::Key::Escape) {
					window.close();
				}
			}
		}

		backgroundScroll =
				std::fmod(backgroundScroll + bird::BACKGROUND_SCROLL_SPEED * dt,
									bird::BACKGROUND_LOOPING_POINT);

		groundScroll = std::fmod(groundScroll + bird::GROUND_SCROLL_SPEED * dt,
														 bird::VIRTUAL_WIDTH);
		flappy.update(dt);

		window.clear();

		background.setPosition({-backgroundScroll, 0.f});
		window.draw(background);
		background.setPosition(
				{-backgroundScroll + bird::BACKGROUND_LOOPING_POINT, 0.f});
		window.draw(background);

		flappy.render(window);

		const float groundY = bird::VIRTUAL_HEIGHT - 16.f;
		ground.setPosition({-groundScroll, groundY});
		window.draw(ground);
		ground.setPosition({-groundScroll + bird::VIRTUAL_WIDTH, groundY});
		window.draw(ground);
		window.display();
	}
}
