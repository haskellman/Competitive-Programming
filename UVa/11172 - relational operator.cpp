#include <iostream>

using namespace std;

int main(){

	int t;
	cin >> t;

	if (t < 15){
        for(int i=0;i<t;i++){
            int a,b;
            cin >> a >> b;
            if ((a < 1000000001) && (b < 1000000001)){
                if (a>b) cout <<  ">";
                else if (a<b) cout << "<";
                else cout << "=";
                cout << endl;
            }
        }
	}
	return 0;
}
