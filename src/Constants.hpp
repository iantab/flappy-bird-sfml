#pragma once
#include <random>

namespace bird {
	inline constexpr float VIRTUAL_WIDTH = 512.f;
	inline constexpr float VIRTUAL_HEIGHT = 288.f;

	inline constexpr float BACKGROUND_SCROLL_SPEED = 30.f;
	inline constexpr float GROUND_SCROLL_SPEED = 60.f;
	inline constexpr float BACKGROUND_LOOPING_POINT = 413.f;

	inline constexpr float GRAVITY = 980.f;

	inline constexpr float PIPE_SCROLL_SPEED = 60.f;

	static std::mt19937 &rng() {
		static std::mt19937 engine{std::random_device{}()};
		return engine;
	}

} // namespace bird