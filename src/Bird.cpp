#include "Bird.hpp"
#include "Constants.hpp"

Bird::Bird(const sf::Texture &texture) : sprite(texture) {
	const auto size = texture.getSize();
	width = static_cast<float>(size.x);
	height = static_cast<float>(size.y);

	x = bird::VIRTUAL_WIDTH / 2.f - width / 2.f;
	y = bird::VIRTUAL_HEIGHT / 2.f - height / 2.f;

	sprite.setPosition({x, y});
}

void Bird::flap() {
	dy = -300.f;
}

void Bird::update(float dt) {
	dy += bird::GRAVITY * dt;
	sprite.move({0.f, dy * dt});
}

void Bird::render(sf::RenderWindow &window) const {
	window.draw(sprite);
}