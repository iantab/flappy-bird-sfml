#include "Bird.hpp"
#include "Constants.hpp"

Bird::Bird() : texture("assets/bird.png"), sprite(texture) {
	texture.setSmooth(false);

	const auto size = texture.getSize();
	width = static_cast<float>(size.x);
	height = static_cast<float>(size.y);

	x = bird::VIRTUAL_WIDTH / 2.f - width / 2.f;
	y = bird::VIRTUAL_HEIGHT / 2.f - height / 2.f;
}

void Bird::render(sf::RenderWindow& window) {
	sprite.setPosition({ x,y });
	window.draw(sprite);
}