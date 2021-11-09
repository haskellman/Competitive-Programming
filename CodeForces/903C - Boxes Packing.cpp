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

/* Feito em Grupo : Israel,Joana,Rafael Pedruzzi */

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

#define FOI(I, A, B)	for (I=A; I<=B; I++)
#define FOD(I, A, B)	for (I=A; I>=B; I--)

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


int main(){

    int n, atual, max = 1, outro = 1;
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
    //cout << pq.top() << " ";


    while(n--){
        if(pq.top() == atual){
            ++outro;
            if(outro > max){
                max = outro;   
            }
        }else{
            atual = pq.top();
            outro = 1;
        }
        pq.pop();
       // cout << pq.top() << " ";
    }
    cout << max << endl;
    return 0;
}



