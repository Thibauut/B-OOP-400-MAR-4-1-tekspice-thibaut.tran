/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** AComponents.hpp
*/

#pragma once

#include "IComponents.hpp"

namespace nts {
    class AComponent: public IComponent {

        // struct Pin {
        //     std::unique_ptr<IComponent> _component;
        //     size_t _pin;
        // };

        public:
            AComponent(std::string name) {
                _component = name;
                // _pins[pin] = pin;
                // _pins[pin]._state = value;
            };
            AComponent() = default;

            virtual ~AComponent() = default;

            virtual nts::Tristate compute(std::size_t pin) = 0;

            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
                AComponent *tmp = dynamic_cast<AComponent*>(&other);
                this->_pins[pin] = std::make_pair(&other, otherPin);
                tmp->_pins[otherPin] = std::make_pair(this, pin);
            };

            virtual nts::Tristate getLink(std::size_t pin) {
                return _pins.at(pin).first->compute(_pins.at(pin).second);
            };

            virtual void simulate(std::size_t tick) {
                this->tick = tick;
            };

            std::string getName() const {
                return _component;
            }

            std::string _component;
            // Tristate _value;

            std::map<std::size_t, std::pair<IComponent*, std::size_t>> _pins;
            std::size_t tick = 0;

    };
};

std::ostream& operator<<(std::ostream &s, nts::Tristate state)
{
    if (state == nts::Tristate::UNDEFINED)
        return s << "-1";
    if (state == nts::Tristate::TRUE)
        return s << "1";
    if(state == nts::Tristate::FALSE)
        return s << "0";
    return s;
};