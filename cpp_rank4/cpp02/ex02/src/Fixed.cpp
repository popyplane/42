#include "../inc/Fixed.hpp"

Fixed::Fixed( void )
{
    cout << "Default constructor called" << endl;
    this->_rawValue = 0;
}

Fixed::Fixed( int const value )
{
    cout <<  "Int constructor called" << endl;
    this->_rawValue = (value << Fixed::_fractionalPart);
}

Fixed::Fixed( float const value )
{
    cout <<  "Float constructor called" << endl;
    this->_rawValue = roundf(value * (1 << Fixed::_fractionalPart));
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

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return (o);
}

int			Fixed::getRawBits( void ) const
{
    cout << "getRawBits member function called" << endl;
    return (this->_rawValue);
}

void		Fixed::setRawBits( int const raw )
{
    cout << "setRawBits member function called" << endl;
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