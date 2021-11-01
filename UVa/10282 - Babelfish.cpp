#include <iostream>
#include <map>
#include <string>
#include <cstring>


using namespace std;

map<string, string> dic;

int main(){
	char line[50], s1[11], s2[11];

	while (gets(line)){
        if (!line[0] != 0)break;
		sscanf(line, "%s %s", s1, s2);
		dic[s2] = s1;
	}
	while (gets(line)){
		if (dic[line].length() == 0)
			cout << "eh" << endl;
		else
			cout << dic[line].c_str() << endl; 
	}
	return 0;
}
