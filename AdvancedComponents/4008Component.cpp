/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** 4008Components.cpp
*/

#include "4008Component.hpp"
#include "../GatesComponents/4030Component.cpp"
#include "../GatesComponents/4081Component.cpp"
#include "../GatesComponents/4071Component.cpp"

nts::Tristate nts::Component4008::Sum(size_t value1, size_t value2, size_t value3) {
    nts::Tristate res;
    nts::Tristate value1_2 = AndOperator(value1, value2);
    nts::Tristate value1_3 = AndOperator(value1, value3);
    nts::Tristate value2_3 = AndOperator(value2, value3);
    res = XorOperator(XorOperator(value1, value2), value3);
    this->_value3 = OrOperator(OrOperator(value1_2, value1_3), value2_3);
    return res;
}

nts::Tristate nts::Component4008::compute(std::size_t pin) {
    nts::Tristate input1 = this->_pins[1].first->compute(this->_pins[1].second);
    nts::Tristate input2 = this->_pins[2].first->compute(this->_pins[2].second);
    nts::Tristate input3 = this->_pins[3].first->compute(this->_pins[3].second);
    nts::Tristate input4 = this->_pins[4].first->compute(this->_pins[4].second);
    nts::Tristate input5 = this->_pins[5].first->compute(this->_pins[5].second);
    nts::Tristate input6 = this->_pins[6].first->compute(this->_pins[6].second);
    nts::Tristate input7 = this->_pins[7].first->compute(this->_pins[7].second);
    nts::Tristate input15 = this->_pins[15].first->compute(this->_pins[15].second);

    nts::Tristate input9 = this->_pins[9].first->compute(this->_pins[9].second);


    nts::Tristate output10 = Sum(input6, input7, input9);
    nts::Tristate output11 = Sum(input4, input5, this->_value3);
    nts::Tristate output12 = Sum(input2, input3, this->_value3);
    nts::Tristate output13 = Sum(input15, input1, this->_value3);
    nts::Tristate output14 = static_cast<nts::Tristate>(this->_value3);

    if (pin == 10)
        return output10;
    if (pin == 11)
        return output11;
    if (pin == 12)
        return output12;
    if (pin == 13)
        return output13;
    if (pin == 14)
        return output14;
    return this->_value;
}