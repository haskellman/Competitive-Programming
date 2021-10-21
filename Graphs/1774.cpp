#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define INF 987654321
#define V 100

int G[V][V];

void liga(int v1, int v2,int peso){
	G[v1][v2] = peso;
	G[v2][v1] = peso;
}

// greedy algorithm 
void prim(int r,int* visitado){
    int x,y,num_lig = 0,sum = 0;

    while (num_lig < r) {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < r; i++) {
            if (visitado[i]) {
                for (int j = 0; j < r; j++) {
                    if (!visitado[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
    sum += G[x][y];
    visitado[y] = true;
    num_lig++;
  }
    cout << sum << endl;
}

int main() {

    int r,c,v,u,peso;
    cin >> r >> c;

    int visitado[V];

    visitado[0] = true;
    memset(visitado, false, sizeof(visitado));

    memset(G, 0, sizeof(G));
    for (int i = 0 ; i < c ; i++){
        cin >> u >> v >> peso;
        u--;
        v--;
        liga(u,v,peso);
    }
    prim(r,visitado);

    return 0;
}