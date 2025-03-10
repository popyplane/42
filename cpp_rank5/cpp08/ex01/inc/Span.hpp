#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
	private :
		const unsigned int	_size;

	public :
		// canon
		Span();
		Span(unsigned int n);
		Span(const Span &src);
		~Span();
		Span	&operator=(Span &src);

		// members
		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
};

#endif