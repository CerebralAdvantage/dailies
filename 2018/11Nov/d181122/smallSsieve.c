#include <stdio.h>

// this is a billion (2^30) for a reason.  Run it - see how long it takes!
//define HOWBIG 1073741824
#define HOWBIG 1048576/2
// ROOT is the square root of our target (HOWBIG)
//define ROOT 32768
#define ROOT 1024

unsigned char p[HOWBIG]; // point: Sundaram; sieve storage is 1/2

// Second attempt at the Sieve of Sundaram
int primes[8500000];
int main()
{
	int i,j;
	int base, inc;	
	// The idea is... interesting.  Shout out to S.P. Sundaram, an incredible thinker!
	// first, populate an array with 1's...
	for(i=1; i<	HOWBIG; i++) p[i] = 1;
	p[0]=0;
	i=0;
	do
	{
		i++;
		inc = 2*i+1;
		base = 2*i*i+i+i;
		//inc = (2*i*(i+1)+i+i+1)-base; // YES.  It's just that tricky
//printf("base = %d inc = %d \n",base,inc);
		for(j=base; j<HOWBIG; j+=inc) p[j] = 0; // but think of the savings!

	} while(base < HOWBIG);
	primes[0] = 2;
	for(i=1,j=0; j < HOWBIG; j++) if(p[j] == 1) primes[i++] = j*2+1; 
	i--;
	for(j=0;j<i;j++)
	{
		printf("%d ",primes[j]);
		if((j+1)%16 == 0) printf("\n");
	}
	printf("\n");

	printf("Total number of primes ( < %d) is %d\n",HOWBIG,i);

	return 0;
}

// 2 1 3 5 7 11 13 17 19 23 29 31 35 37 41 43 
//                                **  why this?  why OTHER multiples of 5?
// 35-1=34/2=17.  17 should have been sifted out.  EARLY 4 7 10 13 16 12 17
