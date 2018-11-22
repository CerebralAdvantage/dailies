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

or, as we say in the real world...


'''
user0@ii:~/Desktop/git/dailies/2018/11Nov/d181120$ time ./gam 50000000000000 > primes-from-50-trillion

real	0m0.235s
user	0m0.230s
sys	0m0.005s
user0@ii:~/Desktop/git/dailies/2018/11Nov/d181120$ wc primes-from-50-trillion 
  7998  31995 487854 primes-from-50-trillion
user0@ii:~/Desktop/git/dailies/2018/11Nov/d181120$ head primes-from-50-trillion 
Your prize is $2669!!!
sieve requires: 481166 primes
50000000000053 50000000000099 50000000000113 50000000000117 
50000000000143 50000000000161 50000000000177 50000000000221 
50000000000261 50000000000263 50000000000267 50000000000309 
50000000000351 50000000000381 50000000000393 50000000000399 
50000000000413 50000000000473 50000000000521 50000000000539 
50000000000593 50000000000623 50000000000683 50000000000723 
50000000000749 50000000000813 50000000000887 50000000000893 
50000000000903 50000000000941 50000000000959 50000000000963 
user0@ii:~/Desktop/git/dailies/2018/11Nov/d181120$ 

'''
