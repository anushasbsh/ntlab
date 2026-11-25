#include <stdio.h>
int main() {
  int rate[2] = {1, 2}, tok[2] = {0}, rr[2] = {0}, tb[2] = {0}, t, u, b, cur = 0, i, line = 1;
  double ex[2] = {0, 100}, rad = 60, x = 55;
  for (t = 0; t < 8; t++) {
    rr[t % 2]++;
    for (u = 0; u < 2; u++) tok[u] += rate[u];
    b = tok[1] > tok[0];
    if (tok[b] >= 4) { tok[b] -= 4; tb[b]++; }
    x += 10;
    for (i = 0; i < 2; i++)
      if (i != cur && (x - ex[i]) * (x - ex[i]) <= rad * rad && (x - ex[cur]) * (x - ex[cur]) > rad * rad) {
        printf("0.000000 0.000000 0.000000 INFO Handover Event: Node %d is moving to Node %d\n", line++, cur, i);
        cur = i;
      }
  }
  return 0;
}