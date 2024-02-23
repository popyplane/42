#include "../inc/Fixed.hpp"

Fixed::Fixed( void )
{
    cout << "Default constructor called" << endl;
    this->setRawBits(0);
}

Fixed::Fixed( int const value )
{
    this->_value = value;
    for (int i = 0; i < _fractionalPart; i++)
        this->_value *= 2;
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
        this->_value = rhs.getRawBits();

    return *this;
}

int			Fixed::getRawBits( void ) const
{
    cout << "getRawBits member function called" << endl;

    return (this->_value);
}

void		Fixed::setRawBits( int const raw )
{
    this->_value = raw;
}