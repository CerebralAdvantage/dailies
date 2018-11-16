// RotateArray
// October 31, 2018
// Author: Jim Huddle
//
// Rotate any array of any size, in either direction, in place
// OK.  maybe not in either direction, but in O (n) time.  Every time.
// And only using 2 storage variables!

let gcd = function(a,b) { return (!b)?a:gcd(b,a%b); }; // https://stackoverflow.com/questions/17445231/js-how-to-find-the-greatest-common-divisor

function rotateArray(arr, rot)
{
	let i,j, tmp, tmp2, hop, hop2, len = arr.length;
	let neg = false;
	//let count = 0;
	if (rot != 0)
	{
		if (rot < 0) neg = true;
		rot = Math.abs(rot);	// if rot < 0...
		rot = rot % len;	// if rot > len...
		let d = gcd(len,rot);	// keep your eye on d!  (It's the greatest common d!)
		// if the rotation is prime to the array length, d is 1
		if (!neg)	// (maybe we'll do negative values later
		{
			for(i=0;i<d;i++)	// plodding loop - crawls 1-at-a-time (if at all!)
			{			// *************
				hop = i;		// hop starts at zero... or, you know... 1, 2, 3...
				tmp = arr[hop];		// this is the "latent" half of the swap, below
				for(j=0;j<len/d; j++)	// hopping loop - hops rot-at-a-time, wrapping if needed
				{			// ************
					hop2 = (hop+rot)%len;	// hop2 hops forward by rot (and wraps, if needed)
					tmp2 = tmp;		// save the old tmp for next iteration
					tmp = arr[hop2];	// save forward array value
					arr[hop2] = tmp2;	// overwrite (swap) it with prev fwd value
					hop = hop2;		// now hop moves forward by rot (to meet hop2)
					//count++;		// 10M array items? ANY rot takes 10M steps!
				} // hopping loop (do only len/d times)
			} // plodding loop (do only d times)
		} // if (!neg)
	} // if (rot != 0)
//console.log("process took ", count, " steps.");
} // function rotateArray(arr, rot)

function head(arr)
{
	let out = "";
	for(let i = 0; i < 20; i++) out += arr[i] + " ";
	//for(let i = 0; i < arr.length; i++) out += arr[i] + " ";
	console.log(out);
}

//let rot = 51;	// 17 * 3
//let j = 391;	// 17 * 23
//let rot = 4999999;	// biggest prime less than 5,000,000 (this means nothing - but it is a big rotation!)
//let j = 10000000;	// ten million - with a prime rotation like 4999999, the inner (j) loop goes 10M!
let j = 20;		// twenty is "prime to 9"
let rot = 9;	// even though neither 20 nor 9 are prime!  Their gcd is 1.

let arr1 = [];
for(let i = 0; i < j; i++) arr1[i] = i;
rotateArray(arr1, rot);
head(arr1);





/*
function oldRotateArray(arr, rot)
{
	let i, tmp, hop = 0, len = arr.length;
	let neg = false;
	if (rot != 0)
	{
		if (rot < 0) neg = true;
		rot = Math.abs(rot);
		rot = rot % len;
		for(i=len-1;i>=rot;i--)
		{
			tmp = arr[i];
			arr[i] = arr[i-rot];
			arr[i-rot] = tmp;
		}
	}
}

	console.log("array size - 1 = ", j-1);
	console.log(j, " % ",rot," = ", j%rot);
	console.log("array [", j%rot, "-1] = ", arr1[(j%rot)-1]);
*/
