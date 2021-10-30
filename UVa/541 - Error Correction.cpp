#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	//vector<vector<int>> v;
	int v[100][100];
	int l,c;
	int lin = 0;
	int col = 0;
	l = c = 0;
		while(1){
            l = c = 0;
            int somaLinha[100] = {0};
            int somaColuna[100] = {0};
			cin >> n;    // le o tamanho da matriz
            if (n == 0)break;
			for (int i = 0; i < n; i++) {     // le a matriz quadrada
				for (int j = 0; j < n; j++) {
					cin >> v[i][j];
				}
			}
			for (int i = 0; i < n; i++) { // soma as linhas de uma matriz
				for (int j = 0; j < n; j++) {
					somaLinha[i] += v[i][j];
				}
                if (somaLinha[i] % 2 != 0){
                    l++,col=i;
                }
			}
			for (int j = 0; j < n; j++) { // soma as colunas, basta transpor i e j
				for (int i = 0; i < n; i++){
					somaColuna[j] += v[i][j];
				}
                if (somaColuna[j] % 2 != 0){
                    c++,lin=j;
                }
			}
        if(l==0 && c==0)cout<<"OK"<<endl;
        if(l==1 && c==1)cout<<"Change bit ("<<col+1<<","<<lin+1<<")"<<endl;
        if(l>1 || c>1)cout<<"Corrupt"<<endl;
		}
	return 0;
}