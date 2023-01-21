vector<int> g(n);
// Initialize Graph...

int hare{g[g[0]]}, tortoise{g[0]};
while (hare != tortoise) {
  hare = g[g[hare]];
  tortoise = g[tortoise];
}

hare = 0;
while (hare != tortoise) {
  hare = g[hare];
  tortoise = g[tortoise];
}

int start = tortoise;
int length = 1;
hare = g[hare];
while (hare != tortoise) {
  hare = g[hare];
  ++length;
}

return {start, length};
