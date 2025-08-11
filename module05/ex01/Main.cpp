/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debs <debs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:51:49 by debs              #+#    #+#             */
/*   Updated: 2025/08/11 16:55:04 by debs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main(void)
{
    std::cout << "\n---- Creating Bureaucrat ----" << std::endl;
    Bureaucrat *a = createBureaucrat("Alice", 2);
    Bureaucrat *b = createBureaucrat("Bob", 75);
    
    std::cout << "\n---- Creating Forms ----" << std::endl;
    Form *f1 = createForm("Shrubbery Creation", 145, 137);
    Form *f2 = createForm("Robotomy Request", 72, 45);
    Form *f3 = createForm("Presidential Pardon", 25, 5);
    Form *f4 = createForm("Invalid form", 151, 5);
    (void)f4;
    
    std::cout << "\n---- Printing Forms ----" << std::endl;
    std::cout << *f1 << std::endl;
    std::cout << *f2 << std::endl;
    std::cout << *f3 << std::endl;
    
    std::cout << "\n---- Trying Bureaucrat to sign forms ----" << std::endl;
    a->signForm(*f1);
    a->signForm(*f2);
    a->signForm(*f3);
    b->signForm(*f1);
    b->signForm(*f2);
    b->signForm(*f3);
    std::cout << "\n---- Deleting Forms ----" << std::endl;
    deleteForm(f1);
    deleteForm(f2);
    deleteForm(f3);
    
    std::cout << "\n---- Deleting Bureaucrats ----" << std::endl;
    deleteBureaucrat(a);
    deleteBureaucrat(b);
    
    /*std::string name = "Debora";
    int grade = 75;
        Bureaucrat b(name, grade);
        Form f1 = Form("Shrubbery Creation", 145, 137);
        Form f2 = Form("Robotomy Request", 72, 45);
        Form f3 = Form("Presidential Pardon", 25, 5);

        std::cout << b << std::endl;
        std::cout << f1;
        b.signForm(f1);
        std::cout << std::endl;
        std::cout << f2;
        b.signForm(f2);
        std::cout << std::endl;
        std::cout << f3;
        b.signForm(f3);
        std::cout << std::endl;
        */
    return (0);       
}