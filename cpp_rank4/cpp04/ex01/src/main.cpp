/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:33:09 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 22:34:12 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

int main()
{
	Animal const		*animals[4];

	for (int i = 0; i < 4; i++)
	{
		if ( i % 2 )
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 4; i++)
		delete animals[i];

	cout << "-------------------------------------" << endl;

	Cat *cat = new Cat();
	Dog *dog = new Dog();
	
	Cat *copyCat = new Cat(*cat);
	Dog *copyDog = new Dog();

	delete cat;
	delete dog;
	delete copyCat;
	delete copyDog;

	return 0;
}
