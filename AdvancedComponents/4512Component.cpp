/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 4512Component.cpp
*/

#include "4512Component.hpp"

nts::Tristate nts::Component4512::compute(std::size_t pin) {
    return this->_value;
}

void nts::Component4512::setValue(std::size_t value) {
    this->_value = nts::UNDEFINED;
}