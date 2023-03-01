/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 4013Component.cpp
*/

#include "4013Component.hpp"

nts::Tristate nts::Component4013::compute(std::size_t pin) {
    return this->_value;
}

void nts::Component4013::setValue(std::size_t value) {
    this->_value = nts::UNDEFINED;
}