#pragma once
#include <SFML/Graphics.hpp>

enum class PipeOrientation { Top, Bottom };

class Pipe {
	public:
		static constexpr float WIDTH = 70.f;
		static constexpr float HEIGHT = 288.f;

		Pipe(const sf::Texture &texture, PipeOrientation orientation, float y);

		void syncPos(float x);
		void render(sf::RenderWindow &window) const;

	private:
		PipeOrientation orientation;
		float y;
		sf::Sprite sprite;
};