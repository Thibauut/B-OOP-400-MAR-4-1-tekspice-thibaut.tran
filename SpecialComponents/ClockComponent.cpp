/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** ClockComponent.cpp
*/

#include "ClockComponent.hpp"

nts::Tristate nts::ClockComponent::compute(std::size_t pin) {
    return nts::UNDEFINED;
}

void nts::ClockComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (pin != 1)
        throw Error("Clock: Pin " + std::to_string(pin) + " doesn't exist");
    AComponent *tmp = dynamic_cast<AComponent*>(&other);
    this->_pins[pin] = std::make_pair(&other, otherPin);
    tmp->_pins[otherPin] = std::make_pair(this, pin);
}