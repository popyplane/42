/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:14:42 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/01 13:14:47 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		bool		operator>( Fixed const & rhs ) const;
		bool		operator<( Fixed const & rhs ) const;
		bool		operator>=( Fixed const & rhs ) const;
		bool		operator<=( Fixed const & rhs ) const;
		bool		operator==( Fixed const & rhs ) const;
		bool		operator!=( Fixed const & rhs ) const;

		Fixed &		operator+( Fixed const &rhs );
		Fixed &		operator-( Fixed const &rhs );
		Fixed &		operator*( Fixed const &rhs );
		Fixed &		operator/( Fixed const &rhs );

		Fixed operator++(int);
		Fixed operator++();
		Fixed operator--(int);
		Fixed operator--();

		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);

		float		toFloat( void ) const;
		int			toInt( void ) const;
		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif