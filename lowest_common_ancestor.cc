#include <iostream>
using namespace std;

// define standard binary trees

struct Node;

using Tree = Node*;

struct Node {
    int x;
    Tree left;
    Tree right;

    ~Node()
    {
        delete left;
        delete right;
    }
};

// reads a tree according to the specification in the problem statement
Tree read()
{
    int x;
    cin >> x;
    if (x == -1) {
        return nullptr;
    } else {
        Tree left = read();
        Tree right = read();
        return new Node { x, left, right };
    }
};

// ...
Tree lowest_common_ancestor(Tree t, int x, int y)
{
    if (t == nullptr) return nullptr;
    if (t->x == x or t->x == y) return t;
    Tree left  = lowest_common_ancestor(t->left , x, y);
    Tree right = lowest_common_ancestor(t->right, x, y);
    if (left  == nullptr) return right;
    if (right == nullptr) return left ;
    return t;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Tree t = read();
        int u, v;
        cin >> u >> v;
        while (u != -1) {
            Tree lca = lowest_common_ancestor(t, u, v);
            cout << lca->x << endl;
            cin >> u >> v;
        }
        delete t;
        cout << endl;
    }
}
