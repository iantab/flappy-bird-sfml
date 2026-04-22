#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include <optional>

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 1280u, 720u }), "Flappy Bird");
	window.setVerticalSyncEnabled(true);

	sf::View view(sf::FloatRect({ 0.f, 0.f }, { bird::VIRTUAL_WIDTH, bird::VIRTUAL_HEIGHT }));
	window.setView(view);

	sf::Texture backgroundTex("assets/background.png");
	sf::Texture groundTex("assets/ground.png");

	sf::Sprite background(backgroundTex);
	sf::Sprite ground(groundTex);
	ground.setPosition({ 0.f, bird::VIRTUAL_HEIGHT - 16.f });

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
			if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
				if (key->code == sf::Keyboard::Key::Escape) {
					window.close();
				}
			}
		}

		window.clear();
		window.draw(background);
		window.draw(ground);
		window.display();
	}
}
