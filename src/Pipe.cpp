#include "Pipe.hpp"
#include "Constants.hpp"
#include <random>

Pipe::Pipe(const sf::Texture &texture) : sprite(texture) {
	const auto size = texture.getSize();
	width = static_cast<float>(size.x);
	height = static_cast<float>(size.y);

	std::uniform_real_distribution<float> randomY(
			bird::VIRTUAL_HEIGHT / 2.f,
			bird::VIRTUAL_HEIGHT - 10.f);
	x = bird::VIRTUAL_WIDTH;
	y = randomY(bird::rng());
}

void Pipe::update(float dt) {
	x -= bird::PIPE_SCROLL_SPEED * dt;
	sprite.setPosition({x, y});
}

void Pipe::render(sf::RenderWindow &window) const {
	window.draw(sprite);
}

bool Pipe::offScreen() const {
	return x + width < 0.f;
}