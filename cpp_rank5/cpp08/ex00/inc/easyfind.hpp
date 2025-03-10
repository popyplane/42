#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <sstream>
# include <stdexcept>

template <typename T>
typename T::iterator    easyfind(T &t, int const n)
{
    typename T::iterator    it = std::find(t.begin(), t.end(), n);
    if (it == t.end())
    {
        std::ostringstream  oss;
        oss << "value " << n << " not found";
        throw (std::out_of_range(oss.str()));
    }
    return (it);
}

template <typename T>
typename T::const_iterator    easyfind(const T &t, int const n)
{
    typename T::const_iterator    it = std::find(t.begin(), t.end(), n);
    if (it == t.end())
    {
        std::ostringstream  oss;
        oss << "value " << n << " not found";
        throw (std::out_of_range(oss.str()));
    }
    return (it);
}

#endif