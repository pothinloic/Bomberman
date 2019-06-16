#include "../include/Button.hpp"

Button::Button(Explode &infos)
{
    std::string basic;
    std::string hover;

    set_position(infos.next());
    set_type(infos.next());
    basic = infos.next();
    hover = infos.next();
    set_texture(basic, hover);
}

Button::~Button()
{}

static void init_pos(Explode &infos, int &x, int &y)
{
    try {
        x = std::stoi(infos.actual().c_str());
    }   catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << std::endl;
        x = 0;
    }
    try {
        y = std::stoi(infos.next().c_str());
    }   catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << std::endl;
        y = 0;
    }
}

void    Button::set_position(const std::string &str)
{
    Explode infos(str, ":");
    int x = 0;
    int y = 0;

    init_pos(infos, x, y);
    _pos = irr::core::position2d<irr::s32>(x, y);
}

void    Button::set_type(const std::string &str)
{
    if (str == "PLAY")
        _type = PLAY;
    else if (str == "SET")
        _type = SET;
    else if (str == "CRED")
        _type = CRED;
    else if (str == "QUIT")
        _type = QUIT;
    else
        _type = NOTHING;
}

void    Button::set_texture(const std::string &basic, const std::string &hover)
{
    _basic = basic;
    _hover = hover;
}

void    Button::load(irr::video::IVideoDriver *driver)
{
    std::string texture = ((_selected == true) ? _hover : _basic);
    irr::video::ITexture* images = driver->getTexture(texture.c_str());
    driver->draw2DImage(images, _pos);
}

static  Device  quit(Device &device)
{
    delete device.getDevice();
    exit(0);
}

e_game  Button::launchAction(irr::IrrlichtDevice *device)
{
    irr::video::SColor color(255, 140, 230, 220);
    switch (_type) {
    case (PLAY):
        return (PLAY_ON);
    case (SET):
        return (SET_ON);
    case (CRED):
        return (CRED_ON);
    case (QUIT):
        device->drop();
        return (QUIT_NOW);
        break;
    default:
        std::cout << "other" << std::endl;  break;
    }
}
