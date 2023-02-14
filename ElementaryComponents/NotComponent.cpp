/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** NotComponent.cpp
*/

#include "NotComponent.hpp"

nts::Tristate nts::NotComponent::compute(std::size_t pin) {
    if (this->_pins[0].second == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (this->_pins[0].second == nts::TRUE)
        return nts::FALSE;
    return nts::TRUE;
};