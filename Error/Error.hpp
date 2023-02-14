/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibaut.tran
** File description:
** error.hpp
*/

#pragma once

#include <exception>
#include <string>
#include "../Parser/Parser.hpp"


class Error: public std::exception {
    public:
        Error(const std::string& message);
        ~Error() {};

        const char* what()  const noexcept override {
            return _message.c_str();
        };

        static void myErr(std::string msg) {
            try {
                throw Error(msg);
            } catch (Error &e) {
                cout << e.what() << endl;
                exit(84);
            }
        };

    private:
        std::string _message;
};
