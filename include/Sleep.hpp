/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Sleep
*/

#ifndef MYSLEEP_HPP_
#define MYSLEEP_HPP_

#ifdef __linux__
#include <unistd.h>
#endif
#ifdef _WIN32
#include <windows.h>
#endif

class MySleep
{
public:
    MySleep(const int &);
    ~MySleep();
private:
};

#endif // !MYSLEEP_HPP_