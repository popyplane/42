#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <deque>
# include <stack>

template <typename T>
class   MutantStack : public std::stack<T>
{
    public :
        MutantStack() {}
        MutantStack(const MutantStack<T> &src) : std::stack<T>(src) {}
        MutantStack<T>  &operator=(const MutantStack<T> &src)
        {
			if (this != &src)
				this->std::stack<T>::operator=(src);
			return *this;
		}

        ~MutantStack() {}

        typedef typename    std::deque<T>::iterator itr;

        itr begin() {return (this->c.begin());}
        itr end() {return (this->c.end());}
};

#endif