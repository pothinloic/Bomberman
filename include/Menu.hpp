#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Button.hpp"

class Menu
{
	public:
		Menu(const std::string &);
		~Menu();

	private:
		std::list<Button *>	_buttons;
};
