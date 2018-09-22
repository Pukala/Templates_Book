#include <array>
#include <cassert>

template<typename T, auto MaxSize>
class StackAuto
{
  public:
    using size_type = decltype(MaxSize);

  private:
    std::array<T, MaxSize> elems;
    size_type numElems;

  public:
    StackAuto();
    void push(const T& elem);
    void pop();
    const T& top() const;
    bool empty() const
    {
        return numElems == 0;
    }
    size_type size() const
    {
        return numElems;
    }
};
template<typename T, auto MaxSize>
StackAuto<T, MaxSize>::StackAuto() : numElems(0) {}

template<typename T, auto MaxSize>
void StackAuto<T, MaxSize>::push(const T& elem)
{
    assert(numElems < MaxSize);
    elems[numElems++] = elem;
}

template<typename T, auto MaxSize>
void StackAuto<T, MaxSize>::pop()
{
    assert(numElems > 0);
    numElems--;
}

template<typename T, auto MaxSize>
const T& StackAuto<T, MaxSize>::top() const
{
    assert(numElems > 0);
    return elems[numElems -1];
}