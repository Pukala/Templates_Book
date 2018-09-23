#include <iostream>

int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int counter4 = 0;

void print()
{
    std::cout << "It's end :(\n";
    counter1++;
}

template<typename T, typename... Types>
void print(T firstArg, Types... args)
{
    std::cout << firstArg << std::endl; // print first argument
    counter2++;
    print(args...); // call print() for remaining arguments
}

// it can also be implement like this
template<typename T>
void print2(T arg)
{
    counter3++;
    std::cout << arg << std::endl; // print passed argument
}

template<typename T, typename... Types>
void print2(T firstArg, Types... args)
{
    counter4++;
    print2(firstArg);
    print2(args...);
}

/*
    sizeof since C++11 let us possibility to check
    number of elements or Types
*/

template<typename T, typename... Types>
void numOfArgsAndTypes(T firstArg, Types... args)
{
    // print number of remaining types
    std::cout << "Types = " << sizeof...(Types) << "\n";
    // print number of remaining args
    std::cout << "args = " << sizeof...(args) << "\n";
}

int main()
{
    print(1, 2, 4.4, "hello");
    print2(1, 2, 4.4, "hello");
    
    std::cout << "counter1 = " << counter1 << std::endl;
    std::cout << "counter2 = " << counter2 << std::endl;
    std::cout << "counter3 = " << counter3 << std::endl;
    std::cout << "counter4 = " << counter4 << std::endl;

    numOfArgsAndTypes(1, 2.2, "hallo", 0);
}