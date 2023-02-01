// INCLUDES
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// ESTRUCTURES

const int Nil = -1;
const int Infinity = 1000000000;

struct Arc{
  int ciutat;
  int pes;
};

bool operator< (const Arc& a, const Arc& b)
{
    return a.pes > b.pes;
}

using LlistaAdjacencies = vector<Arc>;
using Graf = vector<LlistaAdjacencies>;
// FUNCIONS I ACCIONS
Graf llegir_graf(int n, int m){
  Graf G(n);
  for (int j = 0; j < m; ++j){
    int u, v, weight;
    cin >> u >> v >> weight;
    Arc arc;
    arc.ciutat= v;
    arc.pes = weight;
    G[u].push_back(arc);
    Arc arc2;
    arc2.ciutat = u;
    arc2.pes = weight;
    G[v].push_back(arc2);
  }
  return G;
}

void ruta_barata(const Graf& G, const vector<int>& pesos, int a, int b){
  int n = G.size();
  vector<int> dist(n, Infinity);
  vector<int> prev(n, Nil);
  vector<bool> s(n, false);
  dist[a] = 0;
  priority_queue<Arc> cua;
  cua.push({a, dist[a]});
  while (not cua.empty()){
    int u = cua.top().ciutat;
    cua.pop();
    if (not s[u]){
      s[u] = true;
      for (Arc arc : G[u]){
        int v = arc.ciutat;
        int pes = arc.pes + pesos[v];
        if (dist[v] > dist[u] + pes){
          dist[v] = dist[u] + pes;
          prev[v] = u;
          cua.push({v, dist[v]});
        }
      }
      if (u == b){
        if (u!= a) cout << "c(" << a << "," << b << ") = " << dist[u] - pesos[u] << endl;
        else cout << "c(" << a << "," << b << ") = " << dist[u] << endl;
        return;
      }
    }
  }
  cout << "c(" << a << "," << b << ") = +oo" << endl;
}
// COS PRINCIPAL
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> pesos(n);
  for (int i = 0; i < n; ++i) cin >> pesos[i];
  Graf G = llegir_graf(n, m);
  int a, b;
  while (cin >> a >> b){
    ruta_barata(G, pesos, a, b);
  }
}
