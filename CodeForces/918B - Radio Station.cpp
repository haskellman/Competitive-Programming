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

    short int n,m;
    string nome,ip;
    string command, ip2;

    map<string,string> mymap;

    cin >> n >> m;

    while(n--){
        cin >> nome >> ip;
        mymap[ip] = nome;
    }

    while(m--){
        cin >> command >> ip2;
        ip2.erase(ip2.size() -1);
        cout << command << " " << ip2 << "; #" << mymap[ip2] << endl;
    }
    return 0;
}



