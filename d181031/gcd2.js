let gcd = function(a,b) { return (!b)?a:gcd(b,a%b); };

function mygcd(a,b) // sometimes, recursion is so passe
{
	let t;
	while(b)
	{
		t = b;
		b = a %b;
		a = t;
	}
	return a;
}

console.log(gcd(51,391));
console.log(gcd(391,51));

