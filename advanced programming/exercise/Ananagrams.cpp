#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	while(1)
	{
		getline(cin, str);
		if(str[0] == '#')
			break;
	}

}