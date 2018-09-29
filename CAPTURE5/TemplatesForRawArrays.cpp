#include <iostream>

template<typename T>
struct MyStruct; // primary template

template<typename T, std::size_t SZ>
struct MyStruct<T[SZ]> // partial specialization for arrays of known bounds
{
    static void print()
    {
        std::cout << "print() for T [" << SZ << "]\n";
    }
};

template<typename T, std::size_t SZ>
struct MyStruct<T(&)[SZ]> // partial spec. for references to arrays of known bounds
{
    static void print()
    {
        std::cout << "print() for T(&) [" << SZ << "]\n";
    }
};

template<typename T>
struct MyStruct<T[]> // partial spec. for arrays of known bounds
{
    static void print()
    {
        std::cout << "print() for T[]\n";
    }
};

template<typename T>
struct MyStruct<T(&)[]> // partial spec. for references to arrays of known bounds
{
    static void print()
    {
        std::cout << "print() for T(&)[]\n";
    }
};

template<typename T>
struct MyStruct<T*> // partial spec. for pointers
{
    static void print()
    {
        std::cout << "print() for T*\n";
    }
};

template<typename T1, typename T2, typename T3>
void foo(int a1[7], int a2[], // pointer by language rules
         int (&a3)[42],       // reference to array of knonw bound
         int(&x0)[],          // reference to array of unknown bound
         T1 x1,               // passing by value decays
         T2& x2, T3&& x3)     // passing by reference
{
    MyStruct<decltype(a1)>::print(); // uses MyStruct<T*>
    MyStruct<decltype(a2)>::print(); // uses MyStruct<T*>
    MyStruct<decltype(a3)>::print(); // uses MyStruct<T(&)[SZ]*>
    MyStruct<decltype(x0)>::print(); // uses MyStruct<T(&)[]>
    MyStruct<decltype(x1)>::print(); // uses MyStruct<T*>
    MyStruct<decltype(x2)>::print(); // uses MyStruct<T(&)[]>
    MyStruct<decltype(x2)>::print(); // uses MyStruct<T(&)[]>
}

int main()
{
    int a[42];
    MyStruct<decltype(a)>::print(); // uses MyStruct<T[SZ]

    extern int x[];                 // foeward declare array
    MyStruct<decltype(x)>::print(); // uses MyStruct<T[]>

    foo(a, a, a, x, x, x, x);
}

int x[] = { 0, 8, 15};