#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

using std::cout;
using std::endl;

class Fixed
{
	private :
		int					_rawValue;
		static const int	_fractionalPart = 8;

	public :
		Fixed( void );
		Fixed( int const value );
		Fixed( float const value );
		Fixed( Fixed const & src );
		~Fixed();

		Fixed &		operator=( Fixed const & rhs );

		bool		operator>( Fixed const & rhs );
		bool		operator<( Fixed const & rhs );
		bool		operator>=( Fixed const & rhs );
		bool		operator<=( Fixed const & rhs );
		bool		operator==( Fixed const & rhs );
		bool		operator!=( Fixed const & rhs );

		Fixed &		operator+( Fixed const &rhs );
		Fixed &		operator-( Fixed const &rhs );
		Fixed &		operator*( Fixed const &rhs );
		Fixed &		operator/( Fixed const &rhs );

		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);

		float		toFloat( void ) const;
		int			toInt( void ) const;
		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif