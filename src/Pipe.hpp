#pragma once
#include <SFML/Graphics.hpp>

class Pipe {
	public:
		float x, y;
		float width, height;

		Pipe(const sf::Texture &texture);

		void update(float dt);
		void render(sf::RenderWindow &window) const;
		bool offScreen() const;

	private:
		sf::Sprite sprite;
};