/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Explode
*/

#ifndef EXPLODE_HPP_
#define EXPLODE_HPP_

#include <string>
#include <iostream>

class Explode
{
public:
    Explode(const std::string &, const std::string &);
    ~Explode() = default;
    std::string next();
    std::string actual() { return (_actual); };

private:
    std::string _original;
    std::string _actual;
    std::string _separator;
    int _pos;
};

#endif // EXPLODE_HPP_

