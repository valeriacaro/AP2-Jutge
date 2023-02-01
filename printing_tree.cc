/*Write a program that reads a binary tree of words, and that prints it
following the format of the sample.

Input

Input consists of the description of a tree, which is a preorder traversal of
its words, marking the empty trees with ‘-1’- You can assume that the given
words have less than ten letters.

Output

Your program must print the tree following the format of the sample. Notice that
each level of the tree is printed using ten characters.*/

// INCLUDES
#include <iostream>
using namespace std;
// ESTRUCTURES
struct Node;
using Tree = Node*;
struct Node{
  string x;
  int level;
  Tree left;
  Tree right;
  ~Node(){
    delete left;
    delete right;
  }
};
// FUNCIONS I ACCIONS
Tree read_tree(int level){
  string x;
  cin >> x;
  if (x == "-1") return nullptr;
  else{
    Tree l = read_tree(level+1);
    Tree r = read_tree(level+1);
    return new Node{x, level, l, r};
  }
}

void print_line(string& word, int level)
{
    for (int i = 0; i < level*10 - word.size(); ++i) {
        cout << ' ';
    }
    cout << word << endl;
}

void print_tree(Tree T)
{
    if (T) {
        print_tree(T->right);
        print_line(T->x, T->level);
        print_tree(T->left);
    }
}

// COS PRINCIPAL
int main(){
  Tree a = read_tree(1);
  print_tree(a);
}
