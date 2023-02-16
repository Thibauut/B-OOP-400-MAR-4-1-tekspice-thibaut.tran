/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** TrueComponent.cpp
*/

#include "TrueComponent.hpp"

nts::Tristate nts::TrueComponent::compute(std::size_t pin) {
    try {
        if (pin != 1)
            throw Error("True: Pin " + std::to_string(pin) + " doesn't exist on component");
    } catch (Error &e) {
        std::cerr << e.what() << ": ";
    }
    return _value;
}

void nts::TrueComponent::setValue(std::size_t value) {
    if (value == 0)
        this->_value = nts::FALSE;
    else if (value == 1)
        this->_value = nts::TRUE;
    else
        this->_value = nts::UNDEFINED;
}