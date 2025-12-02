/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:32:04 by debs              #+#    #+#             */
/*   Updated: 2025/11/12 18:32:10 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cmath>
#include <cstdlib>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &assign);
    ~ScalarConverter();

public:
    static void convert(const std::string &str);
    static void convertToChar(const std::string &str);
    static void convertToInt(const std::string &str);
    static void convertToFloat(const std::string &str);
    static void convertToDouble(const std::string &str);
};

#endif
