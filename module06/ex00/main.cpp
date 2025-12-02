/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:31:52 by debs              #+#    #+#             */
/*   Updated: 2025/11/12 18:15:52 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);
    return 0;
}