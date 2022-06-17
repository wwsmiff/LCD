// https://www.arduino.cc/reference/en/libraries/liquidcrystal/
// https://components101.com/displays/16x2-lcd-pinout-datasheet

#define SDL_MAIN_HANDLED

#include <iostream>
#include <array>

#include "LCD.hpp"
#include "fonts_en.hpp"

bool smiley[8][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{1, 0, 0, 0, 1},
	{0, 1, 1, 1, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0}
};

std::array<uint8_t, 8> test_map = {{
		0x1F,
		0x11,
		0x11,
		0x11,
		0x11,
		0x11,
		0x11,
		0x1F
}};

int main(void)
{
	LCD lcd;
	
	lcd.load_character(fonts_en::A);
	lcd.load_character(fonts_en::B);
	lcd.load_character(fonts_en::C);
	lcd.load_character(fonts_en::D);
	lcd.load_character(fonts_en::E);
	lcd.load_character(fonts_en::F);
	lcd.load_character(fonts_en::G);
	lcd.load_character(fonts_en::H);
	lcd.load_character(fonts_en::I);
	lcd.load_character(fonts_en::J);

	lcd.load_character(smiley);

	while(lcd.is_running())
	{
		lcd.update();
		lcd.handle_events();
		lcd.render();
	}

	return EXIT_SUCCESS;
}
