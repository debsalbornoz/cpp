/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:31:56 by debs              #+#    #+#             */
/*   Updated: 2025/11/12 18:31:57 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) { (void)copy; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &assign) { (void)assign; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &str) {
    convertToChar(str);
    convertToInt(str);
    convertToFloat(str);
    convertToDouble(str);
}

void ScalarConverter::convertToChar(const std::string &str) {
    std::cout << "char: ";
    try {
        double value = std::strtod(str.c_str(), NULL);
        if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
            std::cout << "impossível" << std::endl;
        else if (!isprint(static_cast<int>(value)))
            std::cout << "Não exibível" << std::endl;
        else
            std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    } catch (...) {
        std::cout << "impossível" << std::endl;
    }
}

void ScalarConverter::convertToInt(const std::string &str) {
    std::cout << "int: ";
    try {
        double value = std::strtod(str.c_str(), NULL);
        if (std::isnan(value) || std::isinf(value) ||
            value < static_cast<double>(std::numeric_limits<int>::min()) ||
            value > static_cast<double>(std::numeric_limits<int>::max()))
            std::cout << "impossível" << std::endl;
        else
            std::cout << static_cast<int>(value) << std::endl;
    } catch (...) {
        std::cout << "impossível" << std::endl;
    }
}

void ScalarConverter::convertToFloat(const std::string &str) {
    std::cout << "float: ";
    try {
        float value = static_cast<float>(std::strtod(str.c_str(), NULL));
        if (std::isnan(value))
            std::cout << "nanf" << std::endl;
        else if (std::isinf(value))
            std::cout << (value < 0 ? "-inff" : "inff") << std::endl;
        else {
            std::cout << std::fixed << std::setprecision(1) << value << "f" << std::endl;
        }
    } catch (...) {
        std::cout << "impossível" << std::endl;
    }
}

void ScalarConverter::convertToDouble(const std::string &str) {
    std::cout << "double: ";
    try {
        double value = std::strtod(str.c_str(), NULL);
        if (std::isnan(value))
            std::cout << "nan" << std::endl;
        else if (std::isinf(value))
            std::cout << (value < 0 ? "-inf" : "inf") << std::endl;
        else {
            std::cout << std::fixed << std::setprecision(1) << value << std::endl;
        }
    } catch (...) {
        std::cout << "impossível" << std::endl;
    }
}
