#include <stdio.h> // printf()
#include <string.h> // strlen()
#include <stdlib.h> // strtoull()
#include <math.h> // sqrtl()
#include <malloc.h> // malloc()

/* This is a two-part, modified Sieve of Eratosthenes, used for sifting through a large swath
 * of numbers that exist a super long way away from zero.  So finding all of the prime numbers
 * in a swath of (let's say) a million numbers from 50,000,000,000,000 (fifty trillion) to
 * 50,000,001,000,000 (fifty trillion, one million).  Not much of a sentence, but, you know...
 * 
 * btw 50 trillion takes about 0.295 seconds to generate
 */

unsigned long long int target, primes[1000000];
int main(int argc, char **argv)
{
	int i,j, next;
	unsigned char *smallsieve, sieve[1000000];
	long double sqt;
	unsigned int isqt, psqt, count, fcount, *sprimes, z, start;
	// the terms "smallsieve" and "sprimes" refers to their small bit-size (32-bit)

	// input target (we convert a command line arg to an unsigned long long int
	if(argc < 2)
		printf("Usage: %s <number-to-test>\n",argv[0]);
	else
	{
		if (strlen(argv[1]) > 19)
			printf("Please use a number between 1 and 9,000,000,000,000,000,000\n");
		else	//                         actually: 18,446,744,073,709,551,615 (2^64-1)
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
			//printf("Your prize is $%u!!!\n",psqt);
			// That's how many primes we need to make sure that that larger group is prime!

			smallsieve = (unsigned char*)malloc(sqt);
			for(i=0; i<	sqt; i++) smallsieve[i] = 1; // first, populate an array with 1's...

			smallsieve[0] = 0; smallsieve[1] = 0; // These two aren't prime
			next = 0;
			while(next < psqt+1)
			{
				while(!smallsieve[++next]); // find next prime (keep looping while p[++next] is 0)
				// Now, "sift out" multiples of the prime, starting at prime squared
				for(i=next*next; i<isqt; i+=next) smallsieve[i] = 0; // that's the entire sieve algorithm
			}
			// count local primes (could be 4 billion!)
			for(i=0,next=0; next < isqt; next++) if(smallsieve[next] == 1) i++;
			count = i;
			printf("sieve requires: %u primes\n", count);
			sprimes = (unsigned int *)malloc(count * sizeof(unsigned int));
			for(i=0,next=0; next < isqt; next++) if(smallsieve[next] == 1) sprimes[i++] = next; 
			// so... that was the legwork.  Here is where the magic happens...
			// count is the number of primes that we need to check
			// sieve is the place where we'll narrow down our selection of one million candidates.
			// the candidates, themselves, start with target and go to target+1,000,000

			for(i=0; i<	1000000; i++) sieve[i] = 1; // first, populate an array with 1's...

			next = 0;
			for(i=0; i<	count; i++) // so, if we're testing 52000000 primes, this loop goes 52000000 times
			{
				// we have our collection of primes to test, starting with sprimes[0]
				start = 0;
				z = target % sprimes[i]; // this is the remainder from dividing our target by the next prime
				if (z !=0)
					start = sprimes[i] - z; // THIS tells us where to start sifting out multiples of sprimes[i]
				// Now we "sift out" multiples of sprimes[i], starting at sieve[start]
				// keep in mind, start could be 3,000,000,001, which is outside of our million-item array bounds
				if(start<1000000) for(j=start; j<1000000; j+=sprimes[i]) sieve[j] = 0;
			}
			// this is where we "recreate" the primes from the 1's and 0's of our sieve
			for(i=0,next=0; next < 1000000; next++) if(sieve[next] == 1) primes[i++] = target+next;
			fcount = i;
			for(next=0;next<fcount;next++)
			{
				printf("%llu ",primes[next]);
				if((next+1)%4 == 0) printf("\n");
			}
		} // valid target size
	} // target exists
	return 0;
}

