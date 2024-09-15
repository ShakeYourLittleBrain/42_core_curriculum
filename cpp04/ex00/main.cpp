/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 02:41:30 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/08 18:29:55 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.cpp"
#include "WrongCat.cpp"

/******************************************************************************/
/*       https://www.programiz.com/cpp-programming/virtual-functions          */
/******************************************************************************/

int	main(void)
{
	const Dog	*dog = new Dog();
	const Cat	*cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();

	// here we don't use pointer to the base class so we can't call the derived class method
	const Animal dog_1 = Dog("Dog");
	std::cout << dog_1.getType() << " " << std::endl;
	// here we call the base class method but our object is of type Dog
	dog_1.makeSound();

	delete dog;
	delete cat;

	std::cout << "\nANIMAL TEST\n" << std::endl;

	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	// here we explicitly call the base class method
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\nWRONG ANIMAL CAT TEST\n" << std::endl;

	const WrongAnimal	*meta_1 = new WrongAnimal();
	const Animal	*j_1 = new Dog();
	const WrongAnimal	*i_1 = new WrongCat();

	std::cout << j_1->getType() << " " << std::endl;
	i_1->makeSound(); // will output the wrong cat sound!
	std::cout << i_1->getType() << " " << std::endl;
	j_1->makeSound();
	// here we explicitly call the base class method
	meta_1->makeSound();

	delete meta_1;
	delete j_1;
	delete i_1;

	return (0);
}

/*
If we don't use virtual keyword in the base class, the output will be:

Animal constructor called
Dog default constructor called
Animal constructor called
Cat default constructor called
Animal type getter called
Dog
Woof woof!
Animal type getter called
Cat
Meow Meow!
Animal constructor called
Dog arg constructor called
Animal copy constructor called
Animal assignment operator called
Dog destructor called
Animal destructor called
Animal type getter called
Dog
Animal can't make sound

ANIMAL TEST

Animal default constructor called
Animal constructor called
Dog default constructor called
Animal constructor called
Cat default constructor called
Animal type getter called
Dog
Animal can't make sound
Animal type getter called
Cat
Animal can't make sound
Animal can't make sound

WRONG ANIMAL CAT TEST

WrongAnimal default constructor called
Animal constructor called
Dog default constructor called
WrongAnimal arg constructor called
WrongCat default constructor called
Animal type getter called
Dog
Meow Meow! Wrong cat here
WrongAnimal type getter called
WrongCat
Animal can't make sound
WrongAnimal can't make sound
Animal destructor called

*/
