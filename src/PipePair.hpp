#pragma once
#include "Pipe.hpp"

class PipePair {
	public:
		static constexpr float GAP_HEIGHT = 90.f;
		static constexpr float SPEED = 60.f;

		float x;

		PipePair(const sf::Texture &texture, float x, float topY);

		void update(float dt);
		void render(sf::RenderWindow &window) const;

		bool offScreen() const;

	private:
		Pipe upper;
		Pipe lower;
};