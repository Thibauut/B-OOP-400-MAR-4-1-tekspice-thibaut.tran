/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** input.cpp
*/

#include "InputComponent.hpp"

nts::Tristate nts::InputComponent::compute(std::size_t pin) {
    try {
        if (pin != 1)
            throw Error("Input: Pin " + std::to_string(pin) + " doesn't exist on component");
    } catch (Error &e) {
        std::cerr << e.what() << ": ";
    }
    return this->_value;
};

void nts::InputComponent::setValue(std::size_t value) {
    if (value == 0)
        this->_value = nts::FALSE;
    else if (value == 1)
        this->_value = nts::TRUE;
    else
        this->_value = nts::UNDEFINED;
}
