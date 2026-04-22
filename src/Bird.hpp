#pragma once
#include <SFML/Graphics.hpp>

class Bird {
	public:
		float x, y;
		float width, height;
		float dy = 0.f;

		Bird();

		void update(float dt);
		void render(sf::RenderWindow &window) const;

	private:
		sf::Texture texture;
		sf::Sprite sprite;
};