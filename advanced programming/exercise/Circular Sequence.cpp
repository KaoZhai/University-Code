#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; ++i)
	{
		string str;
		cin >> str;
		string min = str, tmp = str;
		for(int j = 0 ; j <= str.size() ; ++j)
		{
			string temp = tmp;
			rotate(temp.begin(), temp.begin()+j ,temp.end());
			if(temp < min)
				min = temp;
		}
		cout << min << endl;
	}
}