#include <iostream>
#include <string>
#include "StackAuto.hpp"


int main()
{
    StackAuto<int, 20u> int20Stack;
    StackAuto<std::string, 40> stringStack;

    int20Stack.push(7);
    std::cout << int20Stack.top() << std::endl;
    auto size1 = int20Stack.size();

    stringStack.push("hello");
    std::cout << stringStack.top() << std::endl;
    auto size2 = stringStack.size();

    // Since C++17, for traits returning values, you can also use the suffix_v and skip ::value
    if(!std::is_same_v<decltype(size1), decltype(size2)>)
    {
        std::cout << "size types differ\n";
    }

    /*
        Using auto enables templates to have nontype template parameters that are values
        of generic types.
    */
}