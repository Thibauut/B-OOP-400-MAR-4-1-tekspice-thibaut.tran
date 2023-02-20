/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** ClockComponent.cpp
*/

#include "ClockComponent.hpp"

nts::Tristate nts::ClockComponent::compute(std::size_t pin) {
    return this->_value;
}

void nts::ClockComponent::setValue(std::size_t value) {
        if (value == nts::UNDEFINED)
            this->_value = nts::UNDEFINED;
        else if (value == nts::FALSE)
            this->_value = nts::FALSE;
        else if (value == nts::TRUE)
            this->_value = nts::TRUE;
}

    // if (_resetComp == false) {
    //     if (this->_value == nts::UNDEFINED)
    //         this->_value = nts::UNDEFINED;
    //     else if (this->_value == nts::FALSE)
    //         this->_value = nts::TRUE;
    //     else if (this->_value == nts::TRUE)
    //         this->_value = nts::FALSE;
    // }