#include <stdio.h>

// My second attempt at the Sieve of Sundaram
// The idea is... interesting.  Shout out to S.P. Sundaram, an incredible thinker!

// this is a billion (2^30) for a reason.  Run it - see how long it takes!
// total surprise: 2^30 takes about 8 seconds longer than Eratosthenes
//define HOWBIG 1073741824/2
#define HOWBIG 1048576/2

unsigned char p[HOWBIG]; // point: Sundaram; sieve storage is 1/2
int primes[85000000]; // totally unnecessarily large!
int main()
{
	int i,j;
	int base, inc;	
	// first, populate an array with 1's...
	for(i=1; i< HOWBIG; i++) p[i] = 1;
	i=0;
	do
	{
		i++;
		inc = 2*i+1;
		base = 2*i*i+i+i;
		// A lot of people put that math in the following loop:
		for(j=base; j<HOWBIG; j+=inc) p[j] = 0;
		// but "+= inc" is really the only math required.  It's a sieve.

	} while(base < HOWBIG); // A lot of people use a "for...HOWBIG" loop.
	// Whereas that will work (j-loop just tests out); it's unnecessary.

	primes[0] = 2;
	for(i=1,j=1; j < HOWBIG; j++) if(p[j] == 1) primes[i++] = j*2+1; 
	i--;
/*
	for(j=0;j<i;j++)
	{
		printf("%d ",primes[j]);
		if((j+1)%16 == 0) printf("\n");
	}
	printf("\n");
*/
	printf("Total number of primes ( < %d) is %d\n",HOWBIG*2,i);

	return 0;
}
// Final thoughts on Sundaram's Sieve.  Sundaram never relies on "prime numbers."
// Eratosthenes' Sieve *makes* prime numbers, so there's never a shortage, but the sieve,
// itself, relies on prime numbers to start (and CONTINUE!) the sifting. Sundaram doesn't.
// What equation had Sundaram discovered that so closely related to primes?  Also, Esieve
// cancels a lot of cancelled spots.  Inuititively, so should Ssieve.  Does it?  If not,
// What makes it run 8 seconds slower on a billion slots?  So many things suggest that it
// should be running faster.  It *does* run faster with smaller quantities.  Why?




