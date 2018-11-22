#include <stdio.h> // printf()
#include <string.h> // strlen()
#include <stdlib.h> // strtoull()
#include <math.h> // sqrtl()
#include <malloc.h> // malloc()

/* This is a two-part, modified Sieve of Eratosthenes, used for sifting through a large swath
 * of numbers that exist a super long way away from zero.  So finding all of the prime numbers
 * in a swath of (let's say) a million numbers from 50,000,000,000,000 (fifty trillion) to
 * 50,000,001,000,000 (fifty trillion, one million).  Not much of a sentence, but, you know...
 */

int main(int argc, char **argv)
{
	int i, next;
	unsigned char *smallsieve;
	unsigned long long int target, primes[1000000];
	long double sqt;
	unsigned int isqt, psqt, count;

	// input target (we convert a command line arg to an unsigned long long int
	if(argc < 2)
		printf("Usage: %s <number-to-test>\n",argv[0]);
	else
	{
		if (strlen(argv[1]) > 19)
			printf("Please use a number between 1 and 9,000,000,000,000,000,000\n");
		else
		{
			target = strtoull(argv[1], NULL, 0);
			// calc sq root of target + 1000000.
			sqt = sqrtl((long double)(target+1000000));
			sqt += 1.0L;
			// make that isqt
			isqt = (unsigned int)sqt;
			// This is the number of primes we need to test to confirm primality
			// And take the square root of THAT (psqt)
			psqt = (unsigned int)sqrt(sqt);
			psqt += 10; // just padding things a little
			printf("Your prize is $%u!!!\n",psqt);
			// That's how many primes we need to make sure that that larger group is prime!

			smallsieve = (unsigned char*)malloc(sqt);
			for(i=0; i<	sqt; i++) smallsieve[i] = 1; // first, populate an array with 1's...

			smallsieve[0] = 0; smallsieve[1] = 0; // These two aren't prime
			next = 0;
			while(next < psqt+1)
			{
				while(!smallsieve[++next]); // find next prime (keep looping while p[++next] is 0)
				// Now, "sift out" multiples of the prime, starting at prime squared
				for(i=next*next; i<sqt; i+=next) smallsieve[i] = 0; // that's the entire sieve algorithm
			}
			// count local primes (could be 4 billion!)
			for(i=0,next=0; next < sqt; next++) if(smallsieve[next] == 1) i++;
			count = i-1;
			printf("sieve requires: %u primes\n", count); 
			//for(i=0,next=0; next < 32768; next++) if(p[next] == 1) primes[i++] = next; 

		}
		if (0) // i.e. skip this part
		{
			printf("Number of times through the main loop (number of primes < 32768) is %d\n",i-1);
			// THAT number is 3511.  3511 primes less than 32768.  3511 times through the big loop!
			// Even with this added task, it ran in 27.4 seconds
			for(next=0;next<i;next++)
			{
				printf("%llu ",primes[next]);
				if((next+1)%16 == 0) printf("\n");
			}
			printf("\n");
		}
	}

	return 0;
}


