#include <stdio.h>
#define BUCKET_SIZE 10

int main() {
    int n, p[100], rate, bucket = 0, i, sent, drop;
    printf("Enter the number of packets: ");
    scanf("%d", &n);
    printf("Enter the packet sizes: ");
    for(i = 0; i < n; i++) scanf("%d", &p[i]);
    printf("Enter the output rate: ");
    scanf("%d", &rate);

    printf("\nTime\tPacket\tStatus\t\tSent\tRemaining\n");
    for(i = 0; i < n; i++) {
        drop = (bucket + p[i] > BUCKET_SIZE);
        if(!drop) bucket += p[i];
        sent = bucket < rate ? bucket : rate;
        printf("%d\t%d\t%s\t%d\t%d\n", i+1, p[i],
               drop ? "Discarded" : "Accepted", sent, bucket-sent);
        bucket -= sent;
    }
    return 0;
}
