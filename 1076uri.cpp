#include <cstring>
#include <iostream>
#include <vector>
#define V 100

using namespace std;

int G[V][V];
int visitados[V];
int cont = 0;

void liga(int v1, int v2){
	G[v1][v2] = 1;
	G[v2][v1] = 1;
}

void busca_profundidade (int n, int e){
	int i;
	visitados[n] = 1;
	for (i = 0; i < e; i++){
		if (G[n][i] == 1 && visitados[i] == -1){
			cont++;
			busca_profundidade(i, e);
		}
	}
}

int main(){
	int v, a, x, y, t, n;
    cin >> t;
	while(t--){
		cont = 0;
		memset(G, -1, sizeof(G));
		memset(visitados, -1, sizeof(visitados));
		cin >> n;
		cin >> v >> a;
		for (int j = 0; j < a; j++){
			cin >> x >> y;
			liga(x, y);
		}
		busca_profundidade(n, v);
		cout << cont *2 << endl;
	}
	return 0;
}
