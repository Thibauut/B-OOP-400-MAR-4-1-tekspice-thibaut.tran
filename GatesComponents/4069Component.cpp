/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 4069Component.cpp
*/

#include "4069Component.hpp"

nts::Tristate NotOperator(std::size_t value) {
    nts::Tristate _value;
    if (value == nts::UNDEFINED)
        return _value = nts::UNDEFINED;
    if (value == nts::TRUE)
        return _value = nts::FALSE;
    return _value = nts::TRUE;
}

nts::Tristate nts::Component4069::compute(std::size_t pin) {
    nts::Tristate input1 = this->_pins[1].first->compute(this->_pins[1].second);
    nts::Tristate input3 = this->_pins[3].first->compute(this->_pins[3].second);
    nts::Tristate input5 = this->_pins[5].first->compute(this->_pins[5].second);
    nts::Tristate input9 = this->_pins[9].first->compute(this->_pins[9].second);
    nts::Tristate input11 = this->_pins[11].first->compute(this->_pins[11].second);
    nts::Tristate input13 = this->_pins[13].first->compute(this->_pins[13].second);

    nts::Tristate output2 = NotOperator(input1);
    nts::Tristate output4 = NotOperator(input3);
    nts::Tristate output6 = NotOperator(input5);
    nts::Tristate output8 = NotOperator(input9);
    nts::Tristate output10 = NotOperator(input11);
    nts::Tristate output12 = NotOperator(input13);

    if (pin == 2)
        return this->_value = output2;
    if (pin == 4)
        return this->_value = output4;
    if (pin == 6)
        return this->_value = output6;
    if (pin == 8)
        return this->_value = output8;
    if (pin == 10)
        return this->_value = output10;
    if (pin == 12)
        return this->_value = output12;
    return this->_value;
}