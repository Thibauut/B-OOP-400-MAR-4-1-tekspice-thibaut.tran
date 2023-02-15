/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** Xor.cpp
*/

#include "XorComponent.hpp"

nts::Tristate XorComponent::compute(std::size_t pin) {
    if (pin == 3) {
        if (this->_pins[0].second == nts::UNDEFINED || this->_pins[1].second == nts::UNDEFINED)
            return nts::UNDEFINED;
        if (this->_pins[0].second == this->_pins[1].second)
            return nts::FALSE;
        return nts::TRUE;
    }
    return nts::UNDEFINED;
}