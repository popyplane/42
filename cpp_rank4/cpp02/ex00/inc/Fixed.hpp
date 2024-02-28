#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

using std::cout;
using std::endl;

class Fixed
{
	private :
		int					_rawValue;
		static const int	_fractionalPart = 8;

	public :
		Fixed( void );
		~Fixed();

		Fixed( Fixed const & src );
		Fixed &		operator=( Fixed const & rhs );

		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
};

#endif