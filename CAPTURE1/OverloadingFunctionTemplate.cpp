#include <iostream>
#include <cstring>

/*
    Be careful to use T&
*/

// maximum of two values of any type (call-by-reference)
template<typename T>
const T& max(const T& a, const T& b)
{
    return b < a ? a : b;
}

// maximum of two C-strings (call-by-value)
char const* max (char const* a, char const* b)
{
    return std::strcmp(b,a) < 0 ? a : b;
}

// maximum of three values of any type (call-by-reference)
template<typename T>
const T& max(const T& a, const T& b, const T& c)
{
    return max (max(a,b), c);
}

int main()
{
    std::cout << max(2, 5, 3) << std::endl; // OK

    const char* s1 = "ala";
    const char* s2 = "ma";
    const char* s3 = "kota";

    auto m2 = max(s2, s1, s3); // returning reference to local temporary object
}