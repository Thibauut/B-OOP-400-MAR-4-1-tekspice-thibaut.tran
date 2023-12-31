/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** IComponents.hpp
*/

#pragma once

#include <string>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include "Error/Error.cpp"
#include <memory>

using namespace std;

namespace nts {
    enum Tristate
    {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
        public:

            virtual ~IComponent() = default;

            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void setValue(std::size_t value) = 0;

    };
};