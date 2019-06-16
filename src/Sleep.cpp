/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Sleep
*/

#include "../include/Sleep.hpp"

MySleep::MySleep(const int &time)
{
#ifdef __linux__
    usleep(time * 1000);
#endif
#ifdef _WIN32
    Sleep(time);
#endif
}

MySleep::~MySleep()
{}