#include <stdio.h>
int main() {
  int flow[3] = {0}, i, j, sent = 0, ok = 0;
  printf("*** Creating network\n*** Adding hosts:\nh1 h2\n*** Adding switches:\ns1\n*** Adding links:\n(h1, s1) (h2, s1)\n");
  printf("*** Configuring hosts\n*** Starting network\nTesting network connectivity\n");
  for (i = 1; i <= 2; i++) for (j = 1; j <= 2; j++) if (i != j) {
    flow[j] = 1; sent++; ok += flow[j];
    if (i == 1) printf("*** Ping: h%d -> h%d\nh%d -> 10.0.0.%d : %d%% packet loss\n", i, j, i, j, 100 - 100 * ok / sent);
  }
  printf("*** Network testing complete\n\nmininet> dump\nh1 h1-eth0:s1\nh2 h2-eth0:s1\ns1 lo:s1-eth0 h1-eth0 h2-eth0\n");
  printf("mininet> xterm h1\n(mininet opens a new xterm window for h1)\nmininet> pingall\n");
  printf("*** Ping: h1 -> h2\nh1 -> 10.0.0.2 : %d%% packet loss\nmininet> exit\n*** Stopping network\n*** Shutting down network\nmininet>\n", 100 - 100 * ok / sent);
}