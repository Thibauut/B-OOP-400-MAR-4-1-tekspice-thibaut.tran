/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** nanotekspice.cpp
*/

#include "AComponents.hpp"
#include "Parser/Parser.cpp"

using namespace nts;

int main(int ac, char **av)
{
    AComponent test;
    Parser file;

    if (ac != 2)
        return 84;

    file.parseFile(av[1], file);
    file.print();

    return 0;
}