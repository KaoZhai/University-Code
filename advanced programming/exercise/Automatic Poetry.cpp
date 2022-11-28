#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;cin.ignore();
	for(int i = 0 ; i < n ; ++i)
	{
		string str1, str2;
		string s2, s3, s4, s5;
		getline(cin, str1);
		getline(cin, str2);
		for(int j = 0 ; j < str1.size() ; ++j)
			if(str1[j] != '<' && str1[j] != '>')
				cout << str1[j];
		cout << endl;

		s2 = str1.substr(str1.find("<")+1, str1.find(">") - str1.find("<") - 1);
		s3 = str1.substr(str1.find(">")+1, str1.rfind("<")-str1.find(">")-1);
		s4 = str1.substr(str1.rfind("<")+1, str1.rfind(">")-str1.rfind("<")-1);
		s5 = str1.substr(str1.rfind(">")+1);

		str2 = str2.substr(0, str2.find("..."));

		cout << str2+s4+s3+s2+s5 << endl;
	}
}