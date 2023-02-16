/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** output.cpp
*/

#include "OutputComponent.hpp"

nts::Tristate nts::OutputComponent::compute(std::size_t pin) {
    try {
        if (pin != 1)
            throw Error("Output: Pin " + std::to_string(pin) + " doesn't exist on component");
    } catch (Error &e) {
        std::cerr << e.what() << ": ";
    }
    if (pin == 0)
        return this->_value;
    return this->_pins[pin].first->compute(this->_pins[pin].second);
}
