#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<string, int> lovemap;
	int a;
	cin >> a;
	string str;
	string strr;
	// cin.getline(str, 40);
	for(int i = 0 ; i < a ; i++)
	{
		cin >> strr;
		getline(cin, str);
		lovemap[strr]++;
	}
	for(const auto& l : lovemap){
		cout << l.first << " " << l.second << endl;
	}
}