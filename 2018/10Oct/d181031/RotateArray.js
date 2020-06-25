// RotateArray
// October 31, 2018
// Author: Jim Huddle
//
// Rotate an array of any size by any positive amount, in place, in O(n) time.
// uses ONE additional integer variable for storage.
//
// Wed Jun 24 2020 rev JH
// used one-line gcd - sweet!
// switched to "one tmp variable" algorithm - much neater
// no negative rotates
// smarter comments; more DOING
// tested with node v8.10.0

const { performance } = require('perf_hooks');

function rotateArray(arr, rot) {
    let i,j, tmp, next, len = arr.length;
    let d,b,t,count = 0;
    if (rot > 0) {
        rot = rot % len; // if rot > len...
        d=len; b=rot;    // find the gcd of array len and rotation amount
        while(b) { t = b; b = d % b; d = t; } // d now is gcd (credit: Euclid)
        for(i=0;i<d;i++) {                    // i++...
            next = i;                         // starting place for next
            for(j=0; j<len/d; j++) {          // j just counts off len/d loops
                next = (next + rot) % len;    // 'next' does all the heavy lifting
                tmp = arr[next];              // begin 2-part swap
                arr[next] = arr[i];           // i is always the 'zeroeth' element
                arr[i] = tmp;                 // think of arr[i] as "the other tmp"
                count++;      // 10M array items? ANY rot takes 10M steps
            } // hopping loop (do len/d times)
        } // crawling loop (do d times)
    } // if (rot > 0)
    console.log("process took ", count, " steps.");
} // function rotateArray(arr, rot)

function head(arr)
{
	let out = "";
	for(let i = 0; i < 24; i++) out += arr[i] + " ";
	//for(let i = 0; i < arr.length; i++) out += arr[i] + " ";
	console.log(out);
}

let arr1 = [];
let j = 24; // 20000000;
let rot = 6; //  500000;

for(let i = 0; i < j; i++) arr1[i] = i; // init array to be 0..i-1
console.log("before:");
head(arr1);
//console.log(performance.now());
rotateArray(arr1, rot);  // rotate a 20,000,000 itme array by 500,000 takes just under 200ms
//console.log(performance.now()); // but loading/running the prog and filling the array 1.674s
console.log("after:");
head(arr1);
