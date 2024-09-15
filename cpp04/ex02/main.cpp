/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 02:41:30 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/07 02:34:09 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

/******************************************************************************/
/*       https://www.programiz.com/cpp-programming/pure-virtual-funtion       */
/******************************************************************************/

int	main(void)
{
	std::cout << "\n--------------------------" << std::endl;
	std::cout << "Test with the Animal class" << std::endl;
	std::cout << "--------------------------\n" << std::endl;

	const AAnimal	*j = new Dog();
	const AAnimal	*i = new Cat();

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

	std::cout << "we can't do this as the Animal class is abstract" << std::endl;
	//AAnimal	animal = Dog("Dog");
	//AAnimal	animal2 = Cat("Cat");


	std::cout << "\n--------------------------------" << std::endl;
	std::cout << "Test with the Animal Array class" << std::endl;
	std::cout << "--------------------------------\n" << std::endl;

	AAnimal *a1 = new Dog();
	AAnimal *a2 = new Cat();
	AAnimal *a3 = new Dog();
	AAnimal *a4 = new Cat();

	AAnimal *animals[] = {a1, a2, a3, a4};

	for (int i = 0; i < 4; i++)
		delete animals[i];

	return (0);
}
