// RotateArray
// October 31, 2018
// Author: Jim Huddle
//
// Rotate any array of any size, in either direction, in place

function rotateArray(arr, rot)
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

function head(arr)
{
	let out = "";
	for(let i = 0; i < arr.length; i++) out += arr[i] + " ";
	console.log(out);
}

let arr1 = [];
for(let i = 0; i < 12; i++) arr1[i] = i;
rotateArray(arr1, 5);
head(arr1);

