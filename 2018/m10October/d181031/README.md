# RotateArray

This little javascript program will rotate an array by an arbitrary amount.
Any positive rotation will work.  If, for odd example, you have an array of
size 13 and decide to rotate it by 10 million, this program will handle it.
If you have an array of size 10 million, and wish to rotate it by 5 million,
this routine will do so in exactly 10 million steps, using exactly 2 temporary
(scalar integer) variables to swap array items.  It does the rotation in place.
using no more swap steps than array items.  It is exceedingly efficient.
