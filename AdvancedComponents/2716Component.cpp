/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 2716Component.cpp
*/

#include "2716Component.hpp"

nts::Tristate nts::Component2716::compute(std::size_t pin) {
    return this->_value;
}

void nts::Component2716::setValue(std::size_t value) {
    this->_value = nts::UNDEFINED;
}