function MSD(num)
{
	num = Math.abs(num);			// "preprocesses" all negative numbers
	if (num != 0)				// handles zero
	{
		while (num < 1) num *= 10;	// "fixes" all small decimals, like 0.000000031415
		while (num >= 10) num /= 10;	// "downsizes" all numbers larger than 9.999999...
	}
	return Math.trunc(num);			// "cleans up" the reality to the right of the decimal
} // MSD()


console.log(MSD(12345));		// 1
console.log(MSD(67.89));		// 6
console.log(MSD(0.00987));		// 9
console.log(MSD(100));			// 1? changed ">10" to ">=10"
console.log(MSD(-81.1029));		// 8
console.log(MSD(-54321));		// 5
console.log(MSD(0));			// 0
console.log(MSD(-0));			// 0 changed "if (num < 0)..." to Math.abs...
console.log(MSD(-39));			// 3
console.log(MSD(-0.000712));	// 7


