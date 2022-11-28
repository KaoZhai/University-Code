#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main()
{
	char str[128] = {0}, strtmp[128] {0};
	int32_t cnt = 0, l;

	printf("Please enter the string: ");
	fgets(str, 128, stdin);
	l = strlen(str);
	str[l--] = '\0';
	strcpy(strtmp, str);

	char *tok = strtok(str, ":");

	while(tok != NULL)
	{
		if(!(tok[0] == '\0' || tok[1] == '\0'))
			if((tok[0] <= 'f' && tok[0] >= 'a') || (tok[0] <= '9' && tok[0] >= '0') || (tok[0] <= 'F' && tok[0] >= 'A'))
				if((tok[1] <= 'f' && tok[1] >= 'a') || (tok[1] <= '9' && tok[1] >= '0') || (tok[0] <= 'F' && tok[0] >= 'A'))
					cnt++;

		tok = strtok(NULL, ":");
	}

	if(cnt == 6)
	{
		char *tok = strtok(strtmp, ":");
		while(tok != NULL)
		{
			if(cnt == 6)
			{
				printf("%s", tok);
				cnt--;
			}
			else
			printf("-%s", tok);

			tok = strtok(NULL, ":");
		}
	}
	else
		printf("invalid\n");
	
	return 0;
}