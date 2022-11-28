#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int C;
	cin >> C;
	for(int i = 0 ; i < C ; ++i)
	{
		int N;
		cin >> N;
		vector<int> grade;
		for(int j = 0 ; j < N ; ++j)
		{
			int temp;
			cin >> temp;
			grade.push_back(temp);
		}
		int sum = accumulate(grade.begin(), grade.end(), sum);
		float average = float(sum) / N;
		int cnt = count_if(grade.begin(), grade.end(), >average)
		grade.clear();
	}
}