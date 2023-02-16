/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** ClockComponent.cpp
*/

#include "ClockComponent.hpp"

nts::Tristate nts::ClockComponent::compute(std::size_t pin) {
    if (this->_value == nts::UNDEFINED)
        return this->_value = nts::FALSE;
    else if (this->_value == nts::FALSE)
        return this->_value = nts::TRUE;
    else if (this->_value == nts::TRUE)
        return this->_value = nts::FALSE;
    return this->_value;
}
