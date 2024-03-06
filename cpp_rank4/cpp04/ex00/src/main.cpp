/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:33:09 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 16:09:20 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/WrongAnimal.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	cout << "-------------------------------------" << endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* a = new WrongCat();
	std::cout << a->getType() << " " << std::endl;
	a->makeSound(); //will output the WrongAnimal sound!
	wrongMeta->makeSound();
	
	cout << "-------------------------------------" << endl;

	delete i;
	delete j;
	delete meta;
	delete a;
	delete wrongMeta;

	
	return 0;
}
