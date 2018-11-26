#include <stdio.h>	// printf()
#include <stdlib.h>	// strtoll()
#include <math.h>	// sqrtl()
#include <malloc.h>	// malloc()
#include <string.h> // strlen(), strcpy()

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

__uint128_t strtoullll(char *str)
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
	//unsigned long long int Q,Q2;
	//unsigned int sq, i, j, p, count;
	unsigned long long int sq, i, j, p, count;
	unsigned char *sieve;
	__uint128_t x,Q,Q2;

	if (argc < 2)
		printf("Usage: %s <number>\n", argv[0]);
	else
	{
		Q = strtoullll(argv[1]);
		sq = (unsigned int)sqrtl((double)Q);
		printf("(%llu)\n",sq);
		printf("%s: ",s128(Q));
		sieve = (unsigned char *)malloc(sq+1);
		for(i=0;i<sq+1;i++) sieve[i] = 1;
		sieve[0] = 0; sieve[1] = 0;
		// This is a hybrid sieve.  Here, we create primes, and also test
		// the target (Q) as having the current prime as a factor.  The nifty part
		// is, if we find a factor, Q (and hence sq) get smaller and the sieve
		// space reduces, accordingly
		p = 0; count=0;
		while(Q>1 && p < sq)
		{
			Q2 = Q; // hang on to the old Q...
			while(!sieve[++p]); // find next prime
			while(Q%p == 0) // found a factor! or maybe many!
			{
				printf("%llu ",p); // print it (possibly many of them! (all the same factor))
				Q/=p; // reduce Q, accordingly
				count++;
			}
			count++;
			if(Q != Q2) sq = (unsigned int)sqrtl((double)Q); // if Q has changed, recalc sieve target (sq)
			// now, Eratosthenetically sift that factor out of the remaining (sq) search space
			if(sq>10000000) sq = 10000000; // ok... so a 100 trillion limit... sort of!
			for(i=p*p, j=p+p;i<sq; i+=j) sieve[i] = 0;
		}
		if(Q > 1) printf("%s ",s128(Q));
		printf("\n(count = %llu)\n",count);
	}
// about that 100,000,000,000,000 limit.  It's only a limit on prime numbers.  You can factor numbers much larger
/*
user0@ii:~/Desktop/very busy days$ time factor 793205223829863717873
793205223829863717873: 3 7 11 11 11 11 11 13 13 17 17 17 19 163 223 409

real	0m0.003s
user	0m0.003s
sys	0m0.000s
user0@ii:~/Desktop/very busy days$ time ./xsf128 793205223829863717873
793205223829863717873: (2394095524) 3 7 11 11 11 11 11 13 13 17 17 17 19 163 223 409 (count = 118)

real	0m5.551s  <---- sure, it's slower, but it's a sieve.  And you sort of have to admit: impressive for a sieve!
user	0m4.883s
sys	0m0.668s
user0@ii:~/Desktop/very busy days$ 
*/
// but the math fails for primes larger than 100 Trillion (which is better than just getting a seg fault, n'est pas?
	return 0;
}
