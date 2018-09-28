#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <tuple>

/*
    Since C++ 17 we have Fold Expressions
    it can compute the result of all parameter pack
*/

template<typename... T>
auto foldSum(T... s)
{
    return (... + s);
}

template<typename... T>
auto foldAverage(T... s)
{
    return (... + s)/sizeof...(s);
}

template<typename T>
class AddSpace
{
  private:
    T const& ref; // refer to argument passed in constructor
  
  public:
    AddSpace(const T& r) : ref(r)
    {
    }

    friend std::ostream& operator<<(std::ostream & os, AddSpace<T> s)
    {
        return os << s.ref << ' '; // output passed arg and space
    }
};

template<typename... T>
void print(T... args)
{
    (std::cout << ... << AddSpace(args)) << std::endl;
}


// compute with all the parameters
template<typename... T>
void doubled(T... params)
{
    print(params + params...);
}

template<typename... T>
void addOne(T... params)
{
    print(params + 1 ...);
}

template<typename T1, typename... TN>
constexpr bool isHomogeneus(T1, TN...)
{
    return (std::is_same_v<T1, TN> && ...); // since c++ 17
}

/* 
    this use variadic list of indices to access the corresponding
    elemend of the passed first argument
*/
template<typename T1, typename... Idx>
void printElems(const T1& arr, Idx... idx)
{
    print(arr[idx]...);
}

template<std::size_t... Idx, typename T>
void printIdx(const T& elems)
{
    print(elems[Idx]...);
}

template<std::size_t...>
struct Indices
{

};
template<typename T, std::size_t... Idx>
void printByIdx(T t, Indices<Idx...>)
{
    print(std::get<Idx>(t)...);
}

int main()
{
    std::cout << "foldSum = " << foldSum(1, 2, 3) << std::endl;
    std::cout << "foldAverage = " << foldAverage(1, 2, 3, 6, 7, 11) << std::endl;

    print(1, 2.2, 4);

    doubled(2.2, 1, 1);
    addOne(3.3, 2);
    std::cout << (isHomogeneus(1, 2, "Hello") ? "true" : "false") << std::endl;
    std::cout << (isHomogeneus("Hello", " ", "world") ? "true" : "false") << std::endl;

    std::vector<std::string> elems = {"good", "times", "say", "bye"};
    printElems(elems, 2, 0, 3);
    printIdx<2, 3>(elems);

    std::array<std::string, 5> arr = 
    {
        "Hello", "my", "new", "!", "World"
    };
    printByIdx(arr, Indices<0, 1, 2>());

    auto t = std::make_tuple(12, "monkeys", 2.0);
    printByIdx(t, Indices<0, 1, 2>());
}