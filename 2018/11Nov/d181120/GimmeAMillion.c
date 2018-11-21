#include <stdio.h>

// this is a billion (2^30) for a reason.  Run it - see how long it takes!
#define HOWBIG 3000000000
// ROOT is the square root of our target (HOWBIG)
#define ROOT 54773

unsigned char p[HOWBIG]; // This is just a maximum

// You often see "The Sieve" in computer benchmarks.  It can "busy" a system!
// But I have found that it is MUCH faster than any other prime generator, for primes
// as large as 100 quadrillion.

//32,416,190,071
//32,416,187,567 
//34,359,738,368

int main()
{
	int i, next, primes[100000];
	unsigned long long int target;

// input target
// calc sq root of target + 1.  make that maxsq
// fill sieve with 1's to maxsq
// calc sq of maxsq + 1.  make that sqsq
// sift using sqsq and maxsq to get "a bunch of" primes
// use the "bunch of" sieved primes to sift target swath.
// return remaining (guaranteed, btw) primes from target swath
	
	// first, populate an array with 1's...
	for(i=0; i<	HOWBIG; i++) p[i] = 1;

	p[0] = 0; p[1] = 0; // These two aren't prime
	// After taking care of zero and one, you look for the next value in the huge array that
	// is equal to 1.  That would be p[2].  Turns out, 2 is the first prime!
	next = 0;
	while(next < ROOT+1) // just like using % to test for even divisibility, we only need ROOT tests
	{
		while(!p[++next]); // find next prime (keep looping while p[++next] is 0)
		// Now, "sift out" multiples of the prime, starting at prime squared
		for(i=next*next; i<HOWBIG; i+=next) p[i] = 0; // that's the entire sieve algorithm
	}

	for(i=0,next=0; next < 32768; next++) if(p[next] == 1) primes[i++] = next; 
	printf("Number of times through the main loop (number of primes < 32768) is %d\n",i-1);
	// THAT number is 3511.  3511 primes less than 32768.  3511 times through the big loop!
	// Even with this added task, it ran in 27.4 seconds
	for(next=0;next<i;next++)
	{
		printf("%d ",primes[next]);
		if((next+1)%16 == 0) printf("\n");
	}
	printf("\n");
	return 0;
}


