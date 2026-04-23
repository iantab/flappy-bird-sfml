#include "Pipe.hpp"
#include "Constants.hpp"

Pipe::Pipe(const sf::Texture &texture, PipeOrientation orientation, float y)
		: orientation(orientation), y(y), sprite(texture) {
	if (orientation == PipeOrientation::Top) {
		sprite.setScale({1.f, -1.f});
	}
}

void Pipe::syncPos(float x) {
	if (orientation == PipeOrientation::Top) {
		sprite.setPosition({x, y + HEIGHT});
	} else {
		sprite.setPosition({x, y});
	}
}

void Pipe::render(sf::RenderWindow &window) const {
	window.draw(sprite);
}