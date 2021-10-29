#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
	while(1){
		char ch[51];
		cin >> ch;
		if (strcmp(ch, "#") == 0)return 0;
		if (next_permutation(ch, ch + strlen(ch)))
			cout << ch << endl;
		else
			cout << "No Successor" << endl;
   }
   return 0;
}