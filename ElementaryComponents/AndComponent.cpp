/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** And.cpp
*/

#include "AndComponent.hpp"

nts::Tristate nts::AndComponent::compute(std::size_t pin) {
    if (this->_pins[1].first == nullptr || this->_pins[2].first == nullptr)
        return this->_value = nts::Tristate::UNDEFINED;
    nts::Tristate input1 = this->_pins[1].first->compute(this->_pins[1].second);
    nts::Tristate input2 = this->_pins[2].first->compute(this->_pins[2].second);

    if (input1 == nts::Tristate::FALSE || input2 == nts::Tristate::FALSE)
        return this->_value = nts::Tristate::FALSE;
    else if (input1 == nts::Tristate::TRUE && input2 == nts::Tristate::TRUE)
        return this->_value = nts::Tristate::TRUE;
    else
        return this->_value = nts::Tristate::UNDEFINED;
};
