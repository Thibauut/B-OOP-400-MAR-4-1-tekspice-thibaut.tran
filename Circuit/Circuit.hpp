/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** Circuit.hpp
*/

#pragma once

#include "../IComponents.hpp"
#include "../SpecialComponents/InputComponent.hpp"
#include "../SpecialComponents/OutputComponent.hpp"

namespace nts {
    class Circuit {
        public:
            Circuit() = default;
            ~Circuit() {};

            // IComponent
            nts::Tristate compute(std::size_t pin) {};


            void simulate(std::size_t tick) {
                for (auto &x: _components) {
                    x->simulate(tick);
                }
            };

            // Circuit
            void addComponent(std::string name, Parser &component) {
                for(auto &x: component._chipsets) {
                    if (x.second == name) {
                        cout << "component name : " << x.first << endl;
                        if (x.first == "input") {
                            std::unique_ptr<AComponent> input = std::make_unique<nts::InputComponent>(name);
                            _components.push_back(std::move(input));
                            return;
                        }
                        if (x.first == "output") {
                            cout << "output" << endl;
                            std::unique_ptr<AComponent> output = std::make_unique<nts::OutputComponent>(name);
                            _components.push_back(std::move(output));
                            return;
                        }
                    }
                }
            };

            nts::IComponent *getComponent(std::string name, Parser &file) const {
                int pos = 0;
                for(auto &x: file._chipsets) {
                    if (x.second != name)
                        pos++;
                    if (x.second == name)
                        break;
                }
                auto &component = _components[pos];
                return component.get();
            };

            void display() const {
                cout << "input(s):" << endl;
                for (auto& component : _components) {
                    InputComponent* input= dynamic_cast<InputComponent*>(component.get());
                    if (input != nullptr) {
                        cout << "  " << input->getName() << " = " << input->compute(1) << endl;
                    }
                }
                cout << "output(s):"<< endl;
                for (auto& component : _components) {
                    OutputComponent* output= dynamic_cast<OutputComponent*>(component.get());
                    if (output != nullptr) {
                        cout << "  " << output->getName() << " = " << output->compute(1) << endl;
                    }
                }
            }

            // Variables
            protected:
                std::vector<std::unique_ptr<IComponent>> _components;
    };
};