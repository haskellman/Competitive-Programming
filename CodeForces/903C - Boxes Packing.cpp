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

    int n, atual, max = 1, x = 1;
    int aux;

    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> aux;
        pq.push(aux);
    }

    atual = pq.top();
    pq.pop();
    n--;

    while(n--){
        if(pq.top() == atual){
            ++x;
            if(x > max){
                max = x;   
            }
        }else{
            atual = pq.top();
            x = 1;
        }
        pq.pop();
    }
    cout << max << endl;
    return 0;
}



