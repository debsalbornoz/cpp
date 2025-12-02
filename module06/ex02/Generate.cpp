/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generate.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:01:41 by debs              #+#    #+#             */
/*   Updated: 2025/11/12 19:01:43 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:15:00 by debs              #+#    #+#             */
/*   Updated: 2025/11/12 19:15:00 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base* generate(void) {
    std::srand(std::time(NULL));
    int random = std::rand() % 3;

    switch (random) {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        default:
            std::cout << "Generated: C" << std::endl;
            return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Type (pointer): A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type (pointer): B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type (pointer): C" << std::endl;
    else
        std::cout << "Unknown type (pointer)" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type (reference): A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type (reference): B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type (reference): C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Unknown type (reference)" << std::endl;
}
