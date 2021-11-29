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

int main(){

    int n, k;
    int aux;
    int cont = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n >> k;

    for (int i=0;i<n;i++){
        cin >> aux;
        pq.push(aux);
    }

    while(pq.size() >= 2 && pq.top() < k){
        aux = pq.top();
        pq.pop();
        aux += 2*pq.top();
        pq.pop();
        pq.push(aux);

        cont++;
    }
    if (pq.size() < 2 && pq.top() < k){
        cout << -1 << endl;
    }else{
        cout << cont << endl;
    }

    return 0;
}

