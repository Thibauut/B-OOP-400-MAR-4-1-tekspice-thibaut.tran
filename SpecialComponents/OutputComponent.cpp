/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** output.cpp
*/

#include "OutputComponent.hpp"

nts::Tristate nts::OutputComponent::compute(std::size_t pin) {
    if (pin != 1)
        throw Error("Input: Pin " + std::to_string(pin) + " doesn't exist");
    return this->_pins[pin].first->compute(this->_pins[pin].second);
}

void nts::OutputComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (pin != 1)
        throw Error("Output: Pin " + std::to_string(pin) + " doesn't exist");
    AComponent *tmp = dynamic_cast<AComponent*>(&other);
    this->_pins[pin] = std::make_pair(&other, otherPin);
    tmp->_pins[otherPin] = std::make_pair(this, pin);
}