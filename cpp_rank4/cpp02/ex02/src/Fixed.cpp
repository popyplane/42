/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:15:48 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/01 13:15:51 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

// CONSTRUCTORS & DESTRUCTOR /////////////////////////////////////////////

Fixed::Fixed( void )
{
	// cout << "Default constructor called" << endl;
	this->_rawValue = 0;
}

Fixed::Fixed( int const value )
{
	// cout <<  "Int constructor called" << endl;
	this->_rawValue = (value << Fixed::_fractionalPart);
}

Fixed::Fixed( float const value )
{
	// cout <<  "Float constructor called" << endl;
	this->_rawValue = roundf(value * (1 << Fixed::_fractionalPart));
}

Fixed::Fixed( Fixed const &src )
{
	// cout << "Copy constructor called" << endl;
	*this = src;
}

Fixed::~Fixed( void )
{
	// cout << "Destructor called" << endl;
}

// OPERATOR OVERLOAD /////////////////////////////////////////////////////

Fixed &		Fixed::operator=( Fixed const &rhs )
{
	if ( this != &rhs )
		this->_rawValue = rhs.getRawBits();
	return (*this);
}

bool    Fixed::operator>( Fixed const &rhs ) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<( Fixed const &rhs ) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=( Fixed const &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool    Fixed::operator<=( Fixed const &rhs ) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==( Fixed const &rhs ) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=( Fixed const &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed &		Fixed::operator+( Fixed const &rhs )
{
	Fixed &	val(*this);

	val.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (val);
}

Fixed &		Fixed::operator-( Fixed const &rhs )
{
	Fixed &	val(*this);

	val.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (val);
}

Fixed &		Fixed::operator*( Fixed const &rhs )
{
	Fixed &	val(*this);
	long	tmp1 = (long)this->getRawBits();
	long	tmp2 = (long)rhs.getRawBits();

	val.setRawBits((tmp1 * tmp2) / (1 << Fixed::_fractionalPart));
	return (val);
}

Fixed &		Fixed::operator/( Fixed const &rhs )
{
	Fixed &	val(*this);
	long	tmp1 = (long)this->getRawBits();
	long	tmp2 = (long)rhs.getRawBits();

	val.setRawBits(tmp1 * (1 << Fixed::_fractionalPart) / tmp2);
	return (val);
}

Fixed	Fixed::operator++()
{
	this->_rawValue++;
	return(*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	operator++();
	return (tmp);
}

Fixed	Fixed::operator--()
{
	this->_rawValue--;
	return(*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	operator--();
	return (tmp);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

// MEMBER FUNCTIONS ///////////////////////////////////////////////////////////

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return(b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return(b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return(b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return(b);
}

int			Fixed::getRawBits( void ) const
{
	return (this->_rawValue);
}

void		Fixed::setRawBits( int const raw )
{
	this->_rawValue = raw;
}

float		Fixed::toFloat( void ) const
{
	return ((float)this->_rawValue / (float)(1 << Fixed::_fractionalPart));
}

int         Fixed::toInt( void ) const
{
	return (this->_rawValue >> Fixed::_fractionalPart);
}