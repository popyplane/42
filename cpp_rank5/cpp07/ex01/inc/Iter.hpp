#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename Func>
void    iter(T const *array, int const length, Func const &func)
{
    for (int i = 0; i < length; i++)
        func(array[i]);
}

template <typename T>
void    ft_print(T const &content)
{
    std::cout << content << std::endl;
}

#endif