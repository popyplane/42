#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
	private :
		Span();

		static const unsigned int	kMaxSpan;
		
		const unsigned int	_size;
		unsigned int		_minSpan;
		std::multiset<int>	_data;

		// utils
		void	evaluateMinSpan(std::multiset<int>::iterator it, int n);
		void	evaluateSpan(int num1, int num2);
		int		calculateSpan(int num1, int num2);

	public :
		// canon
		Span(unsigned int n);
		Span(const Span &src);
		~Span();
		Span	&operator=(Span &src);

		// members
		void	addNumber(int n);
		unsigned int		shortestSpan();
		unsigned int		longestSpan();
};

#endif