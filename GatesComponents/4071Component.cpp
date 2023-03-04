/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 4071Component.cpp
*/

#include "4071Component.hpp"

nts::Tristate OrOperator(size_t value1, size_t value2) {
    nts::Tristate _value;
    if (value1 == nts::Tristate::TRUE || value2 == nts::Tristate::TRUE)
        return _value = nts::Tristate::TRUE;
    else if (value1 == nts::Tristate::FALSE && value2 == nts::Tristate::FALSE)
        return _value = nts::Tristate::FALSE;
    else
        return _value = nts::Tristate::UNDEFINED;
}

nts::Tristate nts::Component4071::compute(std::size_t pin) {
    nts::Tristate input1 = this->_pins[1].first->compute(this->_pins[1].second);
    nts::Tristate input2 = this->_pins[2].first->compute(this->_pins[2].second);
    nts::Tristate input5 = this->_pins[5].first->compute(this->_pins[5].second);
    nts::Tristate input6 = this->_pins[6].first->compute(this->_pins[6].second);
    nts::Tristate input8 = this->_pins[8].first->compute(this->_pins[8].second);
    nts::Tristate input9 = this->_pins[9].first->compute(this->_pins[9].second);
    nts::Tristate input12 = this->_pins[12].first->compute(this->_pins[12].second);
    nts::Tristate input13 = this->_pins[13].first->compute(this->_pins[13].second);

    nts::Tristate output3 = OrOperator(input1, input2);
    nts::Tristate output4 = OrOperator(input5, input6);
    nts::Tristate output10 = OrOperator(input8, input9);
    nts::Tristate output11 = OrOperator(input12, input13);

    if (pin == 3)
        return this->_value = output3;
    if (pin == 4)
        return this->_value = output4;
    if (pin == 10)
        return this->_value = output10;
    if (pin == 11)
        return this->_value = output11;
    return this->_value;
}
