/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** input.cpp
*/

#include "InputComponent.hpp"

nts::Tristate nts::InputComponent::compute(std::size_t pin) {
    if (pin == 1)
        this->_value = nts::FALSE;
    else if (pin == 2)
        this->_value = nts::TRUE;
    else
        this->_value = nts::UNDEFINED;
    return this->_value;
};

