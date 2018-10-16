const arraySize = 10000;
const minval = 0;
const maxval =    1000000;
const mintarget =  500000;
const maxtarget = 1500000;
let arr = [];

function init()
{
  let i=0;
  for(i=0;i<arraySize;i++) arr[i] = Math.trunc(Math.random()*(maxval-minval))+minval;
  let target = Math.trunc(Math.random()*(maxtarget-mintarget))+mintarget;
  //for(i=0;i<arraySize;i++) console.log(arr[i]);
  //console.log("HEY!");
}

init();
