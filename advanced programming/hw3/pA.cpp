#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int i = 1 ; i <= T ; ++i)
	{
		int N;
		cin >> N;
		vector<int> num;
		for(int j = 0 ; j < N ; ++j)
		{
			int temp;
			cin >> temp;
			num.push_back(temp);
		}
		vector<int>::iterator ans = max_element(num.begin(), num.end());
		num.clear();
		cout << "Case " << i << ": " << *ans << endl;
	}
}