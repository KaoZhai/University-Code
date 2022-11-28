#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int L;
	cin >> L;
	for(int i = 0 ; i < L ; ++i)
	{
		int N;
		cin >> N;	
		int num[50] = {};
		for(int j = 0 ; j < N ; ++j)
		{
			int temp;
			cin >> temp;
			num[j] = temp;
		}

		int cnt = 0;
		for(int j = 0 ; j < N ; ++j)
		{
			for(int k = j + 1 ; k < N ; ++k)
			{
				if(num[k] < num[j])
				{
					++cnt;
					swap(num[k], num[j]);
				}
			}
		}

		cout << "Optimal train swapping takes " << cnt << " swaps." << endl;
	}
}