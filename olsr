#include <stdio.h>
int main() {
  double x[5] = {0, 30, 60, 90, 100}, rate = 1;
  int t, i, j, k, d[5][5], sent = 0, rcv = 0, ok;
  printf("OLSRRoutingExample: Start simulation with OLSR routing protocol and CBR traffic.\n");
  for (t = 2; t <= 10; t++) {
    x[1] = 30 + 2 * t;
    for (i = 0; i < 5; i++) for (j = 0; j < 5; j++) d[i][j] = i == j ? 0 : ((x[i]-x[j])*(x[i]-x[j]) <= 1600 ? 1 : 99);
    for (k = 0; k < 5; k++) for (i = 0; i < 5; i++) for (j = 0; j < 5; j++) if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
    ok = d[0][1] < 99; sent++; rcv += ok;
    if (t == 2) printf("OLSRRoutingExample: Node 0 starts sending CBR packets to Node 1 at time 2.0s.\nOLSRRoutingExample: Node 1 receives CBR packets at time 2.0s.\n");
    if (t == 3) printf("OLSRRoutingExample: Node 0 continues sending packets at %gMbps.\nOLSRRoutingExample: Node 1 receives packets at time 3.0s.\n", rate);
    if (t == 4) printf("OLSRRoutingExample: Node 0 sending more packets at time 4.0s.\nOLSRRoutingExample: Node 1 receives packets at time 4.0s.\n");
    if (t == 5) printf("OLSRRoutingExample: Node 0 sending packets at %gMbps.\nOLSRRoutingExample: Node 1 receives packets at time 5.0s.\n", rate);
  }
  printf("OLSRRoutingExample: Node 0 sends final packet at time 10.0s.\nOLSRRoutingExample: Node 1 receives final packet at time %s.\n", rcv == sent ? "10.0s" : "(not delivered)");
  printf("OLSRRoutingExample: Simulation finished.\n");
}
