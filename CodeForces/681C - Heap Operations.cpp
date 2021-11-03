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

// References : https://programmersought.com/article/76008442778/

using namespace std;

struct node{
	string s;
	int num;
}a[1000010];


int main(){
    int n;
    cin >> n;
    int cont = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    while(n--){
        string op;
        cin >> op;
        int m;
        if (op == "removeMin"){
            if(!pq.empty()){
                pq.pop();
            }
            else{
                a[cont].s = "insert";
                a[cont].num = 1;
                cont++;
            }
            a[cont].s = op;
        }else if (op == "insert"){
            cin >> m;
            a[cont].s = op;
            a[cont].num = m;
            pq.push(m);

        }else if (op == "getMin"){
            cin >> m;
            while(!pq.empty() && pq.top() < m){
                pq.pop();
                a[cont].s = "removeMin";
                cont++;
            }
            if (pq.empty() || pq.top() > m){
                a[cont].s = "insert";
                a[cont].num = m;
                pq.push(m);
                cont++;
            }
            a[cont].s = op;
            a[cont].num = m;
        }
        cont++;
    }
    cout << cont << endl;

    for (int i=0;i<cont;i++){
        if (a[i].s == "removeMin"){
            cout << a[i].s << endl;
        }else{
            cout << a[i].s << " " << a[i].num << endl;
        }
    }
	return 0;
}