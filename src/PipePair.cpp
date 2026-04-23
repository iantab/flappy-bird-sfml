#include "PipePair.hpp"
#include "Constants.hpp"

PipePair::PipePair(const sf::Texture &texture, float x, float topY)
		: x(x), upper(texture, PipeOrientation::Top, topY),
			lower(texture, PipeOrientation::Bottom, topY + Pipe::HEIGHT + GAP_HEIGHT) {
	upper.syncPos(x);
	lower.syncPos(x);
}

void PipePair::update(float dt) {
	x -= SPEED * dt;
	upper.syncPos(x);
	lower.syncPos(x);
}

void PipePair::render(sf::RenderWindow &window) const {
	upper.render(window);
	lower.render(window);
}

bool PipePair::offScreen() const {
	return x + Pipe::WIDTH < 0.f;
}