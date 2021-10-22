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

typedef pair<int, pair<int,int> > edge;
vector<int> ps;

void init(int n){
    ps.assign(n,0);
    for (int i = 0 ; i < n; i++)
        ps[i] = i;
}

int find_edge(int i){
    return (ps[i] == i? i : ps[i] = find_edge(ps[i]));
}

bool isCircuit(int i, int j){
    return find_edge(i) == find_edge(j);
}

void add_edge(int i, int j){
    ps[find_edge(i)] = find_edge(j);
}

void kruskal(vector<edge>adj,int n,int m){
    int sum = 0;

    sort(adj.begin(), adj.end()); 
    init(n);
    for (int i = 0 ; i < m ; i++){
        edge v = adj[i];
        if (!isCircuit(v.second.first, v.second.second)){
            add_edge(v.second.first, v.second.second);
            sum+= v.first;
        }
    }
    cout << sum << endl;  
}
int main(){
    vector<edge>adj;
    int n,m,v,u,peso;
    
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++){
        cin >> u >> v >> peso;
        u--;
        v--;
        adj.push_back(edge(peso, pair<int,int> (u,v)));
    }
    kruskal(adj,n,m);
    return 0;
}