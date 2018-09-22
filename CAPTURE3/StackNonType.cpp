#include "StackNonType.hpp"
#include <string>
#include <iostream>

int main()
{
    StackNonType<int, 20> stackInt;
    StackNonType<std::string, 20> stackString;

    stackInt.push(2);
    stackInt.pop();

    stackString.push("hi Stack");
    std::cout << stackString.top() << std::endl;
    stackString.pop();
}