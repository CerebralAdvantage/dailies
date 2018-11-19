let tsq = {}
tsq.en = []; // isn't an array so a stack?!!
tsq.de = [];

tsq.enqueue = function(val) {
	tsq.en.push(val); // Always do this no matter what!  tsq.en was born to push like a queue!
}
tsq.dequeue = function() {
	if(tsq.de.length == 0) { // if the dequeue stack is empty...
		while(tsq.en.length > 0) { // transfer the full contents (in reverse!) of the enqueue stack
			tsq.de.push(tsq.en.pop()); // to fill the dequeue stack.
		} // ps. if the enqueue stack was empty and the dequeue stack is empty, popping "undefined" is OK
	}
	return tsq.de.pop(); // just pop every time.  Unless this is empty.  Then see above^
}

tsq.enqueue(131);
tsq.enqueue(261);
tsq.enqueue(391);
tsq.enqueue(521);
console.log(tsq.dequeue()); // should be 131
console.log(tsq.dequeue()); // should be 261
console.log(tsq.dequeue()); // should be 391 -- it's a QUEUE, remember?
tsq.enqueue(1);
tsq.enqueue(2);
tsq.enqueue(3);
tsq.enqueue(4);
console.log(tsq.dequeue()); // should be 521
console.log(tsq.dequeue()); // should be 1  <a lot happens here!>
console.log(tsq.dequeue()); // should be 2
console.log(tsq.dequeue()); // should be 3


/*
This algorithm is optimized to only transfer the 
FULL STACK contents only on the following condition:
1. dequeue() is being called
2. dequeue stack (de) is empty
3. enqueue stack (en) is not empty
Otherwise, it always pushes onto en and pops from de.
when there is nothing on either stack, it returns what
normally gets returned upon popping from an empty stack.. (undefined).
*/
