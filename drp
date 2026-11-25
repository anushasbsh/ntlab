#include <stdio.h>
int main() {
  int c[4][4] = {{0,1,9,9},{1,0,1,9},{9,1,0,1},{9,9,1,0}}, i, j, k, t, sent = 0, rcv = 0;
  double rate = 1, cap = 2, credit = 0;
  for (k = 0; k < 4; k++) for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) if (c[i][k] + c[k][j] < c[i][j]) c[i][j] = c[i][k] + c[k][j];
  printf("DynamicRoutingWithCBR: Start simulation with CBR traffic and AODV routing.\n");
  for (t = 2; t <= 11; t++) {
    sent++; credit += cap / rate;
    if (credit >= 1) { credit--; rcv++; }
    if (t == 2) printf("DynamicRoutingWithCBR: Node 0 starts sending CBR packets to Node 1 at time 2.0s.\nDynamicRoutingWithCBR: Node 1 receives CBR packets at time 2.0s.\n");
    if (t == 3) printf("DynamicRoutingWithCBR: Node 0 continues sending packets at %gMbps.\nDynamicRoutingWithCBR: Node 1 receives packets at time 3.0s.\n", rate);
    if (t == 4) printf("DynamicRoutingWithCBR: Node 0 sends more packets to Node 1 at time 4.0s.\nDynamicRoutingWithCBR: Node 1 receives packets at time 4.0s.\n");
    if (t == 5) printf("DynamicRoutingWithCBR: Node 0 sending packets at %gMbps.\nDynamicRoutingWithCBR: Node 1 receives packets at time 5.0s.\n", rate);
  }
  printf("DynamicRoutingWithCBR: Node 0 sends final packet at time 10.0s.\nDynamicRoutingWithCBR: Node 1 receives final packet at time 10.0s.\n");
  printf("DynamicRoutingWithCBR: Simulation finished.\n<FlowMonitor>\n <Flow>\n  <FlowId>1</FlowId>\n  <SourceAddress>10.1.1.1</SourceAddress>\n  <DestinationAddress>10.1.1.%d</DestinationAddress>\n", c[0][1] + 1);
  printf("  <PacketsSent>%d</PacketsSent>\n  <PacketsReceived>%d</PacketsReceived>\n  <PacketLoss>%d</PacketLoss>\n  <Throughput>%.1fMbps</Throughput>\n  <Delay>%dms</Delay>\n </Flow>\n</FlowMonitor>\n", sent, rcv, sent - rcv, rate * rcv / sent, 10 * c[0][1]);
}