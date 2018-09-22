#include <array>
#include <cassert>

template<typename T, std::size_t MaxSize>
class StackNonType
{
  private:
    std::array<T, MaxSize> elems;
    std::size_t numElems;

  public:
    StackNonType();
    void push(const T& elem);
    void pop();
    const T& top();
    bool empty() const
    {
        return numElems == 0;
    }
    std::size_t size() const
    {
        return numElems;
    }
};

template<typename T, std::size_t MaxSize>
StackNonType<T, MaxSize>::StackNonType() : numElems(0)
{

}

template<typename T, std::size_t MaxSize>
void StackNonType<T, MaxSize>::push(const T& elem)
{
    assert(numElems < MaxSize);
    elems[numElems++] = elem;
}

template<typename T, std::size_t MaxSize>
void StackNonType<T, MaxSize>::pop()
{
    assert(numElems > 0);
    numElems--;
}

template<typename T, std::size_t MaxSize>
const T& StackNonType<T, MaxSize>::top()
{
    assert(numElems > 0);
    return elems[numElems -1];
}