/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** TrueComponent.cpp
*/

#include "TrueComponent.hpp"

nts::Tristate nts::TrueComponent::compute(std::size_t pin) {
    return this->_value;
}

void nts::TrueComponent::setValue(std::size_t value) {
    if (value == nts::UNDEFINED)
        this->_value = nts::UNDEFINED;
    else if (value == nts::FALSE)
        this->_value = nts::FALSE;
    else if (value == nts::TRUE)
        this->_value = nts::TRUE;
}