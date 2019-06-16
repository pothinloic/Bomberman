/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu
*/

#include <string>
#include "../include/Device.hpp"
#include "../include/Menu.hpp"
#include "../include/Image.hpp"
#include "../include/Button.hpp"
#include "../include/IEntities.hpp"
#include "../include/Explode.hpp"
#include "../include/Sleep.hpp"

static IEntities   *s_entities(const std::string &line)
{
    Explode infos(line, ";");

    switch (std::stoi(infos.actual()))
    {
    case 0:
        return (new Image(infos));
        break;
    case 1:
        return (new Button(infos));
        break;
    default:
        std::cout << "wrong entity type" << std::endl;
        break;
    }
}

Menu::Menu(const std::string &path)
{
    std::ifstream	file(path);
    std::string	line;

    _display = true;
    while (getline(file, line)) {
        if (line.compare(0, 2, "//") != 0)
            _buttons.push_back(s_entities(line));
    }
    _pos = 0;
    next();
}

void Menu::load(irr::video::IVideoDriver *driver)
{
    if (_display == false)
        return;
    for (int i = 0; i != _buttons.size(); i++)
        _buttons[i]->load(driver);
}

void    Menu::next()
{
    (_buttons[_pos])->setSelected(false);
    _pos++;
    if (_pos == _buttons.size())
        _pos = 1;
    while (_buttons[_pos]->isButton() != true)
        _pos++;
    (_buttons[_pos])->setSelected(true);
}

void    Menu::previous()
{
    (_buttons[_pos])->setSelected(false);
    _pos--;
    if (_pos == 0)
        _pos = _buttons.size() - 1;
    while (_buttons[_pos]->isButton() != true)
        _pos--;
    (_buttons[_pos])->setSelected(true);
}

e_game    Menu::checkKey(KeyManagement key, Device &device)
{
    std::vector<bool> input = key.getVectorKey();
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == true && _ttw > device.getTime()) {
            return (PLAY_OFF);
        }
    }
    if (input[e_action::BOMB] == true) {
        _ttw = device.getTime() + 200;
        return (_buttons[_pos]->launchAction(device.getDevice()));
    }
    if (input[e_action::DOWN] == true) {
        _ttw = device.getTime() + 200;
        next();
    }
    if (input[e_action::UP] == true) {
        _ttw = device.getTime() + 200;
        previous();
    }
}

Menu::~Menu()
{}