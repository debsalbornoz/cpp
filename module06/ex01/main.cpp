/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:46:52 by debs              #+#    #+#             */
/*   Updated: 2025/11/12 18:48:20 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

int main() {
    Data data;
    data.value = 42;

    std::cout << "Original pointer: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized (uintptr_t): " << raw << std::endl;

    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << deserialized << std::endl;

    if (deserialized == &data)
        std::cout << "Sucess!" << std::endl;
    else
        std::cout << "Failure" << std::endl;

    std::cout << "Value: " << deserialized->value << std::endl;

    return 0;
}
