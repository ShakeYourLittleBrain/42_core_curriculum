/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 02:41:30 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/07 02:01:49 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

/******************************************************************************/
/*       https://www.programiz.com/cpp-programming/virtual-functions          */
/******************************************************************************/

int	main(void)
{
	std::cout << "\n--------------------------" << std::endl;
	std::cout << "Test with the Animal class" << std::endl;
	std::cout << "--------------------------\n" << std::endl;

	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	// we have to set the destructor as virtual to avoid memory leaks
	// if we don't set it as virtual, the destructor of the base class will be called
	delete j;
	delete i;
	/*
		--------------------------
		Test with the Animal class
		--------------------------

		Animal constructor called
		Brain default constructor called
		Dog default constructor called
		Animal constructor called
		Brain default constructor called
		Cat default constructor called
		Animal destructor called
		Animal destructor called

		you can see that the destructor of the base class is called
		so we have leaks in the memory as we set brain in the derived class
		as new Brain() and we didn't delete it unless we call the destructor of the derived class
	*/

	std::cout << "\n---------------------------" << std::endl;
	std::cout << "Test with the Derived class" << std::endl;
	std::cout << "---------------------------\n" << std::endl;

	const Dog	*dog = new Dog();
	const Cat	*cat = new Cat();

	delete dog;
	delete cat;

	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "Test with the Animal class without pointer" << std::endl;
	std::cout << "------------------------------------------\n" << std::endl;


	Animal	animal = Dog("Dog");
	Animal	animal2 = Cat("Cat");


	std::cout << "\n--------------------------------" << std::endl;
	std::cout << "Test with the Animal Array class" << std::endl;
	std::cout << "--------------------------------\n" << std::endl;

	Animal *a1 = new Dog();
	Animal *a2 = new Cat();
	Animal *a3 = new Dog();
	Animal *a4 = new Cat();

	Animal *animals[] = {a1, a2, a3, a4};

	for (int i = 0; i < 4; i++)
		delete animals[i];

	return (0);
}
