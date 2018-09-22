#include <iostream>

// Simple example
template <typename T>
T max1(T a, T b)
{
    return a > b ? a : b;
}

// multiple parameters
template <typename T1, typename T2>
T1 max2(T1 a, T2 b)
{
    return a > b ? a : b;
}

// define default return typename
template <typename T1 = double, typename T2, typename T3>
T1 max3(T2 a, T3 b)
{
    return a > b ? a : b;
}

// use auto return type C++ 14
template <typename T1, typename T2>
auto max4(T1 a, T2 b)
{
    return a > b ? a : b;
}

// trailing return type C++ 11
template <typename T1, typename T2>
auto max5(T1 a, T2 b) -> decltype(a > b ? a : b)
{
    return a > b ? a : b;
}

// trailing return type C++ 11 use true as the condition is enough
template <typename T1, typename T2>
auto max6(T1 a, T2 b) -> decltype(true ? a : b)
{
    return a > b ? a : b;
}

/*
    two methods above are dangerous becasue T can be reference
    it gives "reference to stack memory associated with local variable"
    For this reason you should return the type decayed from T
*/
#include <type_traits>

template <typename T1, typename T2>
auto max7(T1 a, T2 b) -> typename std::decay<decltype(true ? a : b)>::type
{
    return a > b ? a : b;
}

// return auto always decoys

/*
    standart libary provides more general and yields the "common type"
    of two or more diffrent types
    std::common_type<>::type
*/

template <typename T1, typename T2>
std::common_type_t<T1, T2> max8(T1 a, T2 b) // C++ 14
{
    return a > b ? a : b;
}

// std::common_type<> also decays

/*
    for default parameter can be use std::decay<> or std::common_type<>
*/

template <typename T1, typename T2, typename RT = std::decay_t<decltype(true ? T1() : T2())>>
RT max9(T1 a, T2 b)
{
    return a > b ? a : b;
}

template <typename T1, typename T2, typename RT = std::common_type_t<T1, T2>>
RT max10(T1 a, T2 b)
{
    return a > b ? a : b;
}

// the best and easiest solution is to let the compiler deduce the return by auto

int main()
{
    std::cout << "max1 = " << max1(2.2, 3.3) << std::endl;
    std::cout << "max2 = " << max2(2, 4.4) << std::endl;
    std::cout << "max2<double> = " << max2<double>(2, 4.4) << std::endl; // force return type
    std::cout << "max3 = " << max3(2, 4.4) << std::endl;
    std::cout << "max4 = " << max4(4.4, 2) << std::endl;
    std::cout << "max5 = " << max5(5.5, 1) << std::endl;
    std::cout << "max6 = " << max6(6, 7.7) << std::endl;
    std::cout << "max7 = " << max7(8.8, 2) << std::endl;
    std::cout << "max8 = " << max8(9, 3.2) << std::endl;
    std::cout << "max9 = " << max9(1, 3.3) << std::endl;
    std::cout << "max10 = " << max10(4, 3.3) << std::endl;
}
