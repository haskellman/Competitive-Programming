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

void buildRec(int* T, int* A, int node, int start, int end) {
    if(start == end) {
        //# Folha representa um elemento único
        T[node] = A[start];
    } else {
        int mid = (start + end) / 2;
        //# Chamada recursiva para filho à esquerda
        buildRec(T, A, 2 * node, start, mid);
        //# Chamada recursiva para filho à direita
        buildRec(T, A, 2 * node + 1, mid+1, end);
        //# Nó interno tem a SOMA dos dois filhos
        T[node] = T[2 * node] + T[2 * node + 1];        //# <======= IMPORTANTE
    }
}

void build(int *T, int *A, int n) {
    buildRec(T, A, 1, 0, n-1); //# A raíz tem nó 1 e representa o segmento A[0, ..., n-1]
}


int queryRec(int *T, int node, int start, int end, int l, int r) {
    if(r < start or end < l) {
        //# [start, end] está fora de [l, r] -- não há interseção
        return 0;                                       //# <======= IMPORTANTE
    }
    if(l <= start and end <= r){
        //# [start, end] está contido em [l, r]
        return T[node];
    }
    //# [start, end] e [l, r] têm interseção
    int mid = (start + end) / 2;
    int p1 = queryRec(T, 2 * node, start, mid, l, r);
    int p2 = queryRec(T, 2 * node + 1, mid + 1, end, l, r);
    return (p1 + p2);                                   //# <======= IMPORTANTE
}

int query(int* T, int n, int l, int r) { //#Soma(A[l, ..., r])
    return queryRec(T, 1, 0, n-1, l, r);
}

void updateRec(int* T, int* A, int node, int start, int end, int idx, int val) {
    if(start == end) {
        //# Nó folha, atualiza A e T
        A[idx] = val;
        T[node] = val;
    } else {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid) {
            //# idx está no filho à esquerda
            updateRec(T, A, 2 * node, start, mid, idx, val);
        } else {
            //# idx está no filho à direita
            updateRec(T, A, 2 * node + 1, mid + 1, end, idx, val);
        }
        //# Faz atualização do nó pai
        T[node] = T[2 * node] + T[2 * node + 1];        //# <======= IMPORTANTE
    }
}

void update(int *T, int *A, int n, int idx, int val) { //# A[idx] = A[idx] + val
    updateRec(T, A, 1, 0, n - 1, idx, val);
}

int main(){

    int n;
    int casos {0};
    cin >> n;
    while(n && casos < 3){
        int c = n;
        int vec[n];
        int arv[4*n];

        while(c--){
            int seila;
            cin >> seila;
            vec[n-c-1] = seila;
        }
        build(arv, vec, n);                //# Constrói a SegTree
        string control,s,r;
        getc(stdin);
        getline(cin,control);

        cout << "Case " << ++casos << ":" << endl;
        while(control != "END"){
            istringstream ss(control);
            ss >> s;

            if (s == "M"){
                ss >> s >> r;
                cout << query(arv,n,stoi(s)-1,stoi(r)-1) << endl;
            }else{
                ss >> s >> r;
                update(arv,vec,n,stoi(s)-1,stoi(r));
            }

            getline(cin,control);
        }
        cin >> n;
        if(n && casos < 3)
            cout << endl;
    }
	return 0;
}