// (install and) use nodejs to run the following callback routines
// > node as1.js

function doSomething(possibleCallback) {
console.log("============");
  if (typeof(possibleCallback) === 'function'){
    console.log('possibleCallback is a callback! So... we call it back!:');
    possibleCallback(); //we can invoke the callback!
  }
  else {
    console.log('possibleCallback: ', possibleCallback, ' is not a callback function.');
  }
console.log("------------\n");
}

function thisIsReal() {
  console.log("this is a REAL function!");
}

doSomething('stringy');

doSomething(thisIsReal); // NOTE: we're passing the function pointer (address of) thisIsReal

// thisIsReal() gets called immediately and runs.
// then it returns undefined to doSomething()
doSomething(thisIsReal()); // (bit of a logic error! - program works, just not as expected!)

doSomething(function myCallback(){ console.log('yes, I am a callback!') });
doSomething(myCallback = function (){ console.log('yes, I am a (weirder) callback!') });

doSomething(function() {
  console.log("AAAA-Nonimous!");
});
doSomething(() => {
  let a = "2";
  let b = 3;
  console.log("AAAArrow function!", a+b);
});

//doSomething(() {
//  console.log("AAAA-Nonimous?"); // Unexpected Token Error!
//});

