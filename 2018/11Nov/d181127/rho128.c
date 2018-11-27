#include <stdio.h>
#include <stdlib.h>
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

__int128_t gcd(__int128_t a, __int128_t b) 
{
    __int128_t remainder;
    while (b != 0) {
        remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}
// Retrofit of C code from https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm
// Frankly, I expected a little snappier response time - this one eats a whole processor for 20 seconds.
int main (int argc, char *argv[])
{
    //int count, total = 0, number = 10403, loop = 1;
    //int count, total = 0, number = 4999999, loop = 1;
    //int count, total = 0, number = 1040302997, loop = 1;
    int total = 0, loop = 1;
    __int128_t number = 10409283492874902998, x_fixed = 2, count, size = 2, x = 2, factor = 1;
	int done = 0;
	printf("%s: ", s128(number));
	while (done == 0)
	{
		x_fixed = 2; size = 2; x = 2; factor = 1;
		while (factor == 1) {
			for (count = 1; (count <= size) && (factor <= 1); count++) {
				x = (x * x + 1) % number;
				factor = gcd(abs(x - x_fixed), number);
			}
			size = 2 * size;
			x_fixed = x;
			loop = loop + 1;
		}
		if(factor == number)
		{
			printf("%s ", s128(factor));
			done = 1;
		}
		else
		{
			while(number % factor == 0)
			{
				number /= factor;
				printf("%s ", s128(factor));
			}
		}
	}
	printf("\n");
	return EXIT_SUCCESS;
}

