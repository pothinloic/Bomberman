#include "../include/Menu.hpp"

Menu::Menu(const std::string &path)
{
	std::ifstream	file(path);
	std::string	line;

	while (getline(file, line) != eofbit)
		_buttons.push(new Button(line));
}

Menu::~Menu()
{

}