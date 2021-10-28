#include <iostream>

using namespace std;

int main(){

	int t;
	cin >> t;
	while(t--){
		int n, x, y = 0;
		cin >> n;
		while(n--){
			cin >> x;
			y = max(x, y);
		}
		cout << "Case " << i << ": " << y << endl;
	}
	return 0;
}
