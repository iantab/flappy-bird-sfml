#include "Bird.hpp"
#include "Constants.hpp"
#include "Pipe.hpp"
#include "PipePair.hpp"
#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>

int main() {
	sf::RenderWindow window(sf::VideoMode({1280u, 720u}), "Flappy Bird");
	window.setVerticalSyncEnabled(true);

	sf::View view(sf::FloatRect({0.f, 0.f}, {bird::VIRTUAL_WIDTH, bird::VIRTUAL_HEIGHT}));
	window.setView(view);

	sf::Texture backgroundTex("assets/background.png");
	sf::Texture groundTex("assets/ground.png");
	sf::Texture birdTex("assets/bird.png");
	sf::Texture pipeTex("assets/pipe.png");

	backgroundTex.setSmooth(false);
	groundTex.setSmooth(false);
	birdTex.setSmooth(false);
	pipeTex.setSmooth(false);

	sf::Sprite background(backgroundTex);
	sf::Sprite ground(groundTex);

	float backgroundScroll = 0.f;
	float groundScroll = 0.f;

	sf::Clock clock;

	Bird flappy(birdTex);

	std::vector<PipePair> pipePairs;
	float spawnTimer = 0.f;
	float lastY = -Pipe::HEIGHT + 10.f + static_cast<float>(bird::rng()() % 81);

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
				if (key->code == sf::Keyboard::Key::Space) {
					flappy.flap();
				}
			}
		}

		backgroundScroll = std::fmod(
				backgroundScroll + bird::BACKGROUND_SCROLL_SPEED * dt,
				bird::BACKGROUND_LOOPING_POINT);

		groundScroll = std::fmod(groundScroll + bird::GROUND_SCROLL_SPEED * dt, bird::VIRTUAL_WIDTH);
		flappy.update(dt);
		spawnTimer += dt;
		if (spawnTimer > 2.f) {
			std::uniform_int_distribution<int> drift(-20, 20);

			float y = std::max(
					-Pipe::HEIGHT + 10.f,
					std::min(
							lastY + drift(bird::rng()),
							bird::VIRTUAL_HEIGHT - PipePair::GAP_HEIGHT - Pipe::HEIGHT));
			lastY = y;
			pipePairs.emplace_back(pipeTex, bird::VIRTUAL_WIDTH + 32.f, y);
			spawnTimer = 0.f;
		}

		for (auto &pipe : pipePairs) {
			pipe.update(dt);
		}

		std::erase_if(pipePairs, [](const PipePair &p) { return p.offScreen(); });

		window.clear();

		background.setPosition({-backgroundScroll, 0.f});
		window.draw(background);
		background.setPosition({-backgroundScroll + bird::BACKGROUND_LOOPING_POINT, 0.f});
		window.draw(background);

		flappy.render(window);
		for (const auto &pair : pipePairs) {
			pair.render(window);
		}

		const float groundY = bird::VIRTUAL_HEIGHT - 16.f;
		ground.setPosition({-groundScroll, groundY});
		window.draw(ground);
		ground.setPosition({-groundScroll + bird::VIRTUAL_WIDTH, groundY});
		window.draw(ground);
		window.display();
	}
}
