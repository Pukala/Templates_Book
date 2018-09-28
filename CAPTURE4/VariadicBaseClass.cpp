#include <iostream>
#include <string>
#include <unordered_set>

class Customer
{
  private:
    std::string name;
  public:
    Customer(const std::string& n) : name(n) {}
    std::string getName() const { return name; }
};

struct CustomerEq
{
    bool operator() (const Customer& c1, const Customer& c2)
    {
        return c1.getName() == c2.getName();
    }
};

struct CustomerHash
{
    std::size_t operator() (const Customer& c) const
    {
        return std::hash<std::string>()(c.getName());
    }
};

// define class that combines operator() for variadic base classes

template<typename... Bases>
struct Overloader : Bases...
{
    using Bases::operator()...; // OK since c++ 17
};

int main()
{
    // combine hasher and equality for customer in one type:
    using CustomerOp = Overloader<CustomerHash, CustomerEq>;

    std::unordered_set<Customer, CustomerHash, CustomerEq> coll1;
    std::unordered_set<Customer, CustomerOp, CustomerOp> coll2;
}