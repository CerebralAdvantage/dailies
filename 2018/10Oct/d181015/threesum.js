const arraySize = 1000000;
//const arraySize = 300;
const minval = 0;
const maxval =    10000000;
//const maxval =    1000;
const mintarget =  5000000;
const maxtarget = 15000000;
//const mintarget =  300;
//const maxtarget = 400;
let arr = [];
let target = 0;

function init()
{
  let i=0;
  for(i=0;i<arraySize;i++) arr[i] = Math.trunc(Math.random()*(maxval-minval))+minval;
  target = Math.trunc(Math.random()*(maxtarget-mintarget))+mintarget;
} // init()

function checkguess(target, guess)
{
  if((arr[guess] > target) && (arr[guess-1] > target)) return  1; // way too high
  if((arr[guess] < target) && (arr[guess+1] < target)) return -1; // way too low
  return 0; // close enough to stop guessing
} // checkguess()

function find()
{
  let i=0, finalguess = 0;
  console.log("target =", target);

  // OK.  So what's the big deal...  3 steps.  First, sort the list O = n(log n)
  let start = Date.now();
  arr.sort(function(a,z){ return a-z; });
  let lapse = Date.now();
  console.log("Time to sort list: ", lapse-start, "milliseconds.");

  // Second, find the "sweet spot" (in this case, target/3)
  let sspot = Math.trunc(target/3); // calc sweet spot
  console.log("sweet spot =", sspot);

  // find it using what I call "Sorted Random List Search" somewhat close to "interpolation search"
  let rstep = Math.trunc((maxval-minval)/arraySize); // given a reasonably even distribution...
  let guess = Math.trunc((sspot-minval) / rstep); // pretty good first guess
  finalguess = guess;
  if (checkguess(sspot, guess) != 0)
  {
    let guess2 = guess + Math.trunc((sspot-arr[guess]) / rstep); // even better second guess
    finalguess = guess2;
    if (checkguess(sspot, guess2) != 0)
    {
      let guess3 = guess2 + Math.trunc((sspot-arr[guess2]) / rstep); // even better third guess
      finalguess = guess3;
      if (checkguess(sspot, guess3) != 0) // if we get this far, it's horrible...
      {
        while(arr[finalguess]>sspot) finalguess--; // why so stupid?
        while(arr[finalguess]<sspot) finalguess++; // because I'm LAZY, that's why! :-)
      } // guess3
    } // guess2
  } // guess

  // while technically correct, we can quickly do better
  let guessx = finalguess;
  if (arr[guessx] != sspot)
  {
    if(Math.abs(sspot-arr[finalguess-1])<Math.abs(sspot-arr[guessx])) guessx = finalguess-1;
    if(Math.abs(sspot-arr[finalguess+1])<Math.abs(sspot-arr[guessx])) guessx = finalguess+1;
  }

  console.log("BEST guess =", guessx, arr[guessx],"\n\n");
  for(i=guessx-5;i<guessx+5;i++) console.log(i, arr[i]);

  // Step 3 is to do a "simple extension search" from that center, until you hit it square, And if
  // you have a lot of values, you will probably quickly find 3 values that add up to your target


  let donetime = Date.now();
  console.log("Time to find sum values:", donetime-lapse, "milliseconds.");
  console.log("total time = ", donetime-start, "milliseconds.");


  //just for laughs, let's see how close we are!
  console.log(target, "target");
  console.log(arr[guessx-1] + arr[guessx] + arr[guessx+1], "virgin guess");

} // find()

init();
find();


/*
  // find it using what I call "Sorted Random List Search" somewhat close to "interpolation search"
  let rstep = Math.trunc((maxval-minval)/arraySize); // given a reasonably even distribution...
  let guess = Math.trunc((sspot-minval) / rstep); // pretty good first guess
//   console.log("first guess =", guess);
//   for(i=guess-2;i<guess+2;i++) console.log(i, arr[i]);
  finalguess = guess;
  if (checkguess(sspot, guess) != 0)
  {
    let guess2 = guess + Math.trunc((sspot-arr[guess]) / rstep); // even better second guess
//     console.log("second guess =", guess2);
//     for(i=guess2-2;i<guess2+2;i++) console.log(i, arr[i]);
    finalguess = guess2;
    if (checkguess(sspot, guess2) != 0)
    {
      let guess3 = guess2 + Math.trunc((sspot-arr[guess2]) / rstep); // even better third guess
//       console.log("third guess =", guess3);
//       for(i=guess3-2;i<guess3+2;i++) console.log(i, arr[i]);
      finalguess = guess3;
      if (checkguess(sspot, guess3) != 0) // if we get this far, it's horrible...
      {
        while(arr[finalguess]>sspot) finalguess--; // why so stupid?
        while(arr[finalguess]<sspot) finalguess++; // because I'm LAZY, that's why! :-)
      } // guess3
    } // guess2
  } // guess

//   console.log("final guess was =", finalguess);
//   for(i=finalguess-1;i<finalguess+2;i++) console.log(i, arr[i]);
  // while technically correct, we can quickly do better...
  let guessx = finalguess;
  if (arr[guessx] != sspot)
  {
    if(Math.abs(sspot-arr[finalguess-1])<Math.abs(sspot-arr[guessx])) guessx = finalguess-1;
    if(Math.abs(sspot-arr[finalguess+1])<Math.abs(sspot-arr[guessx])) guessx = finalguess+1;
  }
  console.log("BEST guess =", guessx, arr[guessx],"\n\n");
  for(i=guessx-8;i<guessx+9;i++) console.log(i, arr[i]);

*/
