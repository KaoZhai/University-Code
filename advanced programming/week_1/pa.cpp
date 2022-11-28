#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;
    while(cin >> a >> b)
    {
    	if(a == 0 && b == 0)
    		break;

    	int alice_map[100010], betty_map[100010];
    	for(int i = 0 ; i < 100010 ; i++)
    	{
    		alice_map[i] = 0;
    		betty_map[i] = 0;
    	}
    	int tmp;
    	for(int i = 0 ; i < a ; i++)
    	{
    		cin >> tmp;
    		alice_map[tmp]++;
    	}
    	for(int i = 0 ; i < b ; i++)
    	{
    		cin >> tmp;
    		betty_map[tmp]++;
    	}
    	int a_cnt = 0, b_cnt = 0;
    	for(int i = 1 ; i <= 100000 ; i++)
    	{
    		if(alice_map[i] >= 1 && betty_map[i] == 0)
    			a_cnt++;
    		if(betty_map[i] >= 1 && alice_map[i] == 0)
    			b_cnt++;
    	}
    	cout << min(a_cnt, b_cnt) << endl;
    }
}