#include "LCD.hpp"

LCD::LCD()
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Failed to initialize SDL2, " << SDL_GetError() << std::endl;
		return;
    }

    m_window = SDL_CreateWindow("16x2 LCD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_WINDOW_WIDTH, m_WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if(!m_window)
    {
        std::cout << "Failed to create a window, " << SDL_GetError() << std::endl;
		return;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(!m_renderer)
    {
        std::cout << "Failed to create a renderer, " << SDL_GetError() << std::endl;
		return;
    }

	for(size_t x = 0; x < 2; ++x)
	{
		for(size_t y = 0; y < 16; ++y)
		{
			static uint32_t index = 0;

			for(size_t i = 0; i < m_BLOCK_HEIGHT; ++i)
			{
				for(size_t j = 0;  j < m_BLOCK_WIDTH; ++j)
				{
					blocks[index][i][j].m_rect.x = (y * 50) + (j + 3) * 7;
					blocks[index][i][j].m_rect.y = (x * 70) + (i + 3) * 7;
					blocks[index][i][j].m_rect.w = blocks[index][i][j].m_rect.h = m_CELL_SIZE;
					blocks[index][i][j].set_state(0);
				}
			}

			index++;
		}
	}

	m_running = true;
}

LCD::~LCD()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);

	SDL_Quit();
}

void LCD::render()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 170, 0, 255);
	SDL_RenderClear(m_renderer);

	for(size_t x = 0; x < 32; ++x)
	{
		for(size_t i = 0; i < m_BLOCK_HEIGHT; ++i)
		{
			for(size_t j = 0; j < m_BLOCK_WIDTH; ++j)
			{
				SDL_SetRenderDrawColor(m_renderer, blocks[x][i][j].m_color.r, 
												   blocks[x][i][j].m_color.g, 
												   blocks[x][i][j].m_color.b, 
												   blocks[x][i][j].m_color.a);

				SDL_RenderFillRect(m_renderer, &blocks[x][i][j].m_rect);
			}
		}
	}

	SDL_RenderPresent(m_renderer);
}

void LCD::update()
{
}

void LCD::load_character(const std::array<std::array<bool, 5>, 8> &character_map)
{
	for(size_t i = 0; i < 8; ++i)
	{
		for(size_t j = 0; j < 5; ++j)
		{
			blocks[m_cursor][i][j].set_state(character_map[i][j]);
		}
	}

	m_cursor++;
}

void LCD::load_character(bool character_map[8][5])
{
	for(size_t i = 0; i < 8; ++i)
	{
		for(size_t j = 0; j < 5; ++j)
		{
			blocks[m_cursor][i][j].set_state(character_map[i][j]);
		}
	}

	m_cursor++;
}

void LCD::load_character(std::array<uint8_t, 8> &character_map)
{
	for(size_t i = 0; i < 8; ++i)
	{
		for(size_t j = 0; j < 5; ++j)
		{
			// bool first = character_map[i] & 0x1;
			// bool second = character_map[i] & 0x2;
			// bool third = character_map[i] & 0x4;
			// bool fourth = character_map[i] & 0x8;
			// bool fifth = character_map[i] & 0x10;
			
			blocks[m_cursor][i][j].set_state(character_map[i] & static_cast<uint8_t>(1 * std::pow(2, j)));
		}
	}

	m_cursor++;
}

void LCD::handle_events()
{
	SDL_PollEvent(&m_window_event);
	if(m_window_event.type == SDL_QUIT) m_running = false;
}

bool LCD::is_running() const
{
	return m_running;
}
