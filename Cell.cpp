#include "LCD.hpp"

Cell::Cell()
{}

Cell::Cell(bool p_state, int32_t p_x, int32_t p_y, int32_t p_w, int32_t p_h)
	:m_state(p_state)
{
	m_rect.x = p_x;
	m_rect.y = p_y;
	m_rect.w = p_w;
	m_rect.h = p_h;

	if(m_state)
	{
		m_color = {0, 20, 0, 255};
	}

	else
	{
		m_color = {0, 150, 0, 255};
	}
}

Cell::~Cell()
{}

void Cell::set_state(bool p_state)
{
	m_state = p_state;
	
	if(m_state)
	{
		m_color = {0, 20, 0, 255};
	}

	else
	{
		m_color = {0, 150, 0, 255};
	}
}
