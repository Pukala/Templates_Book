#include <vector>
#include <cassert>
#include <string>
#include <memory>
template <typename T>
class MyStack
{
  private:
    std::vector<T> elems;

  public:
    MyStack() = default;
    MyStack(const T& elem) : elems({std::move(elem)}) {}
    /*
        Since C++17, class template arguments can automatically be deduced from
        constructors.
    */

    void push(T const &elem);
    void pop();
    T const &top() const;
    bool empty() const
    {
       return elems.empty();
    }
    
};

template <typename T>
void MyStack<T>::push(T const &elem)
{
    elems.push_back(elem);
}

template <typename T>
void MyStack<T>::pop()
{
    assert(!elems.empty());
    elems.pop_back();
}

template <typename T>
T const &MyStack<T>::top() const
{
    assert(!elems.empty());
    return elems.back();
}

/*  deduction guides to provide additional or fix 
    existing class template argument deductions.
    Handling raw pointers in containers is a source of trouble, we
    should disable automatically deducing raw character pointers for container classes
*/
MyStack(char const*) -> MyStack<std::string>;