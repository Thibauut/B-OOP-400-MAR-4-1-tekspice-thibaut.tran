/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** And.cpp
*/

#include "AndComponent.hpp"

nts::Tristate nts::AndComponent::compute(std::size_t pin) {
    if (this->_pins[0].second == nts::UNDEFINED || this->_pins[1].second == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (this->_pins[0].second == nts::TRUE && this->_pins[1].second == nts::TRUE)
        return nts::TRUE;
    if (this->_pins[0].second == nts::TRUE && this->_pins[1].second == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (this->_pins[0].second == nts::UNDEFINED && this->_pins[1].second == nts::TRUE)
        return nts::UNDEFINED;
    return nts::FALSE;
};