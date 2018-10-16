function ranger(angle, speed)
{
  let upspeed = Math.sin((3.1415926536/180) * angle) * speed;
  let fwspeed = Math.cos((3.1415926536/180) * angle) * speed;
  let time = (upspeed / 32.174) * 2; // time includes uptime
                                     // and the identical downtime (* 2)
  let distance = time * fwspeed;
  return [distance, time];
}

let x = [];
console.log("at 100 ft/sec... ");
x = ranger(5,100); console.log("At 5 degrees, it went", x[0], "feet in", x[1], "seconds");
x = ranger(30,100); console.log("At 30 degrees, it went", x[0], "feet in", x[1], "seconds");
x = ranger(35,100); console.log("At 35 degrees, it went", x[0], "feet in", x[1], "seconds");
x = ranger(40,100); console.log("At 40 degrees, it went", x[0], "feet in", x[1], "seconds");
x = ranger(45,100); console.log("At 45 degrees, it went", x[0], "feet in", x[1], "seconds");
x = ranger(50,100); console.log("At 50 degrees, it went", x[0], "feet in", x[1], "seconds");
x = ranger(60,100); console.log("At 60 degrees, it went", x[0], "feet in", x[1], "seconds");
x = ranger(85,100); console.log("At 85 degrees, it went", x[0], "feet in", x[1], "seconds");
x = ranger(89.9,100); console.log("At 89.9 degrees, it went", x[0], "feet in", x[1], "seconds");
x = ranger(89.999,100); console.log("At 89.999 degrees, it went", x[0], "feet in", x[1], "seconds");
x = ranger(90,100); console.log("At 90 degrees, it went", x[0], "feet in", x[1], "seconds");
console.log("Time enough to run, screaming, away...");
