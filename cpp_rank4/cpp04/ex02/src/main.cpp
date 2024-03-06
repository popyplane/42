/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:33:09 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 22:49:51 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

int main()
{
	// const AAnimal* meta = new AAnimal(); // now impossible
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	// meta->makeSound(); // now impossible
	
	cout << "-------------------------------------" << endl;

	delete i;
	delete j;
	// delete meta; // now useless

	return 0;
}
