// fizz of Eratosthenes
let arr = [];
let i = 0;
for(i=1;i<=100;i++) arr[i] = 1;    // initialize array to 'all' ones
for(i=3;i<=100;i+=3) arr[i] *= 3;  // multiples of 3 get multiplied by three
for(i=5;i<=100;i+=5) arr[i] *= 5;  // multiples of 5 get multiplied by five
// That last step has the 'side effect' of multiplying some multiples of 3 by 5.
// Seeing as all multiples of three are 3, they become 15 with that step.
// you could swap the order of step *3 and step *5 without changing a thing.
for(i=1;i<=100;i++)                            // this just logs everything out
{
  if (arr[i] == 1) {console.log(i); continue;} // notice we log 'i' not 'arr[i]'
  if (arr[i] == 3) console.log("fizz");        // only non-five multiples of 3
  if (arr[i] == 5) console.log("buzz");        // only non-three multiples of 5
  if (arr[i] == 15) console.log("fizzbuzz");   // multiples of 3 and 5
}
// In the spirit of Eratosthenes, no / or % was used!!
