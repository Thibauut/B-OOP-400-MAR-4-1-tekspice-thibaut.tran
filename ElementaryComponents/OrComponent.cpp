/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** Or.cpp
*/

#include "OrComponent.hpp"

nts::Tristate OrComponent::compute(std::size_t pin) {
    if (pin == 3) {
        if (this->_pins[0]._state == nts::UNDEFINED || this->_pins[1]._state == nts::UNDEFINED)
            return nts::UNDEFINED;
        if (this->_pins[0]._state == nts::TRUE && this->_pins[1]._state == nts::TRUE)
            return nts::TRUE;
        if (this->_pins[0]._state == nts::TRUE && this->_pins[1]._state == nts::UNDEFINED)
            return nts::TRUE;
        if (this->_pins[0]._state == nts::FALSE && this->_pins[1]._state == nts::UNDEFINED)
            return nts::UNDEFINED;
        return nts::FALSE;
    }
    return (_pins[pin]._state);
};