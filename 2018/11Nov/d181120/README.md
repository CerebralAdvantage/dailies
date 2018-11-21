# Modified Sieve in C

### Gimme a Million!

This is a modified *Sieve of Eratosthenes* in C.

If you enter a 63-bit number, it will return all the primes bewteen the number you entered (x) and x+1,000,000.  Not exactly a million primes, but a goodly quantity at a fair distance from zero.  You enter the number, you get the primes in a space separated list.

You can redirect the output to a file, to keep those numbers for later:

'''
$> GaM > lots-of-primes-starting-at-50-billion
50000000000
$> wc lots-of-primes-starting-at-50-billion
lots lots lots*11
'''

