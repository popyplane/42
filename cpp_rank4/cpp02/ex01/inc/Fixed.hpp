#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

using std::cout;
using std::endl;

class Fixed
{
	private :
		int					_value;
		static const int	_fractionalPart = 8;

	public :
		Fixed( void );
		~Fixed();

		Fixed( int const value );									// new implementation
		Fixed( float const value );									// new implementation
		Fixed( Fixed const & src );
		Fixed &		operator=( Fixed const & rhs );

		float		toFloat( void ) const;							// new implementation
		int			toInt( void ) const;							// new implementation
		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);	// new implementation

#endif