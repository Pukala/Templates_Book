#include "MyStack.hpp"
#include <string>
#include <iostream>

/*
    Specialization of class gives as more flexibility.
    It is posible to add some special behaviors for some types.
*/

template <>
class MyStack<std::string>
{
  private:
    std::vector<std::string> elems;

  public:
    MyStack()
    {
        std::cout << "HI, STRING HRERE\n";
    }
    MyStack(std::string const& elem) : elems({std::move(elem)}) {}
    void push(std::string const &elem);
    void pop();
    std::string const &top() const;
    bool empty() const
    {
        return elems.empty();
    }
};

void MyStack<std::string>::push(std::string const &elem)
{
    elems.push_back(elem);
}

void MyStack<std::string>::pop()
{
    assert(!elems.empty());
    elems.pop_back();
}
std::string const &MyStack<std::string>::top() const
{
    assert(!elems.empty());
    return elems.back();
}

/*
    It is posible to define particular specialization of Type.
    We can do specialization for all pointers.
*/

template <typename T>
class MyStack<T *>
{
  private:
    std::vector<T *> elems;

  public:
    MyStack()
    {
        std::cout << "HI, SOME POINTER HERE\n";
    }
    void push(T *);
    T *pop();
    T *top() const;
    bool empty() const
    {
        return elems.empty();
    }
};

template <typename T>
void MyStack<T *>::push(T *elem)
{
    elems.push_back(elem);
}

template <typename T>
T *MyStack<T *>::pop()
{
    assert(!elems.empty());
    T *p = elems.back();
    elems.pop_back(); // remove last element

    return p;          // and return it (unlike in the general case)
}

template <typename T>
T *MyStack<T *>::top() const
{
    assert(!elems.empty());
    return elems.back();
}

int main()
{
    MyStack<std::string> x; // this has calling constructor for string
    MyStack<int> i;         // this is silence, because doesn't have
    MyStack<int *> p;       // this has calling constructor for pointer

    p.push(new int{42});
    std::cout << *p.top() << "\n";
    delete p.pop();

    MyStack<int> intStack1;
    MyStack<int> intStack2 = intStack1;  // OK in all versions
    MyStack intStack3 = intStack1;       // OK since C++17
    MyStack stackint = 1;                // Stack<int> deduced since C++17

    MyStack stackString{"lala"};
    MyStack stackString2 = "lala";       // Handling raw pointers to std::string
}