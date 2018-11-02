# after being inspired by this video: https://www.youtube.com/watch?v=3xeAdFBfGWc
# I wrote a square root of two (sot) routine based on the pattern I observed in
# the video:
"""
2 3
5 7 (2)
12 17 (5)
29 41  (12)    1682 = 1681 + 1

12+17 = 29
12+29 = 41

1^2 + 1^2 = 1^2 + 1
2^2 + 2^2 = 3^2 - 1
5^2 + 5^2 = 7^2 + 1
"""

def sot():
	a = 2
	b = 3
	for i in range(1000):
		down = a + b
		across = a + down
		a = down
		b = across
	print a
	print b
	print b/a  #sadly, this only ever prints "1"

sot()

