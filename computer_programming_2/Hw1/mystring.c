#include "mystring.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char *mystrchr(const char *s, int c)
{
	int32_t cnt = 0;
	while(1)
	{
		if(*(s + cnt) == c)
			return s + cnt;
		else if(*(s + cnt) == '\0')
			return NULL;
		cnt++;
	}
}

char *mystrrchr(const char *s, int c)
{

}

size_t mystrspn(const char *s, const char *accept)
{

}

size_t mystrcspn(const char *s, const char *reject)
{

}

char *mystrpbrk(const char *s, const char *accept)
{

}

char *mystrstr(const char *haystack , const char *needle)
{

}

char *mystrtok(char *str, const char *delim)
{

}