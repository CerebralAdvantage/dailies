#include <stdio.h>
#include <string.h>
#include <malloc.h>

// the methodology is to break the 128-bit  value into 3 smaller (approx equal) values,
// shaving off 10,000,000,000,000 decimal (BIGTEN) into each of 3 64-bit values.  I
// *could have* done a 2-way split into to 64-bit uints, but I prefer working with
// (and then printing from) decimal values.  (when I want to see decimal, printed!)
// The s128 is basically a copy/paste/edit of p128, using sprintf to do the hard work.
// The only tricks left to explain is the %013 parts  This keeps a number like 
// 23400000000000500000000000072 from being printed as 2345072... the tricky part is
// to also keep a number like 37 from being printed as 0000000000037

void p128(__uint128_t val)
{
	#define BIGTEN 10000000000000
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
	#define BIGTEN 10000000000000
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

int main()
{
	__uint128_t biggy; // no #include's or -l's required! vanilla gcc
	char *nml;
	biggy = -1; // this saves some typing; setting a uint to -1 gives you max int
	p128(biggy); // the easiest way (p128)

	printf("\n%s\n",s128(biggy)); // the easy way (s128)

	nml = s128(biggy);	// the
	printf("%s\n",nml);	// no memory leak
	free(nml);			// way

	return 0;
}

/*

user0@ii:~/Desktop$ gcc -o zb biggytest.c 
user0@ii:~/Desktop$ ./zb
340282366920938463463374607431768211455
340282366920938463463374607431768211455
user0@ii:~/Desktop$ bcc 65536^8 -1
340282366920938463463374607431768211455

note bcc is:
bcc () { echo "$@" | bc ; }

*/
