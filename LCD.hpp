#ifndef LCD_HPP_
#define LCD_HPP_

#include <SDL2/SDL.h>
#include <iostream>
#include <array>

#include "Cell.hpp"

class LCD
{
public:
	LCD();
	~LCD();

	void render();
	void update();
	void handle_events();
	bool is_running() const;
	void load_character(const std::array<std::array<bool, 5>, 8> &character_map);
	void load_character(bool character_map[8][5]);
	void load_character(std::array<uint8_t, 8> &character_map);
	
	friend class Cell;

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Event m_window_event;
	bool m_running = false;

	// Window dimensions - 800x200 (16x2 LCD) 3 px padding on both sides
	const uint32_t m_WINDOW_WIDTH = 16 * 51 + 6;
	const uint32_t m_WINDOW_HEIGHT = 2 * 85;

	// Cell dimensions - 25x40 (5x8 Cells)
	const uint32_t m_BLOCK_WIDTH = 5;
	const uint32_t m_BLOCK_HEIGHT = 8;
	const uint32_t m_CELL_SIZE = 5;

	std::array<std::array<std::array<Cell, 5>, 8>, 16 * 2> blocks;

	size_t m_cursor = 0;
};

#endif // LCD_HPP_
