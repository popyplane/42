/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:16:44 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/01 13:16:46 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed( void )
{
    cout << "Default constructor called" << endl;
    this->_rawValue = 0;
}

Fixed::Fixed( Fixed const &src )
{
    cout << "Copy constructor called" << endl;
    
    *this = src;
}

Fixed::~Fixed( void )
{
     cout << "Destructor called" << endl;
}

Fixed &		Fixed::operator=( Fixed const &rhs )
{
    cout << "Copy assignment operator called " << endl;
    
    if ( this != &rhs )
        this->_rawValue = rhs.getRawBits();

    return *this;
}

int			Fixed::getRawBits( void ) const
{
    cout << "getRawBits member function called" << endl;

    return (this->_rawValue);
}

void		Fixed::setRawBits( int const raw )
{
    cout << "getRawBits member function called" << endl;

    this->_rawValue = raw;
}