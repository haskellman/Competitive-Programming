#include <iostream>
#include <algorithm>
#include <list>

#define min(x,y,z) (x < y ? (x < z ? x : z) : (y < z ? y : z))
#define max(x,y,z) (x > y ? (x > z ? x : z) : (y > z ? y : z))


using namespace std;

int main(){

    short int T,x,y,z;
    cin >> T;
    list<short int> l;

    for(int i=1;i<=T;i++){
        cin >> x >> y >> z;
        l = {x,y,z};
        l.sort();

        auto x = l.begin(); // second element
        x++;
        cout << "Case " << i << ": " << *x << endl;
    }

	return 0;
}
