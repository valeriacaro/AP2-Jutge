// INCLUDES
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ESTRUCTURES
using Node = int;
using LlistaAdjacencies = vector<Node>;
using Graf = vector<LlistaAdjacencies>;

// FUNCIONS I ACCIONS
Graf llegir_graf(int n, int m){
  Graf G(n);
  for (int i = 0; i < m; ++i){
    Node u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  return G;
}

void golafre(const Graf& G, int n){
	vector<int> color(n, -1);
	int color_max = 0;
	color[0] = 0;
	for (int i = 0; i<n; ++i){
		vector<bool> agafats(n, false);
		for (Node v : G[i]){
			if (color[v] != -1) agafats[color[v]] = true;
		}
		int j = 0;
		while (agafats[j] == true) ++j;
		color[i] = j;
		color_max = max(color_max, j);
	}
	cout << color_max+1 << endl;
}

// COS PRINCIPAL
int main(){
  int n, m;
  while (cin >> n >> m){
    Graf G = llegir_graf(n, m);
    golafre(G, n);
  }
}
