#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>


#define BIGTEN 10000000000000

void p128(__uint128_t val)
{
	unsigned long long int t1, t2, t3;
	t1 = val % BIGTEN;
	val /= BIGTEN;
	if (val>0)
	{
		t2 = val % BIGTEN;
		t3 = val / BIGTEN;
		if (t3>0)
			printf("%llu%013llu%013llu",t3,t2,t1);
		else
			printf("%llu%013llu",t2,t1);
	}
	else
		printf("%llu",t1);
}

char *s128(__uint128_t val)
{
	unsigned long long int t1, t2, t3;
	char buff[100], *retstr; // This returns a malloc'ed buffer, which could turn into a memory leak, if looped.
	t1 = val % BIGTEN;
	val /= BIGTEN;
	if (val>0)
	{
		t2 = val % BIGTEN;
		t3 = val / BIGTEN;
		if (t3>0)
			sprintf(buff,"%llu%013llu%013llu",t3,t2,t1);
		else
			sprintf(buff,"%llu%013llu",t2,t1);
	}
	else
		sprintf(buff,"%llu",t1);
	retstr = (char *) malloc((strlen(buff)+1)*sizeof(char));
	strcpy(retstr,buff);
	return retstr;
}

char *substr(char *str, int start, int len) // Seriously?  It's the twenty first century?
{
	int i,j;
	char *retstr;
	retstr = (char *) malloc((len + 1) * sizeof(char));
	for(i=start, j=0; j<len; j++, i++)
		retstr[j] = str[i];
	retstr[len] = '\0';
	return retstr;
}

__uint128_t strtoullll(char *str) // the recursive 128-bit int parsing routine
{
	__uint128_t num = 0;
	char *partA, *partB;
	if(strlen(str) > 13)
	{
		partA = substr(str,0,strlen(str)-13);
		num = strtoullll(partA) * BIGTEN; // recursion
		partB = substr(str,strlen(str)-13,13);
		num += strtoullll(partB);
	}
	else
		num = strtoull(str, NULL, 0); // standard 64-bit routine
	return num;
}

int main(int argc, char **argv)
{
	__uint128_t Q;
	double sq;

	if (argc < 2)
		printf("Usage: %s <number>\n", argv[0]);
	else
	{
		Q = strtoullll(argv[1]);
		sq = sqrtl((double)Q);
		printf("the square root of %s: %f\n",s128(Q),sq);
	}
	return 0;
}
