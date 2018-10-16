function ranger(angle, speed)
{
  let upspeed = Math.sin((3.1415926536/180) * angle) * speed;
  let fwspeed = Math.cos((3.1415926536/180) * angle) * speed;
  let time = (upspeed / 32.174) * 2; // time includes uptime
                                     // and the identical downtime (* 2)
  let distance = time * fwspeed;
  return distance;
}


console.log("at 100 ft/sec... ");
console.log("at 30 degrees, it travelled ", ranger(30,100));
console.log("at 35 degrees, it travelled ", ranger(35,100));
console.log("at 40 degrees, it travelled ", ranger(40,100));
console.log("at 45 degrees, it travelled ", ranger(45,100));
console.log("at 50 degrees, it travelled ", ranger(50,100));
console.log("at 60 degrees, it travelled ", ranger(60,100));
console.log("at 85 degrees, it travelled ", ranger(85,100));
