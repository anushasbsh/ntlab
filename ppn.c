#include <stdio.h>
int main() {
  double bw = 5e6, delay = 0.002, size = 1024 * 8, t = 2, tx = size / bw;
  int q = 100, i, sent = 0, rcv = 0, wait = 0;
  for (i = 0; i < 9; i++, t += 1) {
    sent++;
    wait = tx + delay > 1 ? wait + 1 : 0;
    printf("PointToPointExample:  client: Sent packet to 10.1.1.2 at time %.1fs\n", t);
    if (wait < q) { rcv++; printf("PointToPointExample:  server: Received packet from 10.1.1.1 at time %.1fs\n", t + tx + delay); }
  }
  if (rcv == sent) printf("PointToPointExample:  client: Simulation finished, all packets sent and received.\n");
  else printf("PointToPointExample:  client: Simulation finished, %d packets lost.\n", sent - rcv);
  printf("Simulation finished.\n");
}