#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int luk[7] = {};
	for(int i = 0 ;  i < 7  ; i++)
	{
		while(1)
		{
			int flag = 0;
			luk[i] = rand() % 9 + 1;
			for(int j = 0 ; j < i ; j++)
			{
				if(luk[j] == luk[i])
				{
					flag = 1;
					break;
				}
			}
			if(!flag)
				break;
		}
		printf("%d\n", luk[i]);
	}
	return 0;
}