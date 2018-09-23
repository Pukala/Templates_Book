#include <iostream>

/*
    Since C++ 17 we have Fold Expressions
    it can compute the result of all parameter pack
*/

template<typename... T>
auto foldSum(T... s)
{
    return (... + s);
}

template<typename... T>
auto foldAverage(T... s)
{
    return (... + s)/sizeof...(s);
}

int main()
{
    std::cout << "foldSum = " << foldSum(1, 2, 3) << std::endl;
    std::cout << "foldAverage = " << foldAverage(1, 2, 3, 6, 7, 11) << std::endl;
}