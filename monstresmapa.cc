// MONSTRES EN UN MAPA

// INCLUDES
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// ESTRUCTURES

struct Node{
  int x;
  int y;
};

using Graph = vector<vector<char>>;
// FUNCIONS I ACCIONS

vector<Node> neighbours(Node& u, int n, int m){
  vector<Node> neighbours;
  if(u.x > 0) neighbours.push_back({u.x - 1, u.y});
  if(u.x < n-1) neighbours.push_back({u.x + 1, u.y});
  if(u.y > 0) neighbours.push_back({u.x, u.y - 1});
  if(u.y < m-1) neighbours.push_back({u.x, u.y + 1});
  return neighbours;
}

Graph read_graph(int n, int m, vector<vector<bool>>& paths, queue<Node>& nodes_queue){
  Graph G(n, vector<char> (m));
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      cin >> G[i][j];
      if (G[i][j] == 'I'){
        Node I;
        I.x = i;
        I.y = j;
        paths[I.x][I.y] = true;
        nodes_queue.push(I);
      } else if (G[i][j] == 'M'){
        Node M;
        M.x = i;
        M.y = j;
        for (Node v: neighbours(M, n, m)) paths[v.x][v.y] = true;
      }
    }
  }
  return G;
}

bool path_exists(const Graph& G, int n, int m, vector<vector<bool>>& paths, queue<Node>& nodes_queue){
  while (not nodes_queue.empty()){
    Node u = nodes_queue.front();
    nodes_queue.pop();
    for (Node v: neighbours(u, n, m)){
      if (G[v.x][v.y] == 'F') return true;
      if (not paths[v.x][v.y]){
        paths[v.x][v.y] = true;
        nodes_queue.push(v);
      }
    }
  }
  return false;
}

// COS PRINCIPAL
int main(){
  int n, m;
  while(cin >> n >> m){
    vector<vector<bool>> paths(n, vector<bool> (m, false));
    queue<Node> nodes_queue;
    Graph G = read_graph(n, m, paths, nodes_queue);
    if (path_exists(G, n, m, paths, nodes_queue)) cout << "SI" << endl;
    else cout << "NO" << endl;
  }
}
