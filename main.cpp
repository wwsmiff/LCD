// https://www.arduino.cc/reference/en/libraries/liquidcrystal/
// https://components101.com/displays/16x2-lcd-pinout-datasheet

#include <iostream>

#include "LCD.hpp"

int main(void)
{
	LCD lcd;

	while(lcd.is_running())
	{
		lcd.update();
		lcd.handle_events();
		lcd.render();
	}

	return EXIT_SUCCESS;
}
