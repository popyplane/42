#include "../inc/Fixed.hpp"

Fixed::Fixed( void )
{
    this->setRawBits(0);
    cout << "Default constructor called" << endl;
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