# Sieve of Sundaram II

This is my second attempt at the sieve.  It's more me than what others have posted.  There's a whole lot of multiplications that were used to recalculate the sifted position (j-loop) that really didn't need to be there.  It's like dong the Sieve of Eratosthenes in the following fashion:
```
prime = 5;
for (i = 2; i<max/prime; i++) (j = i*prime; p[j] = 0; }
```
You don't **really** need to say j=i*prime each time through the loop; just say j+=prime.

So here it is.  My Sieve of Sundaram.

Oh.  And I totally figured out why it runs slower than Eratoshenes' Sieve for large runs:
With each new iteration, the incremental step (inc) that the sieve takes increses as an odd number.
So 3,5,7,9,11 etc.  Eratosthenes is each successive prime.  So 2 3 5 7 (waitaminute.. OH YEAH!) then
11, 13, 17, 19, 23, 29, 31, 37... larger and larger increments.  This makes for a sieve that accelerates,
verson one that is intuitively faster out of the gate, but does NOT accelerate.  And hence is passed.

So for runs of 100 or 1000, Sundaram is (probably - I haven't timed it) hella faster than Eratosthenes.
But in the areas that interest me (2^30)... JUST noticeably slower (like 20% slower)
So, fast and steady sort of LOSES the race!
