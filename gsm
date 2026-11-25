#include <stdio.h>
int main() {
  double bx[3] = {0, 1500, 2500}, by[3] = {0, 1500, 2500}, r[3] = {800, 1000, 1200};
  double mx[3] = {500, 1500, 2500}, my[3] = {500, 1500, 2500};
  int net[3] = {1, 1, 2}, cur = 0, i, k, f;
  for (k = 0; k < 3; k++) {
    f = -1;
    for (i = 0; i < 3 && f < 0; i++)
      if ((mx[k]-bx[i])*(mx[k]-bx[i]) + (my[k]-by[i])*(my[k]-by[i]) <= r[i]*r[i]) f = i;
    if (f >= 0 && f != cur) {
      printf("Handover Event: Node %d is moving to Node %d\n", cur, f);
      printf("(%s-handover)\n", net[cur] == net[f] ? "Intra" : "Inter");
      cur = f;
    }
  }
  printf("ns3::Simulator::Run () - Start of simulation\n");
  printf("ns3::Simulator::Destroy () - End of simulation\n");
  return 0;
}