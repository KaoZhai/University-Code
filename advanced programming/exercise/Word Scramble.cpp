#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
	string str;
	while(getline(cin, str))
	{
		istringstream is(str);
		string s;
		bool f = false;
		while(is >> s)
		{
			if(f)
				cout << " ";
			reverse(s.begin(), s.end());
			cout << s;
			f = true;
		}
		cout << endl;
	}
}