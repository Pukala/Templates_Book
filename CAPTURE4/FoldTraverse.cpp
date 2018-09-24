struct Node
{
    int value;
    Node* left;
    Node* right;
    Node() : value(0), left(nullptr), right(nullptr) {}
};

auto left = &Node::left;
auto right = &Node::right;

// traverse tree, using fold expression
template<typename T, typename... TP>
Node* traverse(T np, TP... paths)
{
    return (np->* ... ->* paths); // np ->* paths1 ->* paths2 ...
}

int main()
{
    
}