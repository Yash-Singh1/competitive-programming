let f = 0;
let s = 0;

for (let i = 2; i < 1000000; i += 2) {
  f += i * i + (i-1) * (i-1);
  s += 4 * (i-1);
  if (f === ((((i+2)*(i+3)))-(i+2))*4) {
    console.log(i);
  }
}
