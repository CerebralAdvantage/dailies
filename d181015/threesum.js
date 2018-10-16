const arraySize = 10000;
const minval = 0;
const maxval =    10000000;
const mintarget =  5000000;
const maxtarget = 15000000;
let arr = [];

function init()
{
  let i=0;
  for(i=0;i<arraySize;i++) arr[i] = Math.trunc(Math.random()*(maxval-minval))+minval;
  let target = Math.trunc(Math.random()*(maxtarget-mintarget))+mintarget;
  // OK.  So what's the big deal...  3 steps.  First, sort the list O = n(log n)
  let start = Date.now();
  arr.sort(function(a,z){ return a-z; });
  // Second, find the "sweet spot" (in this case, target/3)
  let sspot = Math.trunc(target/3); // calc sweet spot

  // find it using what I call "Sorted Random List Search" very close to "interpolation search"
  let rstep = Math.trunc((maxval-minval)/arraySize); // given a reasonably even distribution...
  let guess = Math.trunc(sspot / rstep); // pretty good first guess
  let guess2 = guess + Math.trunc((sspot-arr[guess]) / rstep); // even better second guess
  let guess3 = guess2 + Math.trunc((sspot-arr[guess2]) / rstep); // even better third guess
  let finalguess = guess3;
  // So, I basically take 3 guesses to narrow it down pretty well.  Then I just feel around
  // I think binary search would be 13-14 steps... this will be 7-9 steps.
  while(arr[finalguess]>sspot) finalguess--; // why so stupid?
  while(arr[finalguess]<sspot) finalguess++; // because I'm LAZY, that's why! :-)
  // while technically correct, we can quickly do better
  let guessx = finalguess;
  if(Math.abs(sspot-arr[finalguess-1])<Math.abs(sspot-arr[finalguess])) guessx = finalguess-1;
  if(Math.abs(arr[finalguess+1]-sspot)<Math.abs(sspot-arr[guessx])) guessx = finalguess+1;

  // Step 3 is to do a "simple extension search" from that center, until you hit it square, And if
  // you have a lot of values, you will probably quickly find 3 values that add up to your target

  let donetime = Date.now();

  console.log("total time = ", donetime-start, "milliseconds.");
  console.log("target =", target);
  console.log("sweet spot =", sspot);
  console.log("first guess =", guess);
  for(i=guess-2;i<guess+2;i++) console.log(i, arr[i]);
  console.log("second guess =", guess2);
  for(i=guess2-2;i<guess2+2;i++) console.log(i, arr[i]);
  console.log("third guess =", guess3);
  for(i=guess3-3;i<guess3+3;i++) console.log(i, arr[i]);
  console.log("final guess =", finalguess);
  for(i=finalguess-1;i<finalguess+2;i++) console.log(i, arr[i]);
  console.log("BEST guess =", guessx, arr[guessx]);
}

init();
