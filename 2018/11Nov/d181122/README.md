# Sieve of Sundaram II

This is my second attempt at the sieve.  It's more me than what others have posted.  There's a whole lot of multiplications that were used to recalculate the sifted position (j-loop) that really didn't need to be there.  It's like dong the Sieve of Eratosthenes in the following fashion:
```
prime = 5;
for (i = 2; i<max/prime; i++) (j = i*prime; p[j] = 0; }
```
You don't **really** need to say j=i*prime each time through the loop; just say j+=prime.

So here it is.  My Sieve of Sundaram.
