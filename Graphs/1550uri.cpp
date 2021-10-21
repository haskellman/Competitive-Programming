#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int visitados[10000];

int inverte(int n){
	int aux = 0;
	while (n != 0){
		aux = aux * 10;
		aux = aux + n%10;
		n = n/10;
	}
	return aux;
}

int soma1(int n){
	n = n + 1;
	return n;
}

int busca_largura(int a, int b){

	memset(visitados, 0, sizeof visitados);
	queue<pair<int,int>> q;
	q.push(make_pair(a,0));
	visitados[a] = 1;
	while(!q.empty()){
		int soma, inv;
		int atual = q.front().first;
		int cont = q.front().second;
		q.pop();

		soma = soma1(atual);
		inv = inverte(atual);

		if(soma > 10000 || inv > 10000) continue;

		if(soma == b) return cont+1;	// condicao de parada
		else if(inv == b)  return cont+1; // condicao de parada
		else{
			if(visitados[soma] != 1){		
				visitados[soma] = 1;	
				q.push(make_pair(soma, cont+1));
			}
			if(visitados[inv] != 1){
				visitados[inv] = 1;
				q.push(make_pair(inv, cont+1));
			}
		}
	}
	return 1;
}

int main(){
	int n;
	int a, b;
	cin >> n;
	while(n--){
		cin >> a;  cin >> b;
		cout << busca_largura(a,b) << endl;
	}
}