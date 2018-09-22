#include <vector>
#include <cassert>
template <typename T>
class MyStack
{
  private:
    std::vector<T> elems;

  public:
    MyStack() = default;
    MyStack(const T& elem) : elems({elem}) {}

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
