/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Explode
*/

#include "../include/Explode.hpp"

Explode::Explode(const std::string &str, const std::string &c)
{
    _original = str;
    _separator = c;
    _pos = _original.find(c);
    _actual = _original.substr(0, _pos);
    _pos++;
}

std::string Explode::next()
{
    int next_pos = _original.find(_separator, _pos);
    int part_size = next_pos - _pos;

    if (_pos == -1)
        return ("NULL");
    _actual = _original.substr(_pos, part_size);
    _pos = next_pos + ((next_pos == -1) ? 0 : 1);
    return ((_pos != -1) ? _actual : "NULL");
}