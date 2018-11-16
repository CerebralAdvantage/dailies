# RotateArray

This little javascript program will rotate an array by an arbitrary amount.

Any rotation value will work; negative rotations are mishandled on purpose.

If, for odd example, you have an array of size 13 and decide to rotate it by 10 million, this program will handle it.

If you have an array of size 10 million, and wish to rotate it by 4,999,999, this routine will do so in exactly 10 million steps, using exactly 2 temporary (scalar integer) variables to swap array items.  It does the rotation in place, using no more swap steps than array items, and no more additional memory space than the two swap integers.

It is *exceedingly* efficient.

