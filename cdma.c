#include <stdio.h>
int main() {
  int c[5][8] = {{1,1,1,1,1,1,1,1},{1,-1,1,-1,1,-1,1,-1},{1,1,-1,-1,1,1,-1,-1},{1,-1,-1,1,1,-1,-1,1},{1,1,1,1,-1,-1,-1,-1}};
  int sent = 0, rcv = 0, i, j, k, s[8], d, b;
  for (k = 0; k < 10; k++) {
    for (j = 0; j < 8; j++) s[j] = 0;
    for (i = 0; i < 5; i++) for (j = 0; j < 8; j++) s[j] += ((k + i) % 2 ? -1 : 1) * c[i][j];
    for (i = 0; i < 5; i++) {
      for (d = 0, j = 0; j < 8; j++) d += s[j] * c[i][j];
      b = (k + i) % 2 ? -1 : 1; sent++; if (d / 8 == b) rcv++;
    }
  }
  printf("<FlowMonitor>\n <Flow>\n  <SourceAddress>10.1.1.0</SourceAddress>\n  <DestinationAddress>10.1.1.1</DestinationAddress>\n");
  printf("  <PacketsSent>%d</PacketsSent>\n  <PacketsReceived>%d</PacketsReceived>\n  <PacketLoss>%d</PacketLoss>\n", sent, rcv, sent - rcv);
  printf("  <Throughput>%d kbps</Throughput>\n </Flow>\n ...\n</FlowMonitor>\n", 1000 * rcv / sent);
}