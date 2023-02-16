/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** NotComponent.cpp
*/

#include "NotComponent.hpp"

nts::Tristate nts::NotComponent::compute(std::size_t pin) {
    nts::Tristate input1 = this->_pins[1].first->compute(this->_pins[1].second);
    if (input1 == nts::UNDEFINED)
        return this->_value = nts::UNDEFINED;
    if (input1 == nts::TRUE)
        return this->_value = nts::FALSE;
    return this->_value = nts::TRUE;
};