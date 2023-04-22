let a = 1;
let b = 1;
let c = 1;

for (let i = 1; i < 11; ++i) {
  a = b + c;
  b = a + c;
  c = a + b;
}

console.log(a+b+c)
