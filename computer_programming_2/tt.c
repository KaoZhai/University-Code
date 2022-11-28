#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct _tt
{
	int32_t hr;
	int32_t min;
	int32_t sec;
}tt;

int main()
{
	tt tim[2];
	int32_t ansh, ansm, anss;
	int32_t a, b;
	printf("Please enter the time1(xx xx xx): ");
	scanf("%d %d %d", &tim[0].hr, &tim[0].min, &tim[0].sec);
	printf("Please enter the time2(xx xx xx): ");
	scanf("%d %d %d", &tim[1].hr, &tim[1].min, &tim[1].sec);
	a = tim[0].hr * 3600 + tim[0].min * 60 + tim[0].sec;
	b = tim[1].hr * 3600 + tim[1].min * 60 + tim[1].sec;
	if(a > b)
		a = a - b;
	else
		a = b - a;
	anss = a % 60;
	a /= 60;
	ansm = a % 60;
	a /= 60;
	ansh = a;
	printf("this two cha %02d:%02d:%02d", ansh, ansm, anss);
	return 0;
}