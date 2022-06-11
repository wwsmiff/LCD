#ifndef CELL_HPP_
#define CELL_HPP_

#define ON 1
#define OFF 0

#include "LCD.hpp"

class Cell
{
public:
	Cell();
	Cell(bool p_state, int32_t p_x, int32_t p_y, int32_t p_w, int32_t p_h);
	~Cell();
	void set_state(bool p_state);

	friend class LCD;

private:
	bool m_state = 0;
	SDL_Color m_color;
	SDL_Rect m_rect;
};

#endif // CELL_HPP_
