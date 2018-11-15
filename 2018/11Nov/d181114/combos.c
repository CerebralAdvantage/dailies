#include <stdio.h>

void combine(int size, char elms[])
{
	int i, j, pot, count;
	char combo[20];
	if (size < 20)
	{
		pot = 1 << size;
		for(i=1;i<pot;i++)
		{
			count = 0;
			for(j=0;j<size;j++) // check each possible elm[] element...
				if((i>>j)&1)	// if the one bit is set in this loop counting index
					combo[count++] = elms[j]; // add elm[] to combination of chars
			combo[j] = '\0'; // make it a valid C string by appending the null char
			printf("%s ",combo); // print all the combos in one line...
		} // for
		printf("\n"); // ... followed by a newline character to end things neatly
	} // if not a buffer overflow...
} // combine()

int main()
{
	char list[] = {'a','b','c','d','e'};
	combine(5,list);
	return 0;
}
