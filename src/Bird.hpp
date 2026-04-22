#pragma once
#include <SFML/Graphics.hpp>

class Bird {
	public:
		float x, y;
		float width, height;

		Bird();

		void render(sf::RenderWindow &window) const;

	private:
		sf::Texture texture;
		sf::Sprite sprite;
};