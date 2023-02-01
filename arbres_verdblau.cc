// ARBRES VERD-BLAU
#include <iostream>
using namespace std;

struct Node;
using Tree = Node*;
struct Node {
    char color;
    Tree left;
    Tree right;

    ~Node()
    {
        delete left;
        delete right;
    }
};

Tree read_tree()
{
    char c;
    if (cin >> c){
      if (c == '-')
          return nullptr;
      else {
          Tree left = read_tree();
          Tree right = read_tree();
          return new Node { c, left, right };
      }
    }
    return nullptr;
}

bool verd_blau(Tree& T, int& compt){
  if (T == nullptr) {
    compt = 0;
    return true;
  }
  int compt_left, compt_right;
  bool both = verd_blau(T->left, compt_left) and verd_blau(T->right, compt_right);
  if (T->color == 'B') compt = compt_left + 1;
  if (T -> color == 'G'){
    compt = compt_left;
    if (T->left != nullptr and T -> left -> color != 'B') return false;
    if (T->right != nullptr and T -> right -> color != 'B') return false;
  }
  return both and compt_left==compt_right;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Tree T = read_tree();
        int compt = 0;
        if (verd_blau(T, compt))
            cout << compt << endl;
        else
            cout << "no" << endl;
        delete T;
    }
}
