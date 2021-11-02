#include <iostream>
#include <set>
#include <string>
#include <ctype.h>

using namespace std;

int main(){
    string in;
    set<string> words; // Sets stores unique elements following a specific order .
    while (cin >> in){
        string str = "";
        for (int i=0;i<in.size();i++){
            char c = tolower(in[i]);
            if (isalpha(c))str += c;
            else if (str != ""){
                words.insert(str);
                str = "";
            }
        }
        if (str != "")
            words.insert(str);
    }
    for (auto iter=words.begin();iter!=words.end();iter++)
        cout << *iter << endl;
}