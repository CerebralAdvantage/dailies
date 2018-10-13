// buzz of Eratosthenes   neither / nor % is used!
let i=0, arr=[];
for(i=1;i<=100;i+=1) arr[i] =  i;         // initially, arr[1] = 1, arr[2] = 2...
for(i=5;i<=100;i+=5) arr[i] =  "";        // prepopulate all multiples of 5 with ""
for(i=3;i<=100;i+=3) arr[i] =  "fizz";    // populate all multiples of 3 with "fizz"
for(i=5;i<=100;i+=5) arr[i] += "buzz";    // append "buzz" to all multiples of 5
for(i=1;i<=100;i+=1) console.log(arr[i]); // log everything out
// the 'buzz' loop adds "buzz" to all multiples of 5.  These are originally all
// set to "", so the effect SHOULD BE to turn them into "buzz".  But the multiples
// of 3 have been changed to "fizz", so appending "buzz" turns them into "fizzbuzz".
